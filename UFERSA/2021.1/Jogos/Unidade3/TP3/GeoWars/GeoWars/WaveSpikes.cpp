/**********************************************************************************
// WaveG (Código Fonte)
//
// Criação:     06 Ago 2019
// Atualização: 15 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Cria uma onda de inimigos Green
//
**********************************************************************************/

#include "WaveSpikes.h"

#include "Delay.h"
#include "GeoWars.h"
#include "Hud.h"
#include "Spikes.h"

// ------------------------------------------------------------------------------

WaveSpikes::WaveSpikes() : secs(10.0f, 15.0f)
{
	// atraso para a próxima onda
	delay = secs.Rand();
}

// -------------------------------------------------------------------------------

void WaveSpikes::Update()
{
	// contador de inimigos
	static uint counter = 8;

	// se passou o tempo de atraso
	if (timer.Elapsed(delay) && (Hud::spikes < 16) && (GeoWars::player->lives != 0))
	{
		if (counter > 0)
		{
			// adiciona novo inimigo se estiver fora do Viewport
			if ((50 < game->viewport.left) || (50 > game->viewport.right) || (50 < game->viewport.top) || (50 > game->viewport.bottom))
			{
				GeoWars::scene->Add(new Spikes(50, 50, GeoWars::player), MOVING);
			}
			if (((game->Width() - 50) < game->viewport.left) || ((game->Width() - 50) > game->viewport.right) ||
				(50 < game->viewport.top) || (50 > game->viewport.bottom))
			{
				GeoWars::scene->Add(new Spikes(game->Width() - 50, 50, GeoWars::player), MOVING);
			}
			if (((game->Width() - 50) < game->viewport.left) || ((game->Width() - 50) > game->viewport.right) ||
				((game->Height() - 50) < game->viewport.top) || ((game->Height() - 50) > game->viewport.bottom))
			{
				GeoWars::scene->Add(new Spikes(game->Width() - 50, game->Height() - 50, GeoWars::player), MOVING);
			}
			if ((50 < game->viewport.left) || (50 > game->viewport.right) ||
				((game->Height() - 50) < game->viewport.top) || ((game->Height() - 50) > game->viewport.bottom))
			{
				GeoWars::scene->Add(new Spikes(50, game->Height() - 50, GeoWars::player), MOVING);
			}

			delay = 0.450f;
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
