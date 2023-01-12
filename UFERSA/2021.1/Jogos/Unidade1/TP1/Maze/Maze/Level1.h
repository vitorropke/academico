/**********************************************************************************
// Level1 (Arquivo de Cabe�alho)
// 
// Cria��o:     18 Jan 2013
// Atualiza��o: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   N�vel 1 do jogo Maze
//
**********************************************************************************/

#ifndef _MAZE_LEVEl1_H_
#define _MAZE_LEVEL1_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Ghost.h"
#include "Player.h"

#include "Font.h"
#include "Game.h"
#include "PowerUp.h"
#include "Scene.h"
#include "Sprite.h"
#include "Timer.h"

// ------------------------------------------------------------------------------

class Level1 : public Game
{
private:
	Sprite* backg = nullptr;								// background
	Sprite* heart[3] = { nullptr, nullptr, nullptr };		// cora��es
	Sprite* noHeart[3] = { nullptr, nullptr, nullptr };		// sem cora��es
	Sprite* target = nullptr;								// alvo do jogador

	Font* countdown = nullptr;								// contagem regressiva para fim da rodada

	Player* player = nullptr;								// jogador
	Ghost* ghost = nullptr;									// fantasma

	PowerUp* powerUp1 = nullptr;							// power up 1
	PowerUp* powerUp2 = nullptr;							// power up 2

	Timer roundTime;										// tempo da rodada atual

	float timeLimit = 75.0f;								// tempo limite de jogo

	float ghostPositionX = 0.0f;							// posi��o do fantasma no eixo X
	float ghostPositionY = 0.0f;							// posi��o do fantasma no eixo Y

	float targetPositionX = window->CenterX() - 25.0f;		// posi��o do alvo do jogador no eixo X
	float targetPositionY = 55.0f;							// posi��o do alvo do jogador no eixo Y

public:
	static Scene* scene;		// cena do jogo

	void Init();				// inicializa jogo
	void Update();				// atualiza l�gica do jogo
	void Draw();				// desenha jogo
	void Finalize();			// finaliza jogo
};

// -----------------------------------------------------------------------------

#endif
