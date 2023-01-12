/**********************************************************************************
// WaveVirus (Arquivo de Cabeçalho)
//
// Criação:     06 Ago 2019
// Atualização: 15 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Cria uma onda de inimigos Virus
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
	RandF secs;			// valor aleatório de segundos
	Timer timer;		// medidor de tempo
	float delay;		// atraso para a próxima onda

public:
	WaveVirus();		// construtor
	~WaveVirus() {};	// destrutor

	void Update();		// atualização
	void Draw() {};		// desenho
};

// ---------------------------------------------------------------------------------

#endif
