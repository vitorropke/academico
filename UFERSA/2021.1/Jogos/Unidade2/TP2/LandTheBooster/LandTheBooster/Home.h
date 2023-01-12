/**********************************************************************************
// Home (Arquivo de Cabeçalho)
// 
// Criação:     14 Fev 2013
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Tela de abertura do jogo
//
**********************************************************************************/

#ifndef _LAND_THE_BOOSTER_HOME_H_
#define _LAND_THE_BOOSTER_HOME_H_

// ------------------------------------------------------------------------------
// Inclusões

#include "Animation.h"
#include "Game.h"
#include "Sprite.h"
#include "TileSet.h"

// ------------------------------------------------------------------------------

class Home : public Game
{
private:
	TileSet* backg = nullptr;			// pano de fundo animado
	
	Animation* backgAnim = nullptr;		// animação do pano de fundo
	
	Sprite* logo = nullptr;				// logo do jogo
	
	Sprite* escButton = nullptr;		// botão esc
	Sprite* iButton = nullptr;			// botão i
	Sprite* enterButton = nullptr;		// botão enter

public:
	void Init();						// inicia nível
	void Update();						// atualiza lógica do jogo
	void Draw();						// desenha jogo
	void Finalize();					// finaliza nível
};

// -----------------------------------------------------------------------------

#endif
