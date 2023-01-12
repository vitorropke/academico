/**********************************************************************************
// Explosion (Arquivo de Cabeçalho)
//
// Criação:     20 Jan 2013
// Atualização: 27 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Animação de um personagem correndo
//
**********************************************************************************/

#ifndef _ANIMA_RUN_H_
#define _ANIMA_RUN_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Animation.h"                  // animação de sprites
#include "Object.h"                     // interface de Object
#include "Types.h"                      // tipos específicos da engine

// ---------------------------------------------------------------------------------

class Run : public Object
{
private:
    Animation* anim;                    // animação de explosão
    float velX = 500.0f;                     // velocidade horizontal do player

public:
    Run(TileSet* tiles);                // construtor
    ~Run();                             // destrutor

    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline void Run::Draw()
{
    anim->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif