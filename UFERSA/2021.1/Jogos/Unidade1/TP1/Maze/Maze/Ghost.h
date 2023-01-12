/**********************************************************************************
// Ghost (Arquivo de Cabe�alho)
// 
// Cria��o:     01 Jan 2013
// Atualiza��o: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Fantasmas do Maze
//
**********************************************************************************/

#ifndef _MAZE_GHOST_H_
#define _MAZE_GHOST_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Player.h"		// jogador do Maze

#include "Object.h"		// interface de Object
#include "Sprite.h"		// interface de Sprites
#include "Types.h"		// tipos espec�ficos da engine

// ---------------------------------------------------------------------------------
// Constantes Globais

// estados poss�veis para o fantasma
enum GHOSTSTATE { LEFT, RIGHT, UP, DOWN };

// ---------------------------------------------------------------------------------

class Ghost : public Object
{
private:
	Sprite* spriteL = nullptr;			// sprite do fantasma indo para esquerda
	Sprite* spriteR = nullptr;			// sprite do fantasma indo para direita

	Player* player = nullptr;			// ponteiro para jogador

	uint currState = LEFT;				// estado atual do fantasma
	uint direction = 0;					// dire��o para onde o fantasma vai

public:
	float velX = 100;					// velocidade horizontal
	float velY = 100;					// velocidade vertical

	bool sightedPlayer = false;			// jogador foi visto ou n�o

	inline int Radius()					// retorna o tamanho do sprite
	{
		return spriteL->Width();
	}

	Ghost(Player* p);					// construtor
	~Ghost();							// destrutor

	void OnCollision(Object* obj);		// resolu��o da colis�o
	void WallCollision(Object* obj);	// revolve colis�o com muro

	void Update();						// atualiza��o do objeto
	void Draw();						// desenho do objeto
};

// ---------------------------------------------------------------------------------

#endif
