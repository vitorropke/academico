/**********************************************************************************
// Home (Código Fonte)
//
// Criação:     18 Jan 2013
// Atualização: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Tela de abertura do jogo
//
**********************************************************************************/

#include "Instructions.h"

#include "LandTheBooster.h"
#include "Home.h"

#include "Engine.h"

// ------------------------------------------------------------------------------

void Instructions::Init()
{
	backg = new TileSet("Resources/Home/Stars.png", 1280, 720, 7, 59);

	backgAnim = new Animation(backg, 0.07f, false);

	backgAnim->Frame(0);

	instructions = new Sprite("Resources/Instructions/Instructions.png");
}

// ------------------------------------------------------------------------------

void Instructions::Update()
{
	// volta para a tela inicial
	if (window->KeyPress(VK_ESCAPE))
	{
		LandTheBooster::NextLevel<Home>();
	}
}

// ------------------------------------------------------------------------------

void Instructions::Draw()
{
	backgAnim->Draw(window->CenterX(), window->CenterY());
	instructions->Draw(window->CenterX(), window->CenterY());
}

// ------------------------------------------------------------------------------

void Instructions::Finalize()
{
	delete backg;
	delete backgAnim;
	delete instructions;
}

// ------------------------------------------------------------------------------
