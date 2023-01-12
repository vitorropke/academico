/**********************************************************************************
// WaveShip (Código Fonte)
//
// Criação:     06 Ago 2019
// Atualização: 15 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Cria uma onda de inimigos Ship
//
**********************************************************************************/

#include "WaveShip.h"

#include "Delay.h"
#include "GeoWars.h"
#include "Hud.h"
#include "Ship.h"

// ------------------------------------------------------------------------------

WaveShip::WaveShip() : posX(0, game->Width()), posY(0, game->Height()), secs(8.0f, 12.0f)
{
	// enquanto a posição estiver dentro do Viewport, encontre outra posição
	do
	{
		// posição dos inimigos
		pX = posX.Rand();
		pY = posY.Rand();
	} while ((pX > game->viewport.left) && (pX < game->viewport.right) && (pY > game->viewport.top) && (pY < game->viewport.bottom));

	// atraso para a próxima onda
	delay = secs.Rand();
}

// -------------------------------------------------------------------------------

void WaveShip::Update()
{
	// contador de inimigos
	static uint counter = 8;

	// se passou o tempo de atraso
	if (timer.Elapsed(delay) && (Hud::ships < 15) && (GeoWars::player->lives != 0))
	{
		if (counter > 0)
		{
			// adiciona nova inimigo
			GeoWars::scene->Add(new Ship(pX, pY, GeoWars::player), MOVING);

			// enquanto a posição estiver dentro do Viewport, encontre outra posição
			do
			{
				// posição dos inimigos
				pX = posX.Rand();
				pY = posY.Rand();
			} while ((pX > game->viewport.left) && (pX < game->viewport.right) && (pY > game->viewport.top) && (pY < game->viewport.bottom));

			delay = 0.850f;
			timer.Start();
			--counter;
		}
		else
		{
			// nova onda
			counter = 8;
			delay = secs.Rand();
			timer.Start();
		}
	}

	// se o jogo reiniciou, apaga esse gerador de ondas
	if (Delay::ended)
	{
		GeoWars::scene->Delete(this, STATIC);
	}
}

// -------------------------------------------------------------------------------
