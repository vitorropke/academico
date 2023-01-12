/**********************************************************************************
// Home (Arquivo de Cabe�alho)
//
// Cria��o:     18 Jan 2013
// Atualiza��o: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Tela de instru��es do jogo
//
**********************************************************************************/

#ifndef _LAND_THE_BOOSTER_INSTRUCTIONS_H_
#define _LAND_THE_BOOSTER_INSTRUCTIONS_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Animation.h"
#include "Game.h"
#include "TileSet.h"

// ------------------------------------------------------------------------------

class Instructions : public Game
{
private:
	TileSet* backg = nullptr;			// pano de fundo animado mas aqui � est�tico

	Animation* backgAnim = nullptr;		// anima��o do pano de animado mas aqui � est�tico

	Sprite* instructions = nullptr;		// tela com instru��es

public:
	void Init();						// inicializa��o
	void Update();						// atualiza��o
	void Draw();						// desenho
	void Finalize();					// finaliza��o
};

// -----------------------------------------------------------------------------

#endif
