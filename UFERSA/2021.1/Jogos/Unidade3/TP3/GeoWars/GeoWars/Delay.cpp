/**********************************************************************************
// Delay (Código Fonte)
//
// Criação:     02 Ago 2019
// Atualização: 01 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Sincroniza uma ação
//
**********************************************************************************/

#include "Delay.h"

#include "GeoWars.h"
#include "Hud.h"
#include "WaveArrow.h"
#include "WaveBoomerang.h"
#include "WaveShip.h"
#include "WaveShuriken.h"
#include "WaveSpikes.h"
#include "WaveVirus.h"

// ------------------------------------------------------------------------------

// inicializa variável estática
bool Delay::ended = false;

// ------------------------------------------------------------------------------

Delay::Delay()
{
	logo = new Sprite("Resources/SceneContent/Logo.png");
	gameOver = new Sprite("Resources/SceneContent/GameOver.png");
	restart = new Sprite("Resources/SceneContent/Restart.png");

	timer.Start();

	notPlayed = true;
	ended = false;
	phase1 = false;
	phase2 = false;
	phase3 = false;
	phase4 = false;
	phase5 = false;
	phase6 = false;
}

// ------------------------------------------------------------------------------

Delay::~Delay()
{
	delete logo;
	delete gameOver;
	delete restart;
}

// -------------------------------------------------------------------------------

void Delay::Update()
{
	if (notPlayed && timer.Elapsed(0.5f))
	{
		// toca áudio de introdução
		GeoWars::audio->Play(START);
		notPlayed = false;
		ended = false;
	}
	
	if (!phase1 && timer.Elapsed(2.0f))
	{
		// toca música do jogo
		GeoWars::audio->Play(THEME, true);
		GeoWars::viewHUD = true;
		GeoWars::scene->Add(new WaveShuriken(), STATIC);
		phase1 = true;
	}
	
	if (!phase2 && timer.Elapsed(6.0f))
	{
		GeoWars::scene->Add(new WaveArrow(), STATIC);
		phase2 = true;
	}
	
	
	if (!phase3 && timer.Elapsed(8.0f))
	{
		GeoWars::scene->Add(new WaveShip(), STATIC);
		phase3 = true;
	}
	
	if (!phase4 && timer.Elapsed(10.0f))
	{
		GeoWars::scene->Add(new WaveSpikes(), STATIC);
		phase4 = true;
	}
	
	if (!phase5 && timer.Elapsed(12.0f))
	{
		GeoWars::scene->Add(new WaveBoomerang(), STATIC);
		phase5 = true;
	}

	if (!phase6 && timer.Elapsed(15.0f))
	{
		GeoWars::scene->Add(new WaveVirus(), STATIC);
		phase6 = true;
	}

	if (GeoWars::player->lives == 0)
	{
		GeoWars::audio->Frequency(THEME, 0.8f);
		GeoWars::audio->Frequency(SHOT, 0.8f);
		GeoWars::audio->Frequency(SPAWN, 0.8f);
		
		ended = true;

		// Reinicia jogo
		if (window->KeyPress(VK_RETURN))
		{
			GeoWars::audio->Stop(THEME);
			GeoWars::audio->Frequency(THEME, 1);
			GeoWars::audio->Frequency(SHOT, 1);
			GeoWars::audio->Frequency(SPAWN, 1);

			GeoWars::player->killed = false;
			GeoWars::player->speed = new Vector(90.0f, 0.0f);
			GeoWars::player->MoveTo(game->CenterX(), game->CenterY());
			GeoWars::player->lives = 10;

			notPlayed = true;
			phase1 = false;
			phase2 = false;
			phase3 = false;
			phase4 = false;
			phase5 = false;
			phase6 = false;

			Hud::killedArrows = 0;
			Hud::killedBoomerangs = 0;
			Hud::killedShips = 0;
			Hud::killedShurikens = 0;
			Hud::killedSpikes = 0;
			Hud::killedViruses = 0;

			timer.Reset();
		}
	}

	if (GeoWars::player->killed && (killedTimer.Elapsed() == 0))
	{
		killedTimer.Start();
	}

	if ((killedTimer.Elapsed() > 2) && (GeoWars::player->lives != 0))
	{
		GeoWars::player->killed = false;

		killedTimer.Stop();
		killedTimer.Reset();
	}
}

// -------------------------------------------------------------------------------

void Delay::Draw()
{
	if (!phase1)
	{
		logo->Draw(game->viewport.left + window->CenterX() , game->viewport.top + window->CenterY(), Layer::FRONT);
	}

	if (GeoWars::player->lives == 0)
	{
		gameOver->Draw(game->viewport.left + window->CenterX(), game->viewport.top + window->CenterY(), Layer::FRONT);
		restart->Draw(game->viewport.left + window->Width() - 100.0f, game->viewport.top + window->Height() - 45.0f, Layer::FRONT);
	}
}

// -------------------------------------------------------------------------------
