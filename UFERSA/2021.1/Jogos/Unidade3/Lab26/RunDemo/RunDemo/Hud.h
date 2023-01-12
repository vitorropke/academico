/**********************************************************************************
// Hud (Arquivo de Cabe�alho)
//
// Cria��o:     02 Ago 2019
// Atualiza��o: 05 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Heads Up Display
//
**********************************************************************************/

#ifndef _RUNDEMO_HUD_H_
#define _RUNDEMO_HUD_H_

// --------------------------------------------------------------------------------

#include "Object.h"
#include "Sprite.h"
#include "Font.h"
#include <sstream>
using std::stringstream;

// --------------------------------------------------------------------------------

class Hud : public Object
{
private:
    Font * font;                    // fonte para exibi��o normal
    Font * bold;                    // fonte para exibi��o negrito
    Sprite * infoBox;               // �rea de informa��es do jogo
    Sprite * keyMap;                // �rea para teclas de comando
    stringstream text;              // texto tempor�rio

public:
    static uint missiles;           // n�mero de m�sseis na tela
    static uint enemies;            // n�mero de inimigos na tela
    static uint waves;              // n�mero de ondas de inimigos

    Hud();                          // construtor
    ~Hud();                         // destrutor

    void Update();                  // atualiza��o
    void Draw();                    // desenho
};

// ------------------------------------------------------------------------------

#endif

