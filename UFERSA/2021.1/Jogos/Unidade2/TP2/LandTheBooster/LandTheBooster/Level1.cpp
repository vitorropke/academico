/**********************************************************************************
// Level1 (Código Fonte) 
// 
// Criação:     14 Fev 2013
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Nível 1 do jogo
//
**********************************************************************************/

#include "Level1.h"

#include "GameOver.h"
#include "LandTheBooster.h"
#include "Home.h"
#include "Platform.h"
#include "Player.h"

// ------------------------------------------------------------------------------
// Inicializa membros estáticos da classe

Scene* Level1::scene = nullptr;

// ------------------------------------------------------------------------------

void Level1::Init()
{
	// cria gerenciador de cena
	scene = new Scene();

	// panos de fundo do jogo
	sky = new Sprite("Resources/Level1/Sky.jpg");
	backgBack = new Sprite("Resources/Level1/BackgBack.png");
	backgFront = new Sprite("Resources/Level1/BackgFront.png");

	// adiciona jogador na cena
	scene->Add(LandTheBooster::player, MOVING);

	// ----------------------
	// plataformas
	// ----------------------

	Platform * plat;

	plat = new Platform(GROUND);
	scene->Add(plat, STATIC);

	plat = new Platform(LAND_ZONE);
	scene->Add(plat, STATIC);
}

// ------------------------------------------------------------------------------

void Level1::Update()
{
	if (window->KeyPress(VK_ESCAPE))
	{
		LandTheBooster::player->Reset();
		LandTheBooster::audio->Play(HOME, true);
		LandTheBooster::NextLevel<Home>();
	}
	else if (LandTheBooster::player->EndExlosion() || (LandTheBooster::player->Top() > window->Height()) ||
		window->KeyPress(VK_RETURN))
	{
		LandTheBooster::player->Reset();
		LandTheBooster::NextLevel<Level1>();
	}
	else if (LandTheBooster::player->Bottom() < 0)
	{
		LandTheBooster::player->Reset();
		LandTheBooster::NextLevel<GameOver>();
	}
	else
	{
		scene->Update();
		scene->CollisionDetection();
	}
}

// ------------------------------------------------------------------------------

void Level1::Draw()
{
	sky->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
	backgBack->Draw(window->CenterX(), window->Height() + 150.0f - LandTheBooster::player->Y() * 0.8f, Layer::BACK);
	backgFront->Draw(window->CenterX(), window->Height() + 550.0f - LandTheBooster::player->Y() * 1.2f, Layer::BACK);

	scene->Draw();

	if (LandTheBooster::viewBBox)
	{
		scene->DrawBBox();
	}
}

// ------------------------------------------------------------------------------

void Level1::Finalize()
{
	scene->Remove(LandTheBooster::player, MOVING);
	delete scene;
	delete sky;
	delete backgBack;
	delete backgFront;
}

// ------------------------------------------------------------------------------
