/**********************************************************************************
// GameOver (Arquivo de Cabe�alho)
// 
// Cria��o:     14 Fev 2013
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Fim do jogo
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
	
	Animation* backgAnim = nullptr;		// anima��o do pano de fundo
	Animation* rocketAnim = nullptr;	// anima��o do personagem

	Sprite* text = nullptr;				// um texto motivacional, ou n�o
	Sprite* escButton = nullptr;		// bot�o esc
	Sprite* enterButton = nullptr;		// bot�o enter

	float rocketXPosition = -20.0f;		// posi��o horizontal do player pela tela

public:
	void Init();						// inicializa��o do n�vel
	void Update();						// l�gica da tela de fim
	void Draw();						// desenho da tela
	void Finalize();					// finaliza��o do n�vel
};

// ------------------------------------------------------------------------------

#endif
