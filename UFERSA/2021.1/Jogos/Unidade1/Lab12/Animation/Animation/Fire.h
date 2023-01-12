/**********************************************************************************
// Explosion (Arquivo de Cabeçalho)
//
// Criação:     20 Jan 2013
// Atualização: 27 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Animação de um fogo
//
**********************************************************************************/

#ifndef _ANIMA_FIRE_H_
#define _ANIMA_FIRE_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // animação de sprites

// ---------------------------------------------------------------------------------

class Fire : public Object
{
private:
    Animation* anim;                    // animação de explosão

public:
    Fire(TileSet* tiles);               // construtor
    ~Fire();                            // destrutor

    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline void Fire::Draw()
{
    anim->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif