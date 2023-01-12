/**********************************************************************************
// Explosion (Código Fonte)
//
// Criação:     20 Jan 2013
// Atualização: 27 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Animação de um personagem correndo
//
**********************************************************************************/

#include "Anima.h"
#include "Run.h"

// ---------------------------------------------------------------------------------

Run::Run(TileSet* tiles)
{
    anim = new Animation(tiles, 0.05f, true);
}

// ---------------------------------------------------------------------------------

Run::~Run()
{
    delete anim;
}

// ---------------------------------------------------------------------------------

void Run::Update()
{
    Translate(velX * gameTime, 0);

    if (x - 50 > window->Width())
        MoveTo(-50.0f, Y());

    anim->NextFrame();
    if (anim->Inactive())
        Anima::scene->Delete();
}

// ---------------------------------------------------------------------------------
