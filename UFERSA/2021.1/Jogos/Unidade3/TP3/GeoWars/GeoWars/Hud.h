/**********************************************************************************
// Hud (Arquivo de Cabeçalho)
//
// Criação:     02 Ago 2019
// Atualização: 01 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Heads Up Display
//
**********************************************************************************/

#ifndef _GEOWARS_HUD_H_
#define _GEOWARS_HUD_H_

// --------------------------------------------------------------------------------

#include "Font.h"
#include "Object.h"
#include "Sprite.h"

#include <sstream>

using std::stringstream;

// --------------------------------------------------------------------------------

class Hud : public Object
{
private:
	Font* font = nullptr;				// fonte para exibição normal
	Font* bold = nullptr;				// fonte para exibição negrito
	Sprite* infoBox = nullptr;			// área de informações do jogo
	Sprite* keyMap = nullptr;			// área para teclas de comando
	Sprite* killStatus = nullptr;		// área para teclas de comando
	stringstream text;					// texto temporário

public:
	static uint missiles;				// número de mísseis na tela
	static uint arrows;					// número de inimigos setas
	static uint boomerangs;				// número de inimigos bumerangues
	static uint ships;					// número de inimigos naves
	static uint shurikens;				// número de inimigos shurikens
	static uint spikes;					// número de inimigos espigões
	static uint viruses;				// número de inimigos vírus

	static uint killedArrows;			// número de inimigos setas
	static uint killedBoomerangs;		// número de inimigos bumerangues
	static uint killedShips;			// número de inimigos naves
	static uint killedShurikens;		// número de inimigos shurikens
	static uint killedSpikes;			// número de inimigos espigões
	static uint killedViruses;			// número de inimigos vírus

	Hud();								// construtor
	~Hud();								// destrutor

	void Update();						// atualização
	void Draw();						// desenho
};

// ------------------------------------------------------------------------------

#endif
