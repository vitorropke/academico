/**********************************************************************************
// GameOver (Arquivo de Cabeçalho)
// 
// Criação:     14 Fev 2013
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Fim do jogo
//              
**********************************************************************************/

#ifndef _LAND_THE_BOOSTER_GAME_OVER_H_
#define _LAND_THE_BOOSTER_GAME_OVER_H_

// ------------------------------------------------------------------------------

#include "Animation.h"
#include "Game.h"
#include "TileSet.h"

// ------------------------------------------------------------------------------

class GameOver : public Game
{
private:
	TileSet* backg = nullptr;			// pano de fundo animado
	TileSet* rocket = nullptr;			// folha de sprites do personagem
	
	Animation* backgAnim = nullptr;		// animação do pano de fundo
	Animation* rocketAnim = nullptr;	// animação do personagem

	Sprite* text = nullptr;				// um texto motivacional, ou não
	Sprite* escButton = nullptr;		// botão esc
	Sprite* enterButton = nullptr;		// botão enter

	float rocketXPosition = -20.0f;		// posição horizontal do player pela tela

public:
	void Init();						// inicialização do nível
	void Update();						// lógica da tela de fim
	void Draw();						// desenho da tela
	void Finalize();					// finalização do nível
};

// ------------------------------------------------------------------------------

#endif
