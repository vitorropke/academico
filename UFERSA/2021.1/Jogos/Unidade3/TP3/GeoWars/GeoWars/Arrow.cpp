/**********************************************************************************
// Arrow (Código Fonte)
// 
// Criação:     10 Out 2012
// Atualização: 01 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Objeto faz perseguição direta
//
**********************************************************************************/

#include "Arrow.h"

#include "Explosion.h"
#include "GeoWars.h"

// ---------------------------------------------------------------------------------

Arrow::Arrow(float pX, float pY, Player* p) : player(p)
{
	sprite = new Sprite("Resources/Enemies/Arrow.png");
	speed  = new Vector(0, 2.0f);
	BBox(new Circle(18.0f));

	speed->RotateTo(0);
	speed->ScaleTo(2.0f);

	MoveTo(pX, pY);
	type = ARROW;

	GeoWars::audio->Play(SPAWN);

	// incrementa contador
	++Hud::arrows;
}

// ---------------------------------------------------------------------------------

Arrow::~Arrow()
{
	delete sprite;
	delete speed;

	// decrementa contador
	--Hud::arrows;
}

// -------------------------------------------------------------------------------

void Arrow::OnCollision(Object* obj)
{
	if (obj->Type() == MISSILE)
	{
		GeoWars::scene->Delete(obj, STATIC);
		GeoWars::scene->Delete(this, MOVING);
		GeoWars::scene->Add(new Explosion(x, y), STATIC);
		GeoWars::audio->Play(EXPLODE);

		// incrementa contador
		++Hud::killedArrows;
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

void Arrow::Update()
{
	// ajusta ângulo do vetor 
	speed->RotateTo(Line::Angle(Point(x, y), Point(player->X(), player->Y())));

	// limita a magnitude da velocidade para impedir
	// seu crescimento indefinido na soma vetorial
	if (speed->Magnitude() > 4.5f)
	{
		speed->ScaleTo(4.5f);
	}

	// movimenta objeto pelo seu vetor velocidade
	Translate(speed->XComponent() * 60.0f * gameTime, -speed->YComponent() * 60.0f * gameTime);

	if (GeoWars::player->killed)
	{
		GeoWars::scene->Delete(this, MOVING);
		GeoWars::scene->Add(new Explosion(x, y), STATIC);
		GeoWars::audio->Play(EXPLODE);
	}
}

// -------------------------------------------------------------------------------
