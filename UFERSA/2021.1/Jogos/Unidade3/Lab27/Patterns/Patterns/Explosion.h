/**********************************************************************************
// Explosion (Arquivo de Cabe�alho)
//
// Cria��o:     10 Ago 2019
// Atualiza��o: 10 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Objeto representando uma explos�o
//
**********************************************************************************/

#ifndef _PATTERNS_EXPLOSION_H_
#define _PATTERNS_EXPLOSION_H_

// ---------------------------------------------------------------------------------

#include "Object.h"                         // objetos do jogo
#include "TileSet.h"                        // carregamento de imagens
#include "Animation.h"                      // desenho de sprites

// ---------------------------------------------------------------------------------

class Explosion : public Object
{
private:
    Animation * anim;                       // anima��o do objeto

public:
    Explosion(float posX, float posY);      // construtor
    ~Explosion();                           // destrutor

    void Update();                          // atualiza estado do objeto
    void Draw();                            // desenha objeto
};

// ---------------------------------------------------------------------------------

inline void Explosion::Draw()
{ anim->Draw(x, y); }

// ---------------------------------------------------------------------------------

#endif
