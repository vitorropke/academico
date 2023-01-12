/**********************************************************************************
// WaveShuriken (Arquivo de Cabe�alho)
//
// Cria��o:     06 Ago 2019
// Atualiza��o: 15 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Cria uma onda de inimigos Shuriken
//
**********************************************************************************/

#ifndef _GEOWARS_WAVE_SHURIKEN_H_
#define _GEOWARS_WAVE_SHURIKEN_H_

// --------------------------------------------------------------------------------

#include "Object.h"
#include "Random.h"
#include "Sprite.h"
#include "Timer.h"

// --------------------------------------------------------------------------------

class WaveShuriken : public Object
{
private:
	int numX, numY;			// n�mero de inimigos que cabem na tela
	float posX, posY;		// posi��o dos inimigos 
	RandI position;			// valor aleat�rio para posi��o
	RandF delay;			// valor aleat�rio para tempo
	Timer timer;			// medidor de tempo
	float waveDelay;		// atraso para a pr�xima onda
	bool newWave;			// enviar nova onda

public:
	WaveShuriken();			// construtor
	~WaveShuriken() {};		// destrutor

	void Update();			// atualiza��o
	void Draw() {};			// desenho
};

// ---------------------------------------------------------------------------------

#endif
