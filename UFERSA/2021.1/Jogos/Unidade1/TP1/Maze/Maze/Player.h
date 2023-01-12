/**********************************************************************************
// Player (Arquivo de Cabe�alho)
// 
// Cria��o:     01 Jan 2013
// Atualiza��o: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Player do jogo Maze
//
**********************************************************************************/

#ifndef _MAZE_PLAYER_H_
#define _MAZE_PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Object.h"		// interface de Object
#include "Sprite.h"		// interface de Sprites
#include "Types.h"		// tipos espec�ficos da engine

// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
	Sprite* spriteDefault = nullptr;	// sprite do jogador normal
	Sprite* spritePursued = nullptr;	// sprite do jogador sendo perseguido
	Sprite* spriteArrested = nullptr;	// sprite do jogador pego
	Sprite* spriteDead = nullptr;		// sprite do jogador morto
	Sprite* spriteInvisible = nullptr;	// sprite do jogador invis�vel

	float velX = 0;						// velocidade horizontal do jogador
	float velY = 0;						// velocidade vertical do jogador

	bool pursued = false;				// jogador est� sendo perseguido ou n�o

	bool invisible = false;				// jogador est� invis�vel ou n�o
	bool accelerated = false;			// jogador est� acelerado ou n�o

public:
	uint lives = 3;						// vidas do jogador

	bool arrested = false;				// jogador foi pego ou n�o

	Player();							// construtor
	~Player();							// destrutor

	inline int Radius()					// retorna o raio do jogador
	{
		return spriteDefault->Width();
	}

	inline bool Invisible()				// retorna se o jogador est� invis�bel ou n�o
	{
		return invisible;
	}
	
	void OnCollision(Object* obj);		// resolu��o da colis�o
	void WallCollision(Object* obj);	// revolve colis�o com muro
	
	void Update();						// atualiza��o do objeto
	void Draw();						// desenho do objeto
};

// ---------------------------------------------------------------------------------

#endif
