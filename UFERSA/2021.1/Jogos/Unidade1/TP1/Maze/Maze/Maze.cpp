/**********************************************************************************
// Maze (Código Fonte)
// 
// Criação:     01 Jan 2013
// Atualização: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Executor do Maze
//
**********************************************************************************/

#include "Home.h"

#include "Engine.h"
#include "Resources.h"

// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	Engine* engine = new Engine();

	// configura a janela do jogo
	engine->window->Mode(WINDOWED);
	engine->window->Size(960, 720);
	engine->window->Color(128, 128, 128);
	engine->window->Title("Maze");
	engine->window->Icon(IDI_ICON);
	engine->window->Cursor(IDC_CURSOR);

	// configura dispositivo gráfico
	//engine->graphics->VSync(true);
	
	// inicia o jogo
	int status = engine->Start(new Home());

	delete engine;
	return status;
}

// ----------------------------------------------------------------------------
