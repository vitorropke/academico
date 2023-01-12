/**********************************************************************************
// GhostVision (Arquivo de Cabe�alho)
//
// Cria��o:     01 Jan 2013
// Atualiza��o: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Vis�o do fantasma
//
**********************************************************************************/

#ifndef _MAZE_GHOST_VISION_H_
#define _MAZE_GHOST_VISION_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Ghost.h"		// fantasma do Maze

#include "Object.h"		// interface de Object
#include "Types.h"		// tipos espec�ficos da engine

// ---------------------------------------------------------------------------------

class GhostVision : public Object
{
private:
	Ghost* ghost = nullptr;			// fantasma que possui essa vis�o

public:
	GhostVision(Ghost* ghostInput);	// construtor
	~GhostVision();					// destrutor

	void OnCollision(Object* obj);	// resolu��o da colis�o

	void Update();					// atualiza��o
	void Draw() {};					// desenho
};

// ---------------------------------------------------------------------------------

#endif
