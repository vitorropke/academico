/**********************************************************************************
// Cars (Arquivo de Cabe�alho)
//
// Cria��o:     14 Jul 2019
// Atualiza��o: 06 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Carros advers�rios
//
**********************************************************************************/

#ifndef _TOPGEAR_CARS_H_
#define _TOPGEAR_CARS_H_

// ---------------------------------------------------------------------------------

#include "Object.h"                 // objetos do jogo 
#include "Sprite.h"                 // desenho de sprites
#include "Types.h"                  // tipos espec�ficos do motor

// ---------------------------------------------------------------------------------

class Cars : public Object
{
private:
    Sprite * sprite;                // sprite do carro branco
    float deltaX;                   // valor do deslocamento eixo X
    float deltaY;                   // valor do deslocamento eixo Y
    float speed;                    // velocidade do carro

public:
    Cars();                         // construtor
    ~Cars();                        // destrutor

    void Update();                  // atualiza��o
    void Draw();                    // desenho
};

// ---------------------------------------------------------------------------------

#endif

