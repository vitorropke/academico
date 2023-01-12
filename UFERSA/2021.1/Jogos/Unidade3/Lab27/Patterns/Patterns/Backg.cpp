/**********************************************************************************
// Backg (C�digo Fonte)
// 
// Cria��o:     21 Abr 2012
// Atualiza��o: 10 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Plano de fundo do jogo
//
**********************************************************************************/

#include "Backg.h"

// ---------------------------------------------------------------------------------

Backg::Backg()
{
    // cria sprites do plano de fundo
    backg = new Sprite("Resources/Space.png");

    // posi��o inicial do plano de fundo
    MoveTo(window->CenterX(), window->CenterY(), Layer::BACK);
}

// ---------------------------------------------------------------------------------

Backg::~Backg()
{
    delete backg;
}

// -------------------------------------------------------------------------------

void Backg::Update()
{
    // move continuamente o pano de fundo
    Translate(0, 50 * gameTime);

    // se o pano de funda saiu completamente da janela
    if (y - backg->Height() / 2.0f > window->Height())
        // desloca ele de volta para cima
        Translate(0, -1.0f * backg->Height());
}

// -------------------------------------------------------------------------------

void Backg::Draw()
{
    // desenha pano de fundo
    backg->Draw(x, y, Layer::BACK);
    
    // se o pano de fundo n�o preencher toda a janela
    if (y - backg->Height()/2.0f > 0)
        // desenha uma segunda c�pia 
        backg->Draw(x, y - backg->Height(), Layer::BACK);
}

// -------------------------------------------------------------------------------
