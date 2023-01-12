/**********************************************************************************
// PowerUp (Arquivo de Cabeçalho)
//
// Criação:     01 Jan 2013
// Atualização: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Poderes para o jogador
//
**********************************************************************************/

#ifndef _MAZE_POWER_UP_H_
#define _MAZE_POWER_UP_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Spawner.h"	// local onde o power up deve aparecer

#include "Object.h"		// interface de Object
#include "Sprite.h"		// interface de Sprites
#include "Types.h"		// tipos específicos da engine

// ---------------------------------------------------------------------------------
// Constantes Globais

// estados possíveis para o fantasma
enum CURRENTPOWERUP { ACCELERATION, INVISIBILITY };

// ---------------------------------------------------------------------------------

class PowerUp : public Object
{
private:
	Sprite* spriteAcceleration = nullptr;	// sprite do power up de aceleração
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

	void Update() {};						// atualização
	void Draw();							// desenho
};

// ---------------------------------------------------------------------------------

#endif
