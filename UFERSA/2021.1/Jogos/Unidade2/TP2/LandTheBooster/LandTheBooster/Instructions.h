/**********************************************************************************
// Home (Arquivo de Cabeçalho)
//
// Criação:     18 Jan 2013
// Atualização: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Tela de instruções do jogo
//
**********************************************************************************/

#ifndef _LAND_THE_BOOSTER_INSTRUCTIONS_H_
#define _LAND_THE_BOOSTER_INSTRUCTIONS_H_

// ------------------------------------------------------------------------------
// Inclusões

#include "Animation.h"
#include "Game.h"
#include "TileSet.h"

// ------------------------------------------------------------------------------

class Instructions : public Game
{
private:
	TileSet* backg = nullptr;			// pano de fundo animado mas aqui é estático

	Animation* backgAnim = nullptr;		// animação do pano de animado mas aqui é estático

	Sprite* instructions = nullptr;		// tela com instruções

public:
	void Init();						// inicialização
	void Update();						// atualização
	void Draw();						// desenho
	void Finalize();					// finalização
};

// -----------------------------------------------------------------------------

#endif
