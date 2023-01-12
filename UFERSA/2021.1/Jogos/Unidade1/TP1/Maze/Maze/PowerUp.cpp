/**********************************************************************************
// PowerUp (Código Fonte)
//
// Criação:		01 Jan 2013
// Atualização:	25 Ago 2021
// Compilador:	Visual C++ 2019
//
// Descrição:	Poderes para o jogador
//
**********************************************************************************/

#include "PowerUp.h"

#include "Maze.h"

// ---------------------------------------------------------------------------------

PowerUp::PowerUp(uint cpu, Spawner* s)
{
	spriteAcceleration = new Sprite("Resources/PowerUps/Acceleration.png");
	spriteInvisibility = new Sprite("Resources/PowerUps/Invisibility.png");

	currentPowerUp = cpu;
	spawner = s;

	MoveTo(s->X(), s->Y());

	BBox(new Rect(
		-spriteInvisibility->Width() / 2.0f,
		-spriteInvisibility->Height() / 2.0f,
		spriteInvisibility->Width() / 2.0f,
		spriteInvisibility->Height() / 2.0f
	)
	);

	type = POWER_UP;
}

// ---------------------------------------------------------------------------------

PowerUp::~PowerUp()
{
	delete spriteAcceleration;
	delete spriteInvisibility;
}

// ---------------------------------------------------------------------------------

void PowerUp::Draw()
{
	// aceleração
	if (currentPowerUp == ACCELERATION) {
		spriteAcceleration->Draw(x, y, Layer::UPPER);
	}
	// invisibilidade
	else if (currentPowerUp == INVISIBILITY)
	{
		spriteInvisibility->Draw(x, y, Layer::UPPER);
	}
}

// ---------------------------------------------------------------------------------
