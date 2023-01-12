/**********************************************************************************
// Spikes (Código Fonte)
// 
// Criação:     15 Out 2012
// Atualização: 01 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Objeto faz uma fuga suavizada
//
**********************************************************************************/

#include "Spikes.h"

#include "Explosion.h"
#include "GeoWars.h"

// ---------------------------------------------------------------------------------

Spikes::Spikes(float pX, float pY, Player* p) : player(p)
{
	sprite = new Sprite("Resources/Enemies/Spikes.png");
	speed = new Vector(0, 2.0f);
	BBox(new Circle(20.0f));

	speed->RotateTo(0.0f);
	speed->ScaleTo(0.0f);
	MoveTo(pX, pY);

	type = SPIKES;

	// mantém certa distância do jogador
	RandI dist{ 100, 400 };
	distance = dist.Rand();

	// incrementa contador
	++Hud::spikes;
}

// ---------------------------------------------------------------------------------

Spikes::~Spikes()
{
	delete sprite;
	delete speed;

	// decrementa contador
	--Hud::spikes;
}

// -------------------------------------------------------------------------------

void Spikes::OnCollision(Object* obj)
{
	if (obj->Type() == MISSILE)
	{
		GeoWars::scene->Delete(obj, STATIC);
		GeoWars::scene->Delete(this, MOVING);
		GeoWars::scene->Add(new Explosion(x, y), STATIC);
		GeoWars::audio->Play(EXPLODE);

		// incrementa contador
		++Hud::killedSpikes;
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

void Spikes::Update()
{
	// a magnitude do vetor target controla quão 
	// rápido o objeto converge para a direção do alvo
	/*
	float angle = Line::Angle(Point(x, y), Point(player->X(), player->Y()));
	float magnitude = 20.0f * gameTime;
	Vector target = Vector(angle, magnitude);
	*/
	Vector target = Vector(Line::Angle(Point(x, y), Point(player->X(), player->Y())), 20.0f * gameTime);
	
	// fugir se o player chegar muito perto
	if (Point::Distance(Point(x, y), Point(player->X(), player->Y())) < distance)
	{
		target.Rotate(180.0f);
		target.ScaleTo(100.0f * gameTime);
	}

	// ajusta velocidade atual na direção do alvo
	speed->Add(target);
	
	// limita a magnitude da velocidade para impedir
	// seu crescimento indefinido na soma vetorial
	if (speed->Magnitude() > 8)
	{
		speed->ScaleTo(8.0f);
	}

	// move o objeto pelo seu vetor velocidade
	Translate(speed->XComponent() * 50.0f * gameTime, -speed->YComponent() * 50.0f * gameTime);
	Rotate(50 * gameTime);

	// mantém o objeto dentro do mundo do jogo
	if (x < 50)
	{
		MoveTo(50, y);
	}
	if (y < 50)
	{
		MoveTo(x, 50);
	}
	if (x > game->Width() - 50)
	{
		MoveTo(game->Width() - 50, y);
	}
	if (y > game->Height() - 50)
	{
		MoveTo(x, game->Height() - 50);
	}

	if (GeoWars::player->killed)
	{
		GeoWars::scene->Delete(this, MOVING);
		GeoWars::scene->Add(new Explosion(x, y), STATIC);
		GeoWars::audio->Play(EXPLODE);
	}
}

// -------------------------------------------------------------------------------
