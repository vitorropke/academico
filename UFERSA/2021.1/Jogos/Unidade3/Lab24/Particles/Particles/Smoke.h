/**********************************************************************************
// Smoke (Arquivo de Cabe�alho)
// 
// Cria��o:     17 Mar 2013
// Atualiza��o: 27 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Efeito de fuma�a usando sistema de part�culas
//
**********************************************************************************/

#ifndef _REFINERY_SMOKE_H_
#define _REFINERY_SMOKE_H_

// ---------------------------------------------------------------------------------

#include "Object.h"    
#include "Particles.h"
#include "Types.h"

// ---------------------------------------------------------------------------------

class Smoke : public Object
{
private:
    Particles * smokeGen;               // sistema de part�culas
    bool stop;                          // estado da gera��o de fuma�a
    
public:
    Smoke(float pX, float pY,           // posi��o x, y
          float angle,                  // �ngulo da fuma�a
          bool night);                  // dia ou noite
    
    ~Smoke();                           // destrutor

    int  Size();                        // quantidade de part�culas
    void TurnOff();                     // desligar fuma�a

    void Update();                      // atualiza��o
    void Draw();                        // desenho
}; 

// ---------------------------------------------------------------------------------

inline int Smoke::Size()
{ return smokeGen->Size(); }

inline void Smoke::Draw()
{ smokeGen->Draw(Layer::MIDDLE, 1.0f); }

// ---------------------------------------------------------------------------------


#endif