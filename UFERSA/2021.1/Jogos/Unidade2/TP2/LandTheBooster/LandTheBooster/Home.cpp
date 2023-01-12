/**********************************************************************************
// Home (Código Fonte) 
// 
// Criação:     14 Fev 2013
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Tela de abertura do jogo
//
**********************************************************************************/

#include "Home.h"

#include "Instructions.h"
#include "LandTheBooster.h"
#include "Level1.h"

#include "Engine.h"

// ------------------------------------------------------------------------------

void Home::Init()
{
	backg = new TileSet("Resources/Home/Stars.png", 1280, 720, 7, 59);
	
	backgAnim = new Animation(backg, 0.07f, true);
	
	logo = new Sprite("Resources/Home/Logo.png");

	escButton = new Sprite("Resources/Home/EscButton.png");
	iButton = new Sprite("Resources/Home/IButton.png");
	enterButton = new Sprite("Resources/Home/EnterButton.png");
}

// ------------------------------------------------------------------------------

void Home::Update()
{
	// sai com o pressionar do ESC
	if (window->KeyPress(VK_ESCAPE))
	{
		window->Close();
	}
	
	// se a tecla ENTER for pressionada
	if (window->KeyPress(VK_RETURN))
	{
		LandTheBooster::audio->Stop(HOME);
		LandTheBooster::NextLevel<Level1>();
	}
	// se a tecla I for pressionada
	else if (window->KeyPress('I'))
	{
		window->KeyPress(VK_RETURN);
		LandTheBooster::NextLevel<Instructions>();
	}
	else
	{
		backgAnim->NextFrame();
	}
}

// ------------------------------------------------------------------------------

void Home::Draw()
{
	backgAnim->Draw(window->CenterX(), window->CenterY());
	logo->Draw(window->CenterX(), window->CenterY() - 100.0f);
	escButton->Draw(220.0f, window->Height() - 50.0f);
	iButton->Draw(window->CenterX() - 50.0f, window->Height() - 50.0f);
	enterButton->Draw(window->Width() - 250.0f, window->Height() - 50.0f);
}

// ------------------------------------------------------------------------------

void Home::Finalize()
{
	delete backg;
	delete backgAnim;
	delete logo;
	delete escButton;
	delete iButton;
	delete enterButton;
}

// ------------------------------------------------------------------------------
