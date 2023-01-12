/**********************************************************************************
// Frogger (Arquivo de Cabeçalho)
// 
// Criação:     19 Dez 2012
// Atualização: 14 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define o objeto Sapo no jogo Frogger
//
**********************************************************************************/

#ifndef _FROGGER_FROGGER_H_
#define _FROGGER_FROGGER_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"             // tipos específicos da engine
#include "Object.h"            // interface de object
#include "Sprite.h"            // interface de sprites

// ---------------------------------------------------------------------------------

class Frogger : public Object
{
private:
    Sprite * sprite_up;
    Sprite * sprite_right;
    Sprite * sprite_left;
    Sprite * sprite_down;

    bool ctrlUp;
    bool ctrlDown;
    bool ctrlLeft;
    bool ctrlRight;

    bool orientation[2];    // 00 - up
                            // 01 - right
                            // 10 - left
                            // 11 - down

public:
    Frogger();
    ~Frogger();

    void Update();
    void Draw();
};

// ---------------------------------------------------------------------------------
// Funções Membro Inline

inline void Frogger::Draw()
{
    // Desenha sapo virado para cima
    if (!orientation[0] && !orientation[1])
    {
        sprite_up->Draw(x, y, z);
    }
    // Desenha sapo virado para direita
    if (!orientation[0] && orientation[1])
    {
        sprite_right->Draw(x, y, z);
    }
    // Desenha sapo virado para esquerda
    if (orientation[0] && !orientation[1])
    {
        sprite_left->Draw(x, y, z);
    }
    // Desenha sapo virado para baixo
    if (orientation[0] && orientation[1])
    {
        sprite_down->Draw(x, y, z);
    }
}

// ---------------------------------------------------------------------------------

#endif