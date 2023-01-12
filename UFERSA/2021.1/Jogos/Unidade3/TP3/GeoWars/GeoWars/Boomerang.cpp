/**********************************************************************************
// Boomerang (Código Fonte)
//
// Criação:     05 Ago 2019
// Atualização: 01 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Objeto faz movimentos como se fosse um bumerangue
//
**********************************************************************************/

#include "Boomerang.h"

#include "Explosion.h"
#include "GeoWars.h"

// ---------------------------------------------------------------------------------

Boomerang::Boomerang(float pX, float pY) : angle(-8, 8), magnitude(1, 8)
{
	sprite = new Sprite("Resources/Enemies/Boomerang.png");
	speed = new Vector(0, 2.0f);
	BBox(new Circle(20.0f));

	// ajusta ângulo do vetor em uma direção aleatória
	speed->RotateTo(90);
	speed->ScaleTo(400);

	MoveTo(pX, pY);
	type = BOOMERANG;

	// incrementa contador
	++Hud::boomerangs;

	const uint scriptNum = 4;
	// monta o script
	Instruction commands[scriptNum] =
	{
		{ ROTATE, -5.0f, 60.0f, 3.0f },
		{ ROTATE, -5.0f, 60.0f, 6.0f },
		{ RANDOM, 0.0f, 0.0f, 3.0f },
		{ JUMP, 0.0f, 0.0f, 0.0f }
	};

	// faz cópia do script
	script = new Instruction[scriptNum];
	for (uint i = 0; i < scriptNum; i++)
	{
		script[i] = commands[i];
	}

	// inicia execução do script
	index = 0;
	end = scriptNum - 1;
	duration = script[index].duration;
	timer.Start();
}

// ---------------------------------------------------------------------------------

Boomerang::~Boomerang()
{
	delete sprite;
	delete speed;
	delete[] script;

	// decrementa contador
	--Hud::boomerangs;
}

// -------------------------------------------------------------------------------

void Boomerang::OnCollision(Object* obj)
{
	if (obj->Type() == MISSILE)
	{
		GeoWars::scene->Delete(obj, STATIC);
		GeoWars::scene->Delete(this, MOVING);
		GeoWars::scene->Add(new Explosion(x, y), STATIC);
		GeoWars::audio->Play(EXPLODE);

		// incrementa contador
		++Hud::killedBoomerangs;
	}

	if ((obj->Type() == ARROW) || (obj->Type() == BOOMERANG) || (obj->Type() == SHIP) || (obj->Type() == SHURIKEN) ||
		(obj->Type() == SPIKES) || (obj->Type() == VIRUS))
	{
		// vetor de 'repelência'
		// impede que os inimigos se sobreponham
		Vector target = Vector(Line::Angle(Point(x, y), Point(obj->X(), obj->Y())), 20.0f * gameTime);

		target.Rotate(180.0f);
		target.ScaleTo(100.0f * gameTime);

		speed->Add(target);
	}
}

// -------------------------------------------------------------------------------

void Boomerang::Update()
{
	// deslocamento padrão
	float delta = 10.0f * gameTime;

	// ----------------------------
	// Próxima instrução do script
	// ----------------------------

	if (script[index].instruction == MOVETO || script[index].instruction == SLIDETO)
	{
		// pega posição X e Y de destino
		float targetX = script[index].angle;
		float targetY = script[index].magnitude;

		// se chegou bem próximo do destino
		if (abs(x - targetX) < 2 && abs(y - targetY) < 2)
		{
			// move exatamente para a posição de destino
			MoveTo(targetX, targetY);

			// passa para a próxima instrução
			index = (index == end ? index : ++index);
			duration = script[index].duration;
			timer.Start();
		}
	}
	else
	{
		// se esgotou o tempo da instrução
		if (timer.Elapsed(duration))
		{
			// passa para a próxima instrução
			index = (index == end ? index : ++index);
			duration = script[index].duration;
			timer.Start();
		}
	}

	// ------------------------
	// Interpretador do script
	// ------------------------

	// realiza salto antes de qualquer outra instrução
	if (script[index].instruction == JUMP)
	{
		index = int(script[index].angle);
		duration = script[index].duration;
		timer.Start();
	}

	switch (script[index].instruction)
	{
	case MOVE:		// MOVE | Ângulo | Magnitude | Duração
		speed->RotateTo(script[index].angle);
		speed->ScaleTo(script[index].magnitude);
		break;

	case MOVETO:	// MOVETO | PosX | PosY | Magnitude
		speed->RotateTo(Line::Angle(Point(x, y), Point(script[index].angle, script[index].magnitude)));
		speed->ScaleTo(script[index].duration);
		break;

	case SLIDE:		// SLIDE | Ângulo | Magnitude | Duração
		speed->RotateTo(script[index].angle);
		speed->ScaleTo(script[index].magnitude);
		break;

	case SLIDETO:	// SLIDETO | PosX | PosY | Magnitude
		speed->RotateTo(Line::Angle(Point(x, y), Point(script[index].angle, script[index].magnitude)));
		speed->ScaleTo(script[index].duration);
		break;

	case TURN:		// TURN | Ângulo | Magnitude | Duração
	{
		Vector target{ script[index].angle, script[index].magnitude * delta };
		speed->Add(target);
		break;
	}
	case ROTATE:	// ROTATE | Ângulo | Magnitude | Duração
		speed->Rotate(-script[index].angle * delta);
		speed->ScaleTo(script[index].magnitude);
		break;

	case RANDOM:	// RANDOM | Ângulo | Magnitude | Duração
		speed->Rotate(-angle.Rand());
		speed->ScaleTo(magnitude.Rand());
		break;
	}

	Rotate(400.0f * gameTime);

	// limita a magnitude da velocidade para impedir
	// seu crescimento indefinido na soma vetorial
	if (speed->Magnitude() > 10.0f)
	{
		speed->ScaleTo(10.0f);
	}

	// movimenta objeto pelo seu vetor velocidade
	Translate(speed->XComponent() * delta, -speed->YComponent() * delta);

	// mantém o objeto dentro do mundo do jogo
	if (x < 50)
	{
		MoveTo(50, y);
		// ajusta ângulo do vetor em uma direção aleatória
		speed->RotateTo(Line::Angle(Point(x, y), Point(randXDirection.Rand(), randYDirection.Rand())));
	}
	if (y < 50)
	{
		MoveTo(x, 50);
		// ajusta ângulo do vetor em uma direção aleatória
		speed->RotateTo(Line::Angle(Point(x, y), Point(randXDirection.Rand(), randYDirection.Rand())));
	}
	if (x > game->Width() - 50)
	{
		MoveTo(game->Width() - 50, y);
		// ajusta ângulo do vetor em uma direção aleatória
		speed->RotateTo(Line::Angle(Point(x, y), Point(randXDirection.Rand(), randYDirection.Rand())));
	}
	if (y > game->Height() - 50)
	{
		MoveTo(x, game->Height() - 50);
		// ajusta ângulo do vetor em uma direção aleatória
		speed->RotateTo(Line::Angle(Point(x, y), Point(randXDirection.Rand(), randYDirection.Rand())));
	}

	if (GeoWars::player->killed)
	{
		GeoWars::scene->Delete(this, MOVING);
		GeoWars::scene->Add(new Explosion(x, y), STATIC);
		GeoWars::audio->Play(EXPLODE);
	}
}

// ---------------------------------------------------------------------------------
