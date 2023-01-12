/**********************************************************************************
// Jump (C�digo Fonte)
//
// Cria��o:     10 Jul 2019
// Atualiza��o: 30 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Exerc�cio de uso da classe Controller
//
**********************************************************************************/

#include "Engine.h"
#include "Jump.h"

// ------------------------------------------------------------------------------

void Jump::Init()
{
    // carrega sprites e cria anima��o
    braidSet = new TileSet("Resources/Braid.png", 120, 140, 9, 9);
    anim = new Animation(braidSet, 0.250f, false);
    dot = new Sprite("Resources/Dot.png");

    // carrega controle
    controller = new Controller();
    controller->Initialize();

    // posi��o inicial do personagem
    posX = window->CenterX() - 100.0f;
    posY = window->CenterY() + 50.0f;
}

// ------------------------------------------------------------------------------

void Jump::Update()
{
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    // se personagem est� pulando
    if (jumping)
    {
        if (dotTimer.Elapsed(0.1f))
        {
            // adiciona coordenada atual no rastro
            trail.insert(trail.end(), { posX - 40, posY + 70 });
            dotTimer.Reset();
        }

        if (jumpTimer.Elapsed(2.5f))
        {
            // restaura personagem ao estado inicial
            jumping = false;
            posX = oldX;
            posY = oldY;
            anim->Restart();
            trail.clear();
        }
        else if (jumpTimer.Elapsed(2.0f))
        {
            // finaliza pulo
            velX = 0;
            velY = 0;
        }
        else
        {
            anim->NextFrame();

            if (jumpTimer.Elapsed(1.0f))
            {
                // descida
                velY += 100.0f * gameTime;
            }
            else
            {
                // subida
                velY += 100.0f * gameTime;
            }
        }
    }
    else
    {
        // verifica quais bot�es est�o pressionados e a posi��o dos eixos
        controller->UpdateState();

        // no meu controle o bot�o 'X' � o 2
        if (window->KeyPress(VK_SPACE) || controller->ButtonDown(2))
        {
            // inicia pulo
            velX = 100;
            velY = -100;
            
            // adiciona coordenada atual no rastro
            trail.insert(trail.end(), { posX - 40, posY + 70 });
            
            // salva posi��o atual
            oldX = posX;
            oldY = posY;

            // inicia temporizadores
            jumpTimer.Start();
            dotTimer.Start();
            jumping = true;
        }

        posX += controller->Axis(AxisX) * gameTime;
        posY += controller->Axis(AxisY) * gameTime;

        if (window->KeyDown(VK_LEFT))
            posX -= 200 * gameTime;
        if (window->KeyDown(VK_RIGHT))
            posX += 200 * gameTime;
        if (window->KeyDown(VK_UP))
            posY -= 200 * gameTime;
        if (window->KeyDown(VK_DOWN))
            posY += 200 * gameTime;
    }
    
    // atualiza posi��o do personagem 
    posX += velX * gameTime;
    posY += velY * gameTime;
} 

// ------------------------------------------------------------------------------

void Jump::Draw()
{
    // desenha personagem
    anim->Draw(posX, posY);

    // desenha rastro
    for (const auto& [x, y] : trail)
        dot->Draw(x, y);
} 

// ------------------------------------------------------------------------------

void Jump::Finalize()
{
    delete dot;
    delete anim;
    delete braidSet;
    delete controller;
}

// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, 
                     _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
     Engine * engine = new Engine();

    // configura motor
    engine->window->Mode(WINDOWED);
    engine->window->Size(960, 540);
    engine->window->Color(20, 20, 20);
    engine->window->Title("Jump");
    engine->window->Icon(IDI_ICON);
    engine->window->Cursor(IDC_CURSOR);
    //engine->graphics->VSync(true);

    // inicia o jogo
    int status = engine->Start(new Jump());

    delete engine;
    return status;
}

// ----------------------------------------------------------------------------

