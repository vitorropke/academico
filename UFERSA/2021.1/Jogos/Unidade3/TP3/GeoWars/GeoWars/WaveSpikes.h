/**********************************************************************************
// WaveSpikes (Arquivo de Cabe�alho)
//
// Cria��o:     06 Ago 2019
// Atualiza��o: 15 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Cria uma onda de inimigos Spikes
//
**********************************************************************************/

#ifndef _GEOWARS_WAVE_SPIKES_H_
#define _GEOWARS_WAVE_SPIKES_H_

// --------------------------------------------------------------------------------

#include "Object.h"
#include "Random.h"
#include "Timer.h"

// --------------------------------------------------------------------------------

class WaveSpikes : public Object
{
private:
	RandF secs;			// valor aleat�rio de segundos
	Timer timer;		// medidor de tempo
	float delay;		// atraso para a pr�xima onda

public:
	WaveSpikes();		// construtor
	~WaveSpikes() {};	// destrutor

	void Update();		// atualiza��o
	void Draw() {};		// desenho
};

// ---------------------------------------------------------------------------------

#endif
