/**********************************************************************************
// Shuriken (Código Fonte)
// 
// Criação:     05 Ago 2019
// Atualização: 01 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Objeto faz movimento retilíneo
//
**********************************************************************************/

#include "Shuriken.h"

#include "Explosion.h"
#include "GeoWars.h"

// ---------------------------------------------------------------------------------

Shuriken::Shuriken(float pX, float pY, Player* p) : player(p)
{
	sprite = new Sprite("Resources/Enemies/Shuriken.png");
	speed  = new Vector(0, 2.0f);
	BBox(new Circle(20.0f));

	// ajusta ângulo do vetor na direção do jogador
	speed->RotateTo(Line::Angle(Point(x, y), Point(player->X(), player->Y())));
	
	MoveTo(pX, pY);
	multiplier = 70.0f;
	type = SHURIKEN;

	GeoWars::audio->Play(SPAWN);

	// incrementa contador
	++Hud::shurikens;
}

// ---------------------------------------------------------------------------------

Shuriken::~Shuriken()
{
	delete sprite;
	delete speed;

	// decrementa contador
	--Hud::shurikens;
}

// -------------------------------------------------------------------------------

void Shuriken::OnCollision(Object* obj)
{
	if (obj->Type() == MISSILE)
	{
		GeoWars::scene->Delete(obj, STATIC);
		GeoWars::scene->Delete(this, MOVING);
		GeoWars::scene->Add(new Explosion(x, y), STATIC);
		GeoWars::audio->Play(EXPLODE);

		// incrementa contador
		++Hud::killedShurikens;
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

void Shuriken::Update()
{
	// movimenta objeto pelo seu vetor velocidade
	Translate(speed->XComponent() * multiplier * gameTime, -speed->YComponent() * multiplier * gameTime);

	// ajusta ângulo do vetor na direção do jogador
	if (x < 50 || y < 50 || x > game->Width() - 50 || y > game->Height() - 50)
	{
		multiplier = 200.0f;
		speed->RotateTo(Line::Angle(Point(x, y), Point(player->X(), player->Y())));
		rotationVelocity = 400.0f;
	}

	// limita a magnitude da velocidade para impedir
	// seu crescimento indefinido na soma vetorial
	if (speed->Magnitude() > 4.5f)
	{
		speed->ScaleTo(4.5f);
	}

	Rotate(rotationVelocity * gameTime);

	if (GeoWars::player->killed)
	{
		GeoWars::scene->Delete(this, MOVING);
		GeoWars::scene->Add(new Explosion(x, y), STATIC);
		GeoWars::audio->Play(EXPLODE);
	}
}

// ---------------------------------------------------------------------------------
