/**********************************************************************************
// WaveO (Código Fonte)
//
// Criação:     06 Ago 2019
// Atualização: 15 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Cria uma onda de inimigos Orange
//
**********************************************************************************/

#include "WaveShuriken.h"

#include "Delay.h"
#include "GeoWars.h"
#include "Hud.h"
#include "Shuriken.h"

// ------------------------------------------------------------------------------

WaveShuriken::WaveShuriken() : position(0, 3), delay(1.0f, 5.0f)
{
	// número de inimigos na horizontal (X) e na vertical (Y)
	numX = 8;
	numY = 8;

	// posição dos inimigos
	posX = 0;
	posY = 0;

	// não enviar nova onda agora
	newWave = false;
	waveDelay = delay.Rand();
}

// -------------------------------------------------------------------------------

void WaveShuriken::Update()
{
	// nova onda foi solicitada
	if (newWave && (GeoWars::player->lives != 0))
	{
		// se passou o tempo de atraso da solicitação
		if (timer.Elapsed(waveDelay))
		{
			int positionSwitch;
			// enquanto a posição estiver dentro do Viewport, encontre outra posição
			do
			{
				positionSwitch = position.Rand();

				switch (positionSwitch)
				{
				case 0:
					posX = 50;
					posY = 100;
					break;
				case 1:
					posX = 100;
					posY = 50;
					break;
				case 2:
					posX = game->Width() - 50;
					posY = game->Height() - 100;
					break;
				case 3:
					posX = game->Width() - 100;
					posY = game->Height() - 50;
					break;
				}
			} while ((posX > game->viewport.left) && (posX < game->viewport.right) &&
				(posY > game->viewport.top) && (posY < game->viewport.bottom));

			// origem da onda é aleatória
			switch (positionSwitch)
			{
			case 0:
				// lado esquerdo da tela
				for (int i = 0; i < numY; ++i)
				{
					GeoWars::scene->Add(new Shuriken(posX, posY, GeoWars::player), MOVING);
					posY += 50;
				}
				break;
			case 1:
				// lado superior da tela
				for (int i = 0; i < numX; ++i)
				{
					GeoWars::scene->Add(new Shuriken(posX, posY, GeoWars::player), MOVING);
					posX += 50;
				}
				break;
			case 2:
				// lado direito da tela
				for (int i = 0; i < numY; ++i)
				{
					GeoWars::scene->Add(new Shuriken(posX, posY, GeoWars::player), MOVING);
					posY -= 50;
				}
				break;
			case 3:
				// lado inferior da tela
				for (int i = 0; i < numX; ++i)
				{
					GeoWars::scene->Add(new Shuriken(posX, posY, GeoWars::player), MOVING);
					posX -= 50;
				}
				break;
			}

			// onda enviada
			newWave = false;
		}
	}
	else
	{
		// solicita nova onda se existirem poucos inimigos
		if (Hud::shurikens < 10)
		{
			waveDelay = delay.Rand();
			timer.Start();
			newWave = true;
		}
	}

	// se o jogo reiniciou, apaga esse gerador de ondas
	if (Delay::ended)
	{
		GeoWars::scene->Delete(this, STATIC);
	}
}

// -------------------------------------------------------------------------------
