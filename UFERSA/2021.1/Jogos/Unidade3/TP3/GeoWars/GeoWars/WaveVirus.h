/**********************************************************************************
// WaveVirus (Arquivo de Cabe�alho)
//
// Cria��o:     06 Ago 2019
// Atualiza��o: 15 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Cria uma onda de inimigos Virus
//
**********************************************************************************/

#ifndef _GEOWARS_WAVE_VIRUS_H_
#define _GEOWARS_WAVE_VIRUS_H_

// --------------------------------------------------------------------------------

#include "Object.h"
#include "Random.h"
#include "Timer.h"

// --------------------------------------------------------------------------------

class WaveVirus : public Object
{
private:
	RandF secs;			// valor aleat�rio de segundos
	Timer timer;		// medidor de tempo
	float delay;		// atraso para a pr�xima onda

public:
	WaveVirus();		// construtor
	~WaveVirus() {};	// destrutor

	void Update();		// atualiza��o
	void Draw() {};		// desenho
};

// ---------------------------------------------------------------------------------

#endif
