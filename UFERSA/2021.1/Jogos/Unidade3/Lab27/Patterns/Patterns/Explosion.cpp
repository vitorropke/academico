/**********************************************************************************
// Explosion (C�digo Fonte)
//
// Cria��o:     10 Ago 2019
// Atualiza��o: 10 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Objeto representando uma explos�o
//
**********************************************************************************/

#include "Explosion.h"
#include "Patterns.h"
#include "Player.h"

// -------------------------------------------------------------------------------

Explosion::Explosion(float posX, float posY)
{
    anim = new Animation(Player::exploSet, 0.060f, false);
    MoveTo(posX, posY);
}

// -------------------------------------------------------------------------------

Explosion::~Explosion()
{
    delete anim;
}

// -------------------------------------------------------------------------------

void Explosion::Update()
{
    anim->NextFrame();

    if (anim->Inactive())
        Patterns::scene->Delete();
}

// -------------------------------------------------------------------------------
