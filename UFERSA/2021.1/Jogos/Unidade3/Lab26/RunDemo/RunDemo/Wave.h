/**********************************************************************************
// Wave (Arquivo de Cabe�alho)
//
// Cria��o:     06 Ago 2019
// Atualiza��o: 05 Ago 2019
// Compilador:  Visual C++ 2019
//
// Descri��o:   Cria uma onda de inimigos
//
**********************************************************************************/

#ifndef _RUNDEMO_WAVE_H_
#define _RUNDEMO_WAVE_H_

// --------------------------------------------------------------------------------

#include "Object.h"
#include "Timer.h"
#include "Random.h"

// --------------------------------------------------------------------------------

class Wave : public Object
{
private: 
    RandF secs;             // valor aleat�rio de segundos
    Timer timer;            // medidor de tempo
    float delay;            // atraso para a pr�xima onda

public:
    Wave();                 // construtor
    ~Wave();                // destrutor

    void Update();          // atualiza��o
    void Draw();            // desenho
};

// ------------------------------------------------------------------------------

#endif
