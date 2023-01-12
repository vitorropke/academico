/**********************************************************************************
// Missile (C�digo Fonte)
// 
// Cria��o:     21 Dez 2012
// Atualiza��o: 10 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Representa um m�ssil
//
**********************************************************************************/

#include "Missile.h"
#include "Patterns.h"
#include "Player.h"

// ---------------------------------------------------------------------------------

Missile::Missile(float pX, float pY)
{
    sprite = new Sprite(Player::missile);
    MoveTo(pX, pY);
    BBox(new Rect(-3, -8, 3, 8));
    vel = 450;
    type = MISSILE;
}

// ---------------------------------------------------------------------------------

Missile::~Missile()
{
    delete sprite;
}

// ---------------------------------------------------------------------------------

void Missile::Update()
{
    // m�ssil se move apenas no eixo y
    Translate(0, -vel * gameTime);

    // remove m�sseis que saem da janela
    if (y < 0)
        Patterns::scene->Delete();
}

// ---------------------------------------------------------------------------------
