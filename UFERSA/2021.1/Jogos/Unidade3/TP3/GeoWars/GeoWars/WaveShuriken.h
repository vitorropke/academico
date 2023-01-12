/**********************************************************************************
// WaveShuriken (Arquivo de Cabeçalho)
//
// Criação:     06 Ago 2019
// Atualização: 15 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Cria uma onda de inimigos Shuriken
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
	int numX, numY;			// número de inimigos que cabem na tela
	float posX, posY;		// posição dos inimigos 
	RandI position;			// valor aleatório para posição
	RandF delay;			// valor aleatório para tempo
	Timer timer;			// medidor de tempo
	float waveDelay;		// atraso para a próxima onda
	bool newWave;			// enviar nova onda

public:
	WaveShuriken();			// construtor
	~WaveShuriken() {};		// destrutor

	void Update();			// atualização
	void Draw() {};			// desenho
};

// ---------------------------------------------------------------------------------

#endif
