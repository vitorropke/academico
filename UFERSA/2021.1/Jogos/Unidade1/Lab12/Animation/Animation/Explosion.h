/**********************************************************************************
// Explosion (Arquivo de Cabeçalho)
//
// Criação:     20 Jan 2013
// Atualização: 27 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Animação de uma explosão
//
**********************************************************************************/

#ifndef _ANIMA_EXPLOSION_H_
#define _ANIMA_EXPLOSION_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Animation.h"                  // animação de sprites
#include "Object.h"                     // interface de Object
#include "Types.h"                      // tipos específicos da engine

// ---------------------------------------------------------------------------------

class Explosion : public Object
{
private:
    Animation* anim;                   // animação de explosão

public:
    Explosion(TileSet* tiles);         // construtor
    ~Explosion();                       // destrutor

    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline void Explosion::Draw()
{
    anim->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif