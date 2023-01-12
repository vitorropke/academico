/**********************************************************************************
// GhostVision (C�digo Fonte)
//
// Cria��o:     01 Jan 2013
// Atualiza��o: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Vis�o do fantasma
//
**********************************************************************************/

#include "GhostVision.h"

#include "Maze.h"

// ---------------------------------------------------------------------------------

GhostVision::GhostVision(Ghost* ghostInput)
{
	ghost = ghostInput;

	BBox(new Circle(ghost->Radius() * 3.0f));
	type = GHOST_VISION;
}

// ---------------------------------------------------------------------------------

GhostVision::~GhostVision()
{
}

// ---------------------------------------------------------------------------------

void GhostVision::OnCollision(Object* obj)
{
	// colis�o com o jogador
	if (obj->Type() == PLAYER)
	{
		Player* player = (Player*)obj;

		// Se o jogador n�o estiver invis�vel ent�o ele foi visto
		if (!player->Invisible())
		{
			ghost->sightedPlayer = true;
		}
	}
}

// ---------------------------------------------------------------------------------

void GhostVision::Update()
{
	MoveTo(ghost->X(), ghost->Y());
}

// ---------------------------------------------------------------------------------
