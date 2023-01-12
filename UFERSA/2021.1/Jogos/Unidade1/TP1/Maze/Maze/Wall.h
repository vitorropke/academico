/**********************************************************************************
// Wall (Arquivo de Cabeçalho)
//
// Criação:     01 Jan 2013
// Atualização: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Paredes por onde não é possível atravessar
//
**********************************************************************************/

#ifndef _MAZE_WALL_H_
#define _MAZE_WALL_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Object.h"		// interface de Object
#include "Types.h"		// tipos específicos da engine

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

	void Update() {};								// atualização
	void Draw() {};									// desenho
};

// ---------------------------------------------------------------------------------

#endif
