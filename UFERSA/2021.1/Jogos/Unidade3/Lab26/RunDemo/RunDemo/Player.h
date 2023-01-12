/**********************************************************************************
// Player (Arquivo de Cabe�alho)
// 
// Cria��o:     10 Out 2012
// Atualiza��o: 05 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define a classe jogador
//
**********************************************************************************/

#ifndef _RUNDEMO_PLAYER_H_
#define _RUNDEMO_PLAYER_H_

// ---------------------------------------------------------------------------------

#include "Object.h"                     // objetos do jogo
#include "Sprite.h"                     // desenho de sprites
#include "Vector.h"                     // representa��o de vetores
#include "Particles.h"                  // sistema de part�culas
#include "Controller.h"                 // entrada pelo controle

// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
    Sprite * sprite;                    // sprite do objeto
    Particles * tail;                   // calda do jogador
    Controller * gamepad;               // leitura do controle
    bool gamepadOn;                     // controle est� ligado

public:
    Vector * speed;                     // velocidade e dire��o

    Player();                           // construtor
    ~Player();                          // destrutor
    
    void Move(Vector && v);             // movimenta jogador
    void Update();                      // atualiza��o
    void Draw();                        // desenho
}; 
// ---------------------------------------------------------------------------------

#endif