/**********************************************************************************
// WaveShip (Arquivo de Cabe�alho)
//
// Cria��o:     06 Ago 2019
// Atualiza��o: 15 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Cria uma onda de inimigos Ship
//
**********************************************************************************/

#ifndef _GEOWARS_WAVE_SHIP_H_
#define _GEOWARS_WAVE_SHIP_H_

// --------------------------------------------------------------------------------

#include "Object.h"
#include "Random.h"
#include "Timer.h"

// --------------------------------------------------------------------------------

class WaveShip : public Object
{
private:
	float pX, pY;		// posi��o dos inimigos 
	RandF posX;			// valor aleat�rio para posi��o X
	RandF posY;			// valor aleat�rio para posi��o Y
	RandF secs;			// valor aleat�rio de segundos
	Timer timer;		// medidor de tempo
	float delay;		// atraso para a pr�xima onda

public:
	WaveShip();			// construtor
	~WaveShip() {};		// destrutor

	void Update();		// atualiza��o
	void Draw() {};		// desenho
};

// ---------------------------------------------------------------------------------

#endif
