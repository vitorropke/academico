/**********************************************************************************
// TiledScroll (Arquivo de Cabe�alho)
//
// Cria��o:     22 Out 2012
// Atualiza��o: 12 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Desenhando e movimentando um background formado por blocos
//
**********************************************************************************/

#ifndef _TILEDSCROLL_H_
#define _TILEDSCROLL_H_

// ------------------------------------------------------------------------------

#include "Resources.h"              // recursos utilizados no jogo (cursor, �cone, etc.) 
#include "Game.h"                   // defini��o da classe jogo
#include "Font.h"                   // fonte para exibi��o de texto
#include "Sprite.h"                 // defini��o dos sprites
#include "Background.h"             // pano de fundo
#include <sstream>                  // sa�da para strings
using std::stringstream;    

// ------------------------------------------------------------------------------

class TiledScroll : public Game
{
private:
    Sprite * infoBox = nullptr;     // caixa de informa��es
    Sprite * keyMap = nullptr;      // caixa para teclas de atalho
    Font * font = nullptr;          // fonte para texto normal
    Font * bold = nullptr;          // fonte para texto negrito
    stringstream text;              // texto tempor�rio

    Image * tiles = nullptr;        // imagem formada por blocos
    Background * backg = nullptr;   // pano de fundo
    ViewPort viewport;              // �rea de visualiza��o
    float scrollSpeed;              // velocidade de scrolling

public:
    void Init();                    // inicializa jogo
    void Update();                  // atualiza l�gica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza jogo
};

// ---------------------------------------------------------------------------------

#endif