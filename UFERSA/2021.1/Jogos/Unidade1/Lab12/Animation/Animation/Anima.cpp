/**********************************************************************************
// Animation
// 
// Criação:     10 Abr 2012
// Atualização: 27 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Exemplo de uso da classe Animation
//
**********************************************************************************/

#include "Anima.h"
#include "Engine.h"
#include "Resources.h"

// ------------------------------------------------------------------------------

Scene* Anima::scene = nullptr;

// ------------------------------------------------------------------------------

void Anima::Init()
{
    scene = new Scene();
    backg = new Sprite("Resources/Background.jpg");
    
    tilesetExplosion = new TileSet("Resources/Explosion.png", 192, 192, 5, 10);
    tilesetFire = new TileSet("Resources/Fire.png", 64, 64, 10, 60);
    tilesetRun = new TileSet("Resources/Run.png", 180, 248, 5, 10);

    fire = new Fire(tilesetFire);
    fire->MoveTo(window->CenterX(), window->CenterY() - 145.0f);
    scene->Add(fire, STATIC);

    explosion = new Explosion(tilesetExplosion);
    explosion->MoveTo(window->CenterX(), window->CenterY() - 140.0f);
    scene->Add(explosion, STATIC);

    run = new Run(tilesetRun);
    run->MoveTo(0, window->CenterY() + 140.0f);
    scene->Add(run, STATIC);
}

// ------------------------------------------------------------------------------

void Anima::Update()
{
    // sai com o pressionamento do ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    // atualiza animação
    scene->Update();
} 

// ------------------------------------------------------------------------------

void Anima::Draw()
{
    backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
    scene->Draw();
} 

// ------------------------------------------------------------------------------

void Anima::Finalize()
{
    delete backg;

    delete tilesetExplosion;
    delete tilesetFire;
    delete tilesetRun;

    delete scene;
}


// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, 
                     _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    Engine * engine = new Engine();

    // configura janela
    engine->window->Mode(WINDOWED);
    engine->window->Size(960, 540);
    engine->window->Color(0, 0, 0);
    engine->window->Title("Animation");
    engine->window->Icon(IDI_ICON);

    // configura dispositivo gráfico
    //engine->graphics->VSync(true);
    
    // inicia o jogo
    int status = engine->Start(new Anima());

    delete engine;
    return status;
}

// ----------------------------------------------------------------------------

