/**********************************************************************************
// Spawner (Arquivo de Cabeçalho)
//
// Criação:     01 Jan 2013
// Atualização: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Lugares onde o fantasma e os power-ups podem surgir aleatoriamente
//
**********************************************************************************/

#ifndef _MAZE_SPAWNER_H_
#define _MAZE_SPAWNER_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Object.h"		// interface de Object
#include "Types.h"		// tipos específicos da engine

// ---------------------------------------------------------------------------------

class Spawner : public Object
{
public:
	bool occupied = false;	// spawner ocupado ou não

	Spawner();				// construtor
	~Spawner();				// destrutor

	void Update() {};		// atualização
	void Draw() {};			// desenho
};

// ---------------------------------------------------------------------------------

#endif
