/**********************************************************************************
// WaveBoomerang (Código Fonte)
//
// Criação:     06 Ago 2019
// Atualização: 15 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Cria uma onda de inimigos Boomerang
//
**********************************************************************************/

#include "WaveBoomerang.h"

#include "Boomerang.h"
#include "Delay.h"
#include "GeoWars.h"
#include "Hud.h"

// ------------------------------------------------------------------------------

WaveBoomerang::WaveBoomerang() : posX(50, game->Width() - 50), posY(50, game->Height() - 50), secs(10.0f, 15.0f)
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

void WaveBoomerang::Update()
{
	// contador de inimigos
	static uint counter = 4;

	// se passou o tempo de atraso
	if (timer.Elapsed(delay) && (Hud::boomerangs < 4) && (GeoWars::player->lives != 0))
	{
		if (counter > 0)
		{
			// enquanto a posição estiver dentro do Viewport, encontre outra posição
			do
			{
				// posição dos inimigos
				pX = posX.Rand();
				pY = posY.Rand();
			} while ((pX > game->viewport.left) && (pX < game->viewport.right) && (pY > game->viewport.top) && (pY < game->viewport.bottom));

			// adiciona nova inimigo
			GeoWars::scene->Add(new Boomerang(pX, pY), MOVING);
			GeoWars::scene->Add(new Boomerang(pX - 50, pY), MOVING);
			GeoWars::scene->Add(new Boomerang(pX, pY - 50), MOVING);
			GeoWars::scene->Add(new Boomerang(pX - 50, pY - 50), MOVING);

			delay = 0.450f;
			timer.Start();
			--counter;
		}
		else
		{
			// nova onda
			counter = 4;
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
