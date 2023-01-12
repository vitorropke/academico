/**********************************************************************************
// GameOver (Arquivo de Cabeçalho)
// 
// Criação:     14 Fev 2013
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Fim do jogo
//
**********************************************************************************/

#include "GameOver.h"

#include "LandTheBooster.h"
#include "Level1.h"
#include "Home.h"

#include "Engine.h"

// ----------------------------------------------------------------------

void GameOver::Init()
{
	backg = new TileSet("Resources/GameOver/Stars.png", 1280, 720, 9, 75);
	rocket = new TileSet("Resources/Player/Rocket.png", 126, 275, 9, 43);
	
	backgAnim = new Animation(backg, 0.06f, true);
	rocketAnim = new Animation(rocket, 0.05f, false);

	rocketAnim->Frame(24);

	text = new Sprite("Resources/GameOver/Text.png");
	escButton = new Sprite("Resources/Player/EscButton.png");
	enterButton = new Sprite("Resources/Player/EnterButton.png");

	LandTheBooster::audio->Play(GAME_OVER, false);
}

// ----------------------------------------------------------------------

void GameOver::Update()
{
	if (window->KeyPress(VK_ESCAPE))
	{
		LandTheBooster::audio->Stop(GAME_OVER);
		LandTheBooster::audio->Play(HOME, true);
		LandTheBooster::NextLevel<Home>();
	}
	else if (window->KeyPress(VK_RETURN))
	{
		LandTheBooster::audio->Stop(GAME_OVER);
		LandTheBooster::NextLevel<Level1>();
	}
	else
	{
		backgAnim->NextFrame();
		rocketXPosition += 50.0f * gameTime;
	}
}

// ----------------------------------------------------------------------

void GameOver::Draw()
{
	backgAnim->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
	rocketAnim->Draw(rocketXPosition, window->CenterY());
	text->Draw(window->CenterX(), window->CenterY());
	escButton->Draw(300.0f, window->Height() - 50.0f);
	enterButton->Draw(window->Width() - 250.0f, window->Height() - 50.0f);
}

// ----------------------------------------------------------------------

void GameOver::Finalize()
{
	delete backg;
	delete backgAnim;
	delete rocket;
	delete rocketAnim;
	delete text;
	delete escButton;
	delete enterButton;
}

// ----------------------------------------------------------------------
