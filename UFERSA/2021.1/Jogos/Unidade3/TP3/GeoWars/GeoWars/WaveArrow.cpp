/**********************************************************************************
// WaveArrow (C�digo Fonte)
//
// Cria��o:     06 Ago 2019
// Atualiza��o: 15 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Cria uma onda de inimigos Arrow
//
**********************************************************************************/

#include "WaveArrow.h"

#include "Arrow.h"
#include "Delay.h"
#include "GeoWars.h"
#include "Hud.h"

// ------------------------------------------------------------------------------

WaveArrow::WaveArrow() : posX(0, game->Width()), posY(0, game->Height()), secs(2.0f, 4.0f)
{
	// enquanto a posi��o estiver dentro do Viewport, encontre outra posi��o
	do
	{
		// posi��o dos inimigos
		pX = posX.Rand();
		pY = posY.Rand();
	} while ((pX > game->viewport.left) && (pX < game->viewport.right) && (pY > game->viewport.top) && (pY < game->viewport.bottom));

	// atraso para a pr�xima onda
	delay = secs.Rand();
}

// ------------------------------------------------------------------------------

void WaveArrow::Update()
{
	// se passou o tempo de atraso
	if (timer.Elapsed(delay) && (Hud::arrows < 5) && (GeoWars::player->lives != 0))
	{
		// adiciona novo inimigo
		GeoWars::scene->Add(new Arrow(pX, pY, GeoWars::player), MOVING);

		// enquanto a posi��o estiver dentro do Viewport, encontre outra posi��o
		do
		{
			// posi��o dos inimigos
			pX = posX.Rand();
			pY = posY.Rand();
		} while ((pX > game->viewport.left) && (pX < game->viewport.right) && (pY > game->viewport.top) && (pY < game->viewport.bottom));

		// reinicia o timer
		timer.Start();
	}

	// se o jogo reiniciou, apaga esse gerador de ondas
	if (Delay::ended)
	{
		GeoWars::scene->Delete(this, STATIC);
	}
}

// -------------------------------------------------------------------------------
