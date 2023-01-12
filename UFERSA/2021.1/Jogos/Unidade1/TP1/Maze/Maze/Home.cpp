/**********************************************************************************
// Home (Código Fonte) 
// 
// Criação:     18 Jan 2013
// Atualização: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Tela de abertura do jogo Maze
//
**********************************************************************************/

#include "Home.h"

#include "Instructions.h"
#include "Level1.h"

#include "Engine.h"

// ------------------------------------------------------------------------------

void Home::Init()
{
	backg = new Sprite("Resources/Screens/Home.png");
}

// ------------------------------------------------------------------------------

void Home::Finalize()
{
	delete backg;
}

// ------------------------------------------------------------------------------

void Home::Update()
{
	// sai do jogo com a tecla ESC
	if (ctrlKeyESC && window->KeyDown(VK_ESCAPE))
	{
		ctrlKeyESC = false;
		window->Close();
	}
	else if (window->KeyUp(VK_ESCAPE))
	{
		ctrlKeyESC = true;
	}

	// mostra as instruções
	if (window->KeyDown(0x49))
	{
		Engine::Next<Instructions>();
	}

	// inicia o primeiro nível com ENTER
	if (window->KeyDown(VK_RETURN))
	{
		Engine::Next<Level1>();
	}
}

// ------------------------------------------------------------------------------

void Home::Draw()
{
	backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
}

// ------------------------------------------------------------------------------
