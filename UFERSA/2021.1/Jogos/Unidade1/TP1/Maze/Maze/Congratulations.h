/**********************************************************************************
// Congratulations (Arquivo de Cabe�alho)
//
// Cria��o:     18 Jan 2013
// Atualiza��o: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Tela de encerramento bem-sucedido do jogo Maze
//
**********************************************************************************/

#ifndef _MAZE_CONGRATULATIONS_H_
#define _MAZE_CONGRATULATIONS_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Sprite.h"

// ------------------------------------------------------------------------------

class Congratulations : public Game
{
private:
	Sprite* backg = nullptr;	// pano de fundo

public:
	void Init();				// inicializa��o
	void Update();				// atualiza��o
	void Draw();				// desenho
	void Finalize();			// finaliza��o
};

// -----------------------------------------------------------------------------

#endif