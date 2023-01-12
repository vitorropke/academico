/**********************************************************************************
// Home (C�digo Fonte)
//
// Cria��o:     18 Jan 2013
// Atualiza��o: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Tela de fim do jogo Maze
//
**********************************************************************************/

#include "GameOver.h"

#include "Home.h"
#include "Level1.h"

#include "Engine.h"

// ------------------------------------------------------------------------------

void GameOver::Init()
{
	backg = new Sprite("Resources/Screens/GameOver.png");
}

// ------------------------------------------------------------------------------

void GameOver::Finalize()
{
	delete backg;
}

// ------------------------------------------------------------------------------

void GameOver::Update()
{
	if (window->KeyDown(VK_ESCAPE))
	{
		// volta para a tela de abertura
		Engine::Next<Home>();
	}
	else if (window->KeyDown(VK_RETURN))
	{
		// reinicia o primeiro n�vel com ENTER
		Engine::Next<Level1>();
	}
}

// ------------------------------------------------------------------------------

void GameOver::Draw()
{
	backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
}

// ------------------------------------------------------------------------------
