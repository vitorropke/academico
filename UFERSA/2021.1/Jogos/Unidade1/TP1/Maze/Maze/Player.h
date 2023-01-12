/**********************************************************************************
// Player (Arquivo de Cabeçalho)
// 
// Criação:     01 Jan 2013
// Atualização: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Player do jogo Maze
//
**********************************************************************************/

#ifndef _MAZE_PLAYER_H_
#define _MAZE_PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Object.h"		// interface de Object
#include "Sprite.h"		// interface de Sprites
#include "Types.h"		// tipos específicos da engine

// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
	Sprite* spriteDefault = nullptr;	// sprite do jogador normal
	Sprite* spritePursued = nullptr;	// sprite do jogador sendo perseguido
	Sprite* spriteArrested = nullptr;	// sprite do jogador pego
	Sprite* spriteDead = nullptr;		// sprite do jogador morto
	Sprite* spriteInvisible = nullptr;	// sprite do jogador invisível

	float velX = 0;						// velocidade horizontal do jogador
	float velY = 0;						// velocidade vertical do jogador

	bool pursued = false;				// jogador está sendo perseguido ou não

	bool invisible = false;				// jogador está invisível ou não
	bool accelerated = false;			// jogador está acelerado ou não

public:
	uint lives = 3;						// vidas do jogador

	bool arrested = false;				// jogador foi pego ou não

	Player();							// construtor
	~Player();							// destrutor

	inline int Radius()					// retorna o raio do jogador
	{
		return spriteDefault->Width();
	}

	inline bool Invisible()				// retorna se o jogador está invisíbel ou não
	{
		return invisible;
	}
	
	void OnCollision(Object* obj);		// resolução da colisão
	void WallCollision(Object* obj);	// revolve colisão com muro
	
	void Update();						// atualização do objeto
	void Draw();						// desenho do objeto
};

// ---------------------------------------------------------------------------------

#endif
