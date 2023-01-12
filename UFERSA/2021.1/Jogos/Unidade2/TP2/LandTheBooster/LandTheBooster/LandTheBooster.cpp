/**********************************************************************************
// LandTheBooster (Código Fonte)
// 
// Criação:     05 Out 2011
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Jogo estilo plataforma usando a engine do curso
//
**********************************************************************************/

#include "LandTheBooster.h"

#include "GameOver.h"
#include "Home.h"

#include "Engine.h"

// ------------------------------------------------------------------------------

// inicializa membros estáticos da classe
Game* LandTheBooster::level = nullptr;
Player* LandTheBooster::player = nullptr;
Audio* LandTheBooster::audio = nullptr;
bool LandTheBooster::viewBBox = false;

// ------------------------------------------------------------------------------

void LandTheBooster::Init()
{
	// cria sistema de áudio
	audio = new Audio();
	
	audio->Add(HOME, "Resources/Sounds/Home.wav");
	audio->Add(ENGINE, "Resources/Sounds/Engine.wav");
	audio->Add(RCS, "Resources/Sounds/RCS.wav", 2);
	audio->Add(EXPLOSION, "Resources/Sounds/Explosion.wav");
	audio->Add(CHEERS, "Resources/Sounds/Cheers.wav");
	audio->Add(GAME_OVER, "Resources/Sounds/GameOver.wav");

	audio->Volume(HOME, 0.7f);
	audio->Volume(ENGINE, 0.2f);
	audio->Volume(RCS, 0.4f);
	audio->Volume(EXPLOSION, 1.2f);
	audio->Volume(GAME_OVER, 0.7f);

	// bounding box não visível
	viewBBox = false;

	// cria jogador
	player = new Player();

	// inicializa nível de abertura do jogo
	level = new Home();
	level->Init();

	LandTheBooster::audio->Play(HOME, true);
}

// ------------------------------------------------------------------------------

void LandTheBooster::Update()
{
	// habilita/desabilita visualização da bounding box
	if (window->KeyPress('B'))
	{
		viewBBox = !viewBBox;
	}

	// atualiza nível
	level->Update();
} 

// ------------------------------------------------------------------------------

void LandTheBooster::Draw()
{
	// desenha nível
	level->Draw();
} 

// ------------------------------------------------------------------------------

void LandTheBooster::Finalize()
{
	level->Finalize();

	delete player;
	delete audio;
	delete level;
}

// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	Engine * engine = new Engine();

	// configura o motor
	engine->window->Mode(WINDOWED);
	engine->window->Size(1280, 720);
	engine->window->Color(30, 50, 80);
	engine->window->Title("Land The Booster");
	engine->window->Icon(IDI_ICON);
	engine->window->Cursor(IDC_CURSOR);
	//engine->graphics->VSync(true);

	// inicia o jogo
	int status = engine->Start(new LandTheBooster());

	delete engine;
	return status;
}

// ----------------------------------------------------------------------------
