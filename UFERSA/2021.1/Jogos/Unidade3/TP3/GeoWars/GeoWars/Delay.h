/**********************************************************************************
// Delay (Arquivo de Cabeçalho)
//
// Criação:     02 Ago 2019
// Atualização: 01 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Sincroniza uma ação
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
	Timer killedTimer;		// controla tempo após morte e respawn

	bool notPlayed;			// intro não tocada ainda
	bool phase1;			// fase 1 completada
	bool phase2;			// fase 2 completada
	bool phase3;			// fase 3 completada
	bool phase4;			// fase 4 completada
	bool phase5;			// fase 5 completada
	bool phase6;			// fase 6 completada

public:
	static bool ended;		// jogo acabou ou não

	Delay();				// construtor
	~Delay();				// destrutor

	void Update();			// atualização
	void Draw();			// desenho
};

// ------------------------------------------------------------------------------

#endif
