/**********************************************************************************
// Level1 (Arquivo de Cabe�alho)
// 
// Cria��o:     14 Fev 2013
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   N�vel 1 do jogo
//
**********************************************************************************/

#ifndef _LAND_THE_BOOSTER_LEVEL1_H_
#define _LAND_THE_BOOSTER_LEVEL1_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Player.h"

#include "Game.h"
#include "Scene.h"

// ------------------------------------------------------------------------------

class Level1 : public Game
{
private:
	Sprite* sky = nullptr;			// desenho do c�u
	Sprite* backgBack = nullptr;	// desenho do plano de fundo
	Sprite* backgFront = nullptr;	// desenho do plano de frente

public:
	static Scene* scene;			// cena do n�vel

	void Init();					// inicializa��o do n�vel
	void Update();					// atualiza l�gica do jogo
	void Draw();					// desenha jogo
	void Finalize();				// finaliza��o do n�vel
};

// -----------------------------------------------------------------------------

#endif
