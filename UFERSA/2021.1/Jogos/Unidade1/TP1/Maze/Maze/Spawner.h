/**********************************************************************************
// Spawner (Arquivo de Cabe�alho)
//
// Cria��o:     01 Jan 2013
// Atualiza��o: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Lugares onde o fantasma e os power-ups podem surgir aleatoriamente
//
**********************************************************************************/

#ifndef _MAZE_SPAWNER_H_
#define _MAZE_SPAWNER_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Object.h"		// interface de Object
#include "Types.h"		// tipos espec�ficos da engine

// ---------------------------------------------------------------------------------

class Spawner : public Object
{
public:
	bool occupied = false;	// spawner ocupado ou n�o

	Spawner();				// construtor
	~Spawner();				// destrutor

	void Update() {};		// atualiza��o
	void Draw() {};			// desenho
};

// ---------------------------------------------------------------------------------

#endif
