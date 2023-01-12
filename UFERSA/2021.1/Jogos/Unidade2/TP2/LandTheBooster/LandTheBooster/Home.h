/**********************************************************************************
// Home (Arquivo de Cabe�alho)
// 
// Cria��o:     14 Fev 2013
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Tela de abertura do jogo
//
**********************************************************************************/

#ifndef _LAND_THE_BOOSTER_HOME_H_
#define _LAND_THE_BOOSTER_HOME_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Animation.h"
#include "Game.h"
#include "Sprite.h"
#include "TileSet.h"

// ------------------------------------------------------------------------------

class Home : public Game
{
private:
	TileSet* backg = nullptr;			// pano de fundo animado
	
	Animation* backgAnim = nullptr;		// anima��o do pano de fundo
	
	Sprite* logo = nullptr;				// logo do jogo
	
	Sprite* escButton = nullptr;		// bot�o esc
	Sprite* iButton = nullptr;			// bot�o i
	Sprite* enterButton = nullptr;		// bot�o enter

public:
	void Init();						// inicia n�vel
	void Update();						// atualiza l�gica do jogo
	void Draw();						// desenha jogo
	void Finalize();					// finaliza n�vel
};

// -----------------------------------------------------------------------------

#endif
