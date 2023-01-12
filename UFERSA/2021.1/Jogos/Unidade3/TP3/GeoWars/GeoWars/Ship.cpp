/**********************************************************************************
// Ship (C�digo Fonte)
// 
// Cria��o:     10 Out 2012
// Atualiza��o: 01 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Objeto faz uma persegui��o suavizada
//
**********************************************************************************/

#include "Ship.h"

#include "Explosion.h"
#include "GeoWars.h"

// ---------------------------------------------------------------------------------

Ship::Ship(float pX, float pY, Player* p) : player(p)
{
	sprite = new Sprite("Resources/Enemies/Ship.png");
	speed  = new Vector(0, 2.0f);
	BBox(new Circle(20.0f));

	speed->RotateTo(0.0f);
	speed->ScaleTo(0.0f);
	
	MoveTo(pX, pY);
	
	factor = -0.25f;
	type = SHIP;

	// configura��o do emissor de part�culas
	Generator emitter;
	emitter.imgFile = "Resources/Spark.png";    // arquivo de imagem
	emitter.angle = speed->Angle() + 180;       // �ngulo base do emissor
	emitter.spread = 10;                        // espalhamento em graus
	emitter.lifetime = 0.2f;                    // tempo de vida em segundos
	emitter.frequency = 0.010f;                 // tempo entre gera��o de novas part�culas
	emitter.percentToDim = 0.7f;                // desaparece ap�s 60% da vida
	emitter.minSpeed = 50.0f;                   // velocidade m�nima das part�culas
	emitter.maxSpeed = 100.0f;                  // velocidade m�xima das part�culas
	emitter.color.r = 1.0f;                     // componente Red da part�cula 
	emitter.color.g = 0.5;                      // componente Green da part�cula 
	emitter.color.b = 0.0f;                     // componente Blue da part�cula 
	emitter.color.a = 1.0f;                     // transpar�ncia da part�cula

	// cria sistema de part�culas
	tail = new Particles(emitter);

	// incrementa contador
	++Hud::ships;
}

// ---------------------------------------------------------------------------------

Ship::~Ship()
{
	delete sprite;
	delete speed;
	delete tail;

	// decrementa contador
	--Hud::ships;
}

// -------------------------------------------------------------------------------

void Ship::OnCollision(Object* obj)
{
	if (obj->Type() == MISSILE)
	{
		GeoWars::scene->Delete(obj, STATIC);
		GeoWars::scene->Delete(this, MOVING);
		GeoWars::scene->Add(new Explosion(x, y), STATIC);
		GeoWars::audio->Play(EXPLODE);

		// incrementa contador
		++Hud::killedShips;
	}

	if ((obj->Type() == ARROW) || (obj->Type() == BOOMERANG) || (obj->Type() == SHIP) || (obj->Type() == SHURIKEN) ||
		(obj->Type() == SPIKES) || (obj->Type() == VIRUS))
	{
		// vetor de 'repel�ncia'
		// impede que os inimigos se sobreponham
		Vector target = Vector(Line::Angle(Point(x, y), Point(obj->X(), obj->Y())), 20.0f * gameTime);

		target.Rotate(180.0f);
		target.ScaleTo(100.0f * gameTime);

		speed->Add(target);
	}
}

// -------------------------------------------------------------------------------

void Ship::Update()
{
	// a magnitude do vetor 'target' controla qu�o 
	// r�pido o objeto converge para a dire��o do alvo
	/*
	float angle = Line::Angle(Point(x, y), Point(player->X(), player->Y()));
	float magnitude = 2.0f * gameTime;
	Vector target = Vector(angle, magnitude);
	*/
	Vector target{ Line::Angle(Point(x, y), Point(player->X(), player->Y())), 2.0f * gameTime };

	// ajusta velocidade atual na dire��o do alvo
	speed->Add(target);
	
	// limita a magnitude da velocidade para impedir 
	// que ela cres�a indefinidamente pela soma vetorial
	if (speed->Magnitude() > 4.5f)
	{
		speed->ScaleTo(4.5f);
	}

	// move o objeto pelo seu vetor velocidade
	Translate(speed->XComponent() * 50.0f * gameTime, -speed->YComponent() * 50.0f * gameTime);

	// aplica fator de escala
	Scale(1.0f + factor * gameTime);

	// amplia e reduz objeto
	if (scale < 0.85f)
	{
		factor = 0.25f;
	}
	if (scale > 1.00f)
	{
		factor = -0.25f;
	}

	// mant�m o objeto dentro do mundo do jogo
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

	// atualiza calda da nave
	tail->Config().angle = speed->Angle();
	tail->Generate(x - 15 * cos(speed->Radians()), y + 15 * sin(speed->Radians()));
	tail->Update(gameTime);

	if (GeoWars::player->killed)
	{
		GeoWars::scene->Delete(this, MOVING);
		GeoWars::scene->Add(new Explosion(x, y), STATIC);
		GeoWars::audio->Play(EXPLODE);
	}
}

// -------------------------------------------------------------------------------
