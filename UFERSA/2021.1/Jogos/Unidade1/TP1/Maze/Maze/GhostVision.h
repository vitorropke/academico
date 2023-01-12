/**********************************************************************************
// GhostVision (Arquivo de Cabeçalho)
//
// Criação:     01 Jan 2013
// Atualização: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Visão do fantasma
//
**********************************************************************************/

#ifndef _MAZE_GHOST_VISION_H_
#define _MAZE_GHOST_VISION_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Ghost.h"		// fantasma do Maze

#include "Object.h"		// interface de Object
#include "Types.h"		// tipos específicos da engine

// ---------------------------------------------------------------------------------

class GhostVision : public Object
{
private:
	Ghost* ghost = nullptr;			// fantasma que possui essa visão

public:
	GhostVision(Ghost* ghostInput);	// construtor
	~GhostVision();					// destrutor

	void OnCollision(Object* obj);	// resolução da colisão

	void Update();					// atualização
	void Draw() {};					// desenho
};

// ---------------------------------------------------------------------------------

#endif
