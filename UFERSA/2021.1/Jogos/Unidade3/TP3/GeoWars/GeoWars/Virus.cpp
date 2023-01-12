/**********************************************************************************
// Vírus (Código Fonte)
//
// Criação:     05 Ago 2019
// Atualização: 01 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Objeto faz movimento aleatório
//
**********************************************************************************/

#include "Virus.h"

#include "Explosion.h"
#include "GeoWars.h"

// ---------------------------------------------------------------------------------

Virus::Virus(float corX, float corY)
{
	sprite = new Sprite("Resources/Enemies/Virus.png");
	speed = new Vector(0, 2.0f);
	BBox(new Circle(20.0f));

	speed->RotateTo(0.0f);
	speed->ScaleTo(0.0f);

	MoveTo(corX, corY);

	type = VIRUS;

	time.Start();

	// incrementa contador
	++Hud::viruses;
}

// ---------------------------------------------------------------------------------

Virus::~Virus()
{
	time.Stop();
	delete sprite;
	delete speed;

	// decrementa contador
	--Hud::viruses;
}

// -------------------------------------------------------------------------------

void Virus::OnCollision(Object* obj)
{
	if (obj->Type() == MISSILE)
	{
		GeoWars::scene->Delete(obj, STATIC);
		GeoWars::scene->Delete(this, MOVING);
		GeoWars::scene->Add(new Explosion(x, y), STATIC);
		GeoWars::audio->Play(EXPLODE);

		// incrementa contador
		++Hud::killedViruses;
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

void Virus::Update()
{
	// Cria 3 novos vírus se passar 10 segundos
	if ((time.Elapsed() > milestone) && (Hud::viruses < 200))
	{
		GeoWars::scene->Add(new Virus(x, y), MOVING);
		GeoWars::scene->Add(new Virus(x, y), MOVING);
		GeoWars::scene->Add(new Virus(x, y), MOVING);

		milestone += 10;

		// ajusta ângulo do vetor em uma direção aleatória
		speed->RotateTo(Line::Angle(Point(x, y), Point(randXDirection.Rand(), randYDirection.Rand())));
	}

	// limita a magnitude da velocidade para impedir 
	// que ela cresça indefinidamente pela soma vetorial
	if (speed->Magnitude() > 4.5f)
	{
		speed->ScaleTo(4.5f);
	}

	// movimenta objeto pelo seu vetor velocidade
	Translate(speed->XComponent() * 50.0f * gameTime, -speed->YComponent() * 50.0f * gameTime);

	// rotaciona o vírus loucamente
	Rotate(200.0f * gameTime);

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
