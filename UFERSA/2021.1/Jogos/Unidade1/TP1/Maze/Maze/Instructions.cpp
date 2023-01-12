/**********************************************************************************
// Home (C�digo Fonte)
//
// Cria��o:     18 Jan 2013
// Atualiza��o: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Tela de abertura do jogo Maze
//
**********************************************************************************/

#include "Instructions.h"

#include "Home.h"

#include "Engine.h"

// ------------------------------------------------------------------------------

void Instructions::Init()
{
	backg = new Sprite("Resources/Screens/Instructions.png");
}

// ------------------------------------------------------------------------------

void Instructions::Finalize()
{
	delete backg;
}

// ------------------------------------------------------------------------------

void Instructions::Update()
{
	// sai do jogo com a tecla ESC
	if (window->KeyDown(VK_ESCAPE))
	{
		Engine::Next<Home>();
	}
}

// ------------------------------------------------------------------------------

void Instructions::Draw()
{
	backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
}

// ------------------------------------------------------------------------------
