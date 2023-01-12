/**********************************************************************************
// Wall (Arquivo de Cabe�alho)
//
// Cria��o:     01 Jan 2013
// Atualiza��o: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Paredes por onde n�o � poss�vel atravessar
//
**********************************************************************************/

#ifndef _MAZE_WALL_H_
#define _MAZE_WALL_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Object.h"		// interface de Object
#include "Types.h"		// tipos espec�ficos da engine

// ---------------------------------------------------------------------------------

class Wall : public Object
{
private:
	float left = 0;		// coordenada esquerda do muro
	float top = 0;		// coordenada do topo do muro
	float right = 0;	// coordenada direita do muro
	float bottom = 0;	// coordenada de baixo do muro

public:
	Wall(float x1, float y1, float x2, float y2);	// construtor
	~Wall();										// destrutor

	// retorna a coordenada esquerda do muro
	inline float Left()
	{
		return left;
	}
	// retorna a coordenada do topo do muro
	inline float Top()
	{
		return top;
	}
	// retorna a coordenada direita do muro
	inline float Right()
	{
		return right;
	}
	// retorna a coordenada de baixo do muro
	inline float Bottom()
	{
		return bottom;
	}

	void Update() {};								// atualiza��o
	void Draw() {};									// desenho
};

// ---------------------------------------------------------------------------------

#endif
