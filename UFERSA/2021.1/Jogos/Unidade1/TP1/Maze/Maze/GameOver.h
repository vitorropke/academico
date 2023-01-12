/**********************************************************************************
// Home (Arquivo de Cabeçalho)
//
// Criação:     18 Jan 2013
// Atualização: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Tela de fim do jogo Maze
//
**********************************************************************************/

#ifndef _MAZE_GAMEOVER_H_
#define _MAZE_GAMEOVER_H_

// ------------------------------------------------------------------------------
// Inclusões

#include "Game.h"
#include "Sprite.h"

// ------------------------------------------------------------------------------

class GameOver : public Game
{
private:
	Sprite* backg = nullptr;	// pano de fundo

public:
	void Init();				// inicialização
	void Update();				// atualização
	void Draw();				// desenho
	void Finalize();			// finalização
};

// -----------------------------------------------------------------------------

#endif
