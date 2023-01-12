/**********************************************************************************
// WaveArrow (Arquivo de Cabeçalho)
//
// Criação:     06 Ago 2019
// Atualização: 15 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Cria uma onda de inimigos Arrow
//
**********************************************************************************/

#ifndef _GEOWARS_WAVE_ARROW_H_
#define _GEOWARS_WAVE_ARROW_H_

// --------------------------------------------------------------------------------

#include "Object.h"
#include "Random.h"
#include "Timer.h"

// --------------------------------------------------------------------------------

class WaveArrow : public Object
{
private:
	float pX, pY;		// posição dos inimigos 
	RandF posX;			// valor aleatório para posição X
	RandF posY;			// valor aleatório para posição Y
	RandF secs;			// valor aleatório de segundos
	Timer timer;		// medidor de tempo
	float delay;		// atraso para a próxima onda

public:
	WaveArrow();		// construtor
	~WaveArrow() {};	// destrutor

	void Update();		// atualização
	void Draw() {};		// desenho
};

// ------------------------------------------------------------------------------

#endif
