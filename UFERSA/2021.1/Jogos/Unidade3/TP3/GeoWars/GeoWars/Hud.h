/**********************************************************************************
// Hud (Arquivo de Cabe�alho)
//
// Cria��o:     02 Ago 2019
// Atualiza��o: 01 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Heads Up Display
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
	Font* font = nullptr;				// fonte para exibi��o normal
	Font* bold = nullptr;				// fonte para exibi��o negrito
	Sprite* infoBox = nullptr;			// �rea de informa��es do jogo
	Sprite* keyMap = nullptr;			// �rea para teclas de comando
	Sprite* killStatus = nullptr;		// �rea para teclas de comando
	stringstream text;					// texto tempor�rio

public:
	static uint missiles;				// n�mero de m�sseis na tela
	static uint arrows;					// n�mero de inimigos setas
	static uint boomerangs;				// n�mero de inimigos bumerangues
	static uint ships;					// n�mero de inimigos naves
	static uint shurikens;				// n�mero de inimigos shurikens
	static uint spikes;					// n�mero de inimigos espig�es
	static uint viruses;				// n�mero de inimigos v�rus

	static uint killedArrows;			// n�mero de inimigos setas
	static uint killedBoomerangs;		// n�mero de inimigos bumerangues
	static uint killedShips;			// n�mero de inimigos naves
	static uint killedShurikens;		// n�mero de inimigos shurikens
	static uint killedSpikes;			// n�mero de inimigos espig�es
	static uint killedViruses;			// n�mero de inimigos v�rus

	Hud();								// construtor
	~Hud();								// destrutor

	void Update();						// atualiza��o
	void Draw();						// desenho
};

// ------------------------------------------------------------------------------

#endif
