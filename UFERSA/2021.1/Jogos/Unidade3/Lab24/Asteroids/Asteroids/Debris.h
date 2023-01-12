/**********************************************************************************
// Debris (Arquivo de Cabeçalho)
// 
// Criação:     07 Fev 2013
// Atualização: 25 Out 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Animação de explosão
//
**********************************************************************************/

#ifndef _ASTEROIDS_DEBRIS_H_
#define _ASTEROIDS_DEBRIS_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Object.h"                         // objetos do jogo
#include "Particles.h"                      // partículas animadas
#include "Types.h"                          // tipos específicos da engine

// ---------------------------------------------------------------------------------

class Debris : public Object
{
private:
    Particles* debris;                      // sistema de partículas
    random_device rd;                       // gerador de número aleatório
    mt19937 mt{ rd() };                     // gerador mersenne twister
    Rnd RandAngle{ 0.0f, 359.0f };          // ângulo aleatório

public:
    Debris(float posX, float posY);         // construtor
    ~Debris();                              // destrutor

    void Update();                          // atualização
    void Draw();                            // desenho
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline void Debris::Draw()
{
    debris->Draw(Layer::MIDDLE, 0.0f);
}

// ---------------------------------------------------------------------------------

#endif