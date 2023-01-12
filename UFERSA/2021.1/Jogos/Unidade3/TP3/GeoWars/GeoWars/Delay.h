/**********************************************************************************
// Delay (Arquivo de Cabe�alho)
//
// Cria��o:     02 Ago 2019
// Atualiza��o: 01 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Sincroniza uma a��o
//
**********************************************************************************/

#ifndef _GEOWARS_DELAY_H_
#define _GEOWARS_DELAY_H_

// --------------------------------------------------------------------------------

#include "Object.h"
#include "Sprite.h"
#include "Timer.h"

// --------------------------------------------------------------------------------

class Delay : public Object
{
private:
	Sprite* logo;			// logotipo do jogo
	Sprite* gameOver;		// texto de fim do jogo
	Sprite* restart;		// comando de reiniciar jogo
	Timer timer;			// medidor de tempo
	Timer killedTimer;		// controla tempo ap�s morte e respawn

	bool notPlayed;			// intro n�o tocada ainda
	bool phase1;			// fase 1 completada
	bool phase2;			// fase 2 completada
	bool phase3;			// fase 3 completada
	bool phase4;			// fase 4 completada
	bool phase5;			// fase 5 completada
	bool phase6;			// fase 6 completada

public:
	static bool ended;		// jogo acabou ou n�o

	Delay();				// construtor
	~Delay();				// destrutor

	void Update();			// atualiza��o
	void Draw();			// desenho
};

// ------------------------------------------------------------------------------

#endif
