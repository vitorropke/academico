/**********************************************************************************
// Debris (Arquivo de Cabe�alho)
// 
// Cria��o:     07 Fev 2013
// Atualiza��o: 25 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Anima��o de explos�o
//
**********************************************************************************/

#ifndef _ASTEROIDS_DEBRIS_H_
#define _ASTEROIDS_DEBRIS_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Object.h"                         // objetos do jogo
#include "Particles.h"                      // part�culas animadas
#include "Types.h"                          // tipos espec�ficos da engine

// ---------------------------------------------------------------------------------

class Debris : public Object
{
private:
    Particles* debris;                      // sistema de part�culas
    random_device rd;                       // gerador de n�mero aleat�rio
    mt19937 mt{ rd() };                     // gerador mersenne twister
    Rnd RandAngle{ 0.0f, 359.0f };          // �ngulo aleat�rio

public:
    Debris(float posX, float posY);         // construtor
    ~Debris();                              // destrutor

    void Update();                          // atualiza��o
    void Draw();                            // desenho
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

inline void Debris::Draw()
{
    debris->Draw(Layer::MIDDLE, 0.0f);
}

// ---------------------------------------------------------------------------------

#endif