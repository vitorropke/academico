/**********************************************************************************
// Platformer (Código Fonte)
//
// Criação:     05 Out 2011
// Atualização: 02 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Exemplo de jogo estilo platforma
//
**********************************************************************************/

#include "Engine.h"
#include "Platformer.h"
#include "Resources.h"

// -----------------------------------------------------------------------------

Scene * Platformer::scene = nullptr;

// -----------------------------------------------------------------------------

void Platformer::Init()
{
    // cria cena do jogo
    scene = new Scene();

    // pano de fundo do jogo
    backg = new Background();
    scene->Add(backg, STATIC);

    // criar e adicionar player na cena
    player = new Player();
    scene->Add(player, MOVING);

    // criar e adicionar plataformas na cena
    platform = new Platform(window->CenterX() + 380, window->CenterY(), LARGE);
    scene->Add(platform, STATIC);

    platform = new Platform(1200, 50, MEDIUM);
    scene->Add(platform, STATIC);

    platform = new Platform(1600, window->CenterY(), MEDIUM);
    scene->Add(platform, STATIC);

    platform = new Platform(2000, 10, LARGE);
    scene->Add(platform, STATIC);

    platform = new Platform(2100, window->CenterY(), SMALL);
    scene->Add(platform, STATIC);

    platform = new Platform(2500, window->CenterY() + 50, SMALL);
    scene->Add(platform, STATIC);

    platform = new Platform(2600, 10, SMALL);
    scene->Add(platform, STATIC);

    platform = new Platform(2700, window->CenterY(), SMALL);
    scene->Add(platform, STATIC);

    platform = new Platform(2850, window->CenterY() + 100, MEDIUM);
    scene->Add(platform, STATIC);
}

// ------------------------------------------------------------------------------

void Platformer::Update()
{
    // sai com o pressionar do ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    // atualiza cena do jogo
    scene->Update();
    scene->CollisionDetection();

    // detecta se o jogador caiu pra cima(?) ou pra baixo
    if (((player->Y() - (player->sizeYBBox() / 2)) > window->Height()) || ((player->Y() + (player->sizeYBBox() / 2)) < 0))
    {
        Engine::Next<Platformer>();
    }
} 

// ------------------------------------------------------------------------------

void Platformer::Draw()
{
    scene->Draw();
    //scene->DrawBBox();
} 

// ------------------------------------------------------------------------------

void Platformer::Finalize()
{
    delete scene;
}


// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, 
                    _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    Engine * engine = new Engine();

    // configura o motor do jogo
    engine->window->Mode(WINDOWED);
    engine->window->Size(600, 300);
    engine->window->Color(150, 200, 230);
    engine->window->Title("Platformer");
    engine->window->Icon(IDI_ICON);
    engine->window->Cursor(IDC_CURSOR);
    //engine->graphics->VSync(true);
    
    // inicia o jogo
    int status = engine->Start(new Platformer());

    delete engine;
    return status;
}

// ----------------------------------------------------------------------------

