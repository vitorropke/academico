/**********************************************************************************
// PowerUp (Arquivo de Cabe�alho)
//
// Cria��o:     01 Jan 2013
// Atualiza��o: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Poderes para o jogador
//
**********************************************************************************/

#ifndef _MAZE_POWER_UP_H_
#define _MAZE_POWER_UP_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Spawner.h"	// local onde o power up deve aparecer

#include "Object.h"		// interface de Object
#include "Sprite.h"		// interface de Sprites
#include "Types.h"		// tipos espec�ficos da engine

// ---------------------------------------------------------------------------------
// Constantes Globais

// estados poss�veis para o fantasma
enum CURRENTPOWERUP { ACCELERATION, INVISIBILITY };

// ---------------------------------------------------------------------------------

class PowerUp : public Object
{
private:
	Sprite* spriteAcceleration = nullptr;	// sprite do power up de acelera��o
	Sprite* spriteInvisibility = nullptr;	// sprite do power up de invisibilidade

	uint currentPowerUp = ACCELERATION;		// power up atual

public:
	Spawner* spawner = nullptr;				// Spawner onde o power up apareceu

	PowerUp(uint cpu, Spawner* s);			// construtor
	~PowerUp();								// destrutor

	inline uint CurrentPowerUp()			// retorna o power up atual
	{
		return currentPowerUp;
	}

	void Update() {};						// atualiza��o
	void Draw();							// desenho
};

// ---------------------------------------------------------------------------------

#endif
