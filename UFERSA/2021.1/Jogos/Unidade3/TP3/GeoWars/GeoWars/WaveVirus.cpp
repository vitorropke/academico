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

#include "WaveVirus.h"

#include "Delay.h"
#include "GeoWars.h"
#include "Hud.h"
#include "Virus.h"

// ------------------------------------------------------------------------------

WaveVirus::WaveVirus() : secs(10.0f, 15.0f)
{
	// atraso para a próxima onda
	delay = secs.Rand();
}

// -------------------------------------------------------------------------------

void WaveVirus::Update()
{
	// contador de inimigos
	static uint counter = 4;

	// se passou o tempo de atraso
	if (timer.Elapsed(delay) && (Hud::viruses < 4) && (GeoWars::player->lives != 0))
	{
		if (counter > 0)
		{
			// adiciona novo inimigo se estiver fora do Viewport
			if ((50 < game->viewport.left) || (50 > game->viewport.right) || (50 < game->viewport.top) || (50 > game->viewport.bottom))
			{
				GeoWars::scene->Add(new Virus(50, 50), MOVING);
			}
			if (((game->Width() - 50) < game->viewport.left) || ((game->Width() - 50) > game->viewport.right) ||
				(50 < game->viewport.top) || (50 > game->viewport.bottom))
			{
				GeoWars::scene->Add(new Virus(game->Width() - 50, 50), MOVING);
			}
			if (((game->Width() - 50) < game->viewport.left) || ((game->Width() - 50) > game->viewport.right) ||
				((game->Height() - 50) < game->viewport.top) || ((game->Height() - 50) > game->viewport.bottom))
			{
				GeoWars::scene->Add(new Virus(game->Width() - 50, game->Height() - 50), MOVING);
			}
			if ((50 < game->viewport.left) || (50 > game->viewport.right) ||
				((game->Height() - 50) < game->viewport.top) || ((game->Height() - 50) > game->viewport.bottom))
			{
				GeoWars::scene->Add(new Virus(50, game->Height() - 50), MOVING);
			}

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
