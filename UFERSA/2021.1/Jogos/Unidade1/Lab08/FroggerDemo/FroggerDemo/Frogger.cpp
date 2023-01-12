/**********************************************************************************
// Frogger (Código Fonte)
// 
// Criação:     19 Dez 2012
// Atualização: 14 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define o objeto Sapo no jogo Frogger
//
**********************************************************************************/

#include "Frogger.h"

// ---------------------------------------------------------------------------------

Frogger::Frogger()
{
    sprite_up = new Sprite("Resources/frog_up.png");
    sprite_right = new Sprite("Resources/frog_right.png");
    sprite_left = new Sprite("Resources/frog_left.png");
    sprite_down = new Sprite("Resources/frog_down.png");

    MoveTo(window->CenterX() - sprite_up->Width()/2.0f, 545.0f, Layer::FRONT);

    ctrlUp = true;
    ctrlDown = true;
    ctrlLeft = true;
    ctrlRight = true;

    orientation[0] = false;
    orientation[1] = false;
}

// ---------------------------------------------------------------------------------

Frogger::~Frogger()
{
    delete sprite_up;
    delete sprite_right;
    delete sprite_left;
    delete sprite_down;
}

// ---------------------------------------------------------------------------------

void Frogger::Update()
{
    // desloca sapo para cima
    if (ctrlUp && window->KeyDown(VK_UP))
    {
        Translate(0.0f, -40.0f);
        ctrlUp = false;

        orientation[0] = false;
        orientation[1] = false;
    }
    else if (window->KeyUp(VK_UP))
    {
        ctrlUp = true;
    }
    
    // desloca sapo para baixo
    if (ctrlDown && window->KeyDown(VK_DOWN))
    {
        Translate(0.0f, 40.0f);
        ctrlDown = false;

        orientation[0] = true;
        orientation[1] = true;
    }
    else if (window->KeyUp(VK_DOWN))
    {
        ctrlDown = true;
    }

    // desloca sapo para esquerda
    if (ctrlLeft && window->KeyDown(VK_LEFT))
    {
        Translate(-40.0f, 0.0f);
        ctrlLeft = false;

        orientation[0] = true;
        orientation[1] = false;
    }
    else if (window->KeyUp(VK_LEFT))
    {
        ctrlLeft = true;
    }

    // desloca sapo para direita
    if (ctrlRight && window->KeyDown(VK_RIGHT))
    {
        Translate(40.0f, 0.0f);
        ctrlRight = false;

        orientation[0] = false;
        orientation[1] = true;
    }
    else if (window->KeyUp(VK_RIGHT))
    {
        ctrlRight = true;
    }
    
    // mantém sapo dentro da tela
    if (y < 60)
        MoveTo(x, 60);

    if (y > 540)
        MoveTo(x, 540);

    if (x < 10)
        MoveTo(10, y);

    if (x > 760)
        MoveTo(760, y);
}

// ---------------------------------------------------------------------------------
