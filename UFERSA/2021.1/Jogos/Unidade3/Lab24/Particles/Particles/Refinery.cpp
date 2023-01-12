/**********************************************************************************
// Refinery (C�digo Fonte)
//
// Cria��o:     07 Out 2012
// Atualiza��o: 27 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Demonstra��o do sistema de part�culas
//
**********************************************************************************/

#include "Engine.h"
#include "Refinery.h"

// ------------------------------------------------------------------------------

Audio * Refinery::audio = nullptr;            // sistema de �udio
Scene * Refinery::scene = nullptr;            // cena do jogo

// ------------------------------------------------------------------------------

void Refinery::Init()
{
    // cria sistema de �udio
    audio = new Audio();
    audio->Add(MACHINERY, "Resources/Machinery.wav");

    // carrega sprites de fundo e interface
    backg = new Sprite("Resources/Refinery.png");
    overlay = new Sprite("Resources/Overlay.png");
    onoff = new Sprite("Resources/OnOff.png");
    
    // cria gerenciador de cena
    scene = new Scene();

    // cria fontes para exibi��o de texto
    font = new Font("Resources/Tahoma14.png");
    font->Spacing("Resources/Tahoma14.dat");
    bold = new Font("Resources/Tahoma14b.png");
    bold->Spacing("Resources/Tahoma14b.dat");
}

// ------------------------------------------------------------------------------

void Refinery::Update()
{
    // sai com o pressionamento da tecla ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    // cria fogos de artif�cio com o bot�o esquerdo do mouse 
    if (window->KeyPress(VK_LBUTTON))
        scene->Add(new Fireworks(), STATIC);

    // muda entre dia e noite
    if (window->KeyPress('N'))
    {
        nightOn = !nightOn;

        // troca a cor da fuma�a para refletir 
        // a mudan�a na luminosidade do ambiente
        if (smokeOn)
        {
            // remove geradores de fuma�a
            for (const auto & elem : exhausts)
                scene->Delete(elem, STATIC);

            // cria novos geradores de fuma�a
            float ang = smokeAng(mt);
            exhausts[0] = new Smoke(240,  255, ang, nightOn);
            exhausts[1] = new Smoke(380,  312, ang, nightOn);
            exhausts[2] = new Smoke(919,  288, ang, nightOn);
            exhausts[3] = new Smoke(1041, 293, ang, nightOn);
            
            // adiciona geradores de fuma�a na cena
            for (const auto& elem : exhausts)
                scene->Add(elem, STATIC);
        }
    }
    
    // liga ou desliga a refinaria
    if (window->KeyPress('R'))
    {
        if (smokeOn)
        {
            // p�ra o som das m�quinas 
            audio->Stop(MACHINERY);

            // desliga os emissores de fuma�a
            for (const auto& elem : exhausts)
                elem->TurnOff();
        }
        else
        {
            // inicia o som das m�quinas
            audio->Play(MACHINERY, true);

            // cria novos emissores de fuma�a
            float ang = smokeAng(mt);
            exhausts[0] = new Smoke(240,  255, ang, nightOn);
            exhausts[1] = new Smoke(380,  312, ang, nightOn);
            exhausts[2] = new Smoke(919,  288, ang, nightOn);
            exhausts[3] = new Smoke(1041, 293, ang, nightOn);

            // adiciona emissores de fuma�a na cena
            for (const auto& elem : exhausts)
                scene->Add(elem, STATIC);
        }

        // muda estado da refinaria
        smokeOn = !smokeOn;
    }

    // atualiza a cena
    scene->Update();
} 

// ------------------------------------------------------------------------------

void Refinery::Draw()
{
    // desenha pano de fundo e bot�o dia/noite com a cor apropriada
    if (nightOn)
    {
        backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK, 1, 0, Color(0.1f, 0.1f, 0.1f, 1.0f));
        onoff->Draw(797, 634, Layer::BACK, 1, 0, Color(0.0f, 1.0f, 0.0f, 1.0f));
    }
    else
    {
        backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
        onoff->Draw(797, 634, Layer::BACK, 1, 0, Color(0.5f, 0.0f, 0.0f, 1.0f));
    }
    
    // desenha moldura da interface
    overlay->Draw(window->CenterX(), window->CenterY(), Layer::FRONT);

    // desenha bot�o liga/desliga na cor apropriada
    if (smokeOn)
        onoff->Draw(697, 634, Layer::BACK, 1, 0, Color(0.0f, 1.0f, 0.0f, 1.0f));
    else
        onoff->Draw(697, 634, Layer::BACK, 1, 0, Color(0.5f, 0.0f, 0.0f, 1.0f));
    
    // desenha cena
    scene->Draw();
    
    // calcula n�mero de part�culas ativas
    Object * obj = nullptr;
    Smoke * smk = nullptr;
    Fireworks * fir = nullptr;
    int size = 0;
    scene->Begin();    
    while (obj = scene->Next())
    {
        if (obj->Type() == SMOKE)
        {
            smk = static_cast<Smoke*>(obj);
            size += smk->Size();
        }
        else
        {
            fir = static_cast<Fireworks*>(obj);
            size += fir->Size();
        }
    }

    // define cor dos textos
    Color textColor{ 0.85f, 0.85f, 0.85f, 1.0f };
    Color boldColor{ 0.75f, 0.75f, 0.75f, 1.0f };

    // desenha textos
    text.str("");
    text << "Sistema de Part�culas";
    bold->Draw(window->CenterX() - 48, 23, text.str(), boldColor);

    text.str("");
    text << "R     Refinaria";
    font->Draw(window->CenterX() + 134.0f, window->Height() - 6.0f, text.str(), textColor);

    text.str("");
    text << "N     Noturno";
    font->Draw(window->CenterX() + 234.0f, window->Height() - 6.0f, text.str(), textColor);

    text.str("");
    text << "Geradores: " << scene->Size();
    font->Draw(320, window->Height() - 6.0f, text.str(), textColor);

    text.str("");
    text << "Part�culas: " << size;
    font->Draw(420, window->Height() - 6.0f, text.str(), textColor);

    //desenha posi��o do mouse
    text.str("");
    text << window->MouseX() << " x " << window->MouseY();
    font->Draw(65, window->Height() - 6.0f, text.str(), textColor);
}

// ------------------------------------------------------------------------------

void Refinery::Finalize()
{
    delete backg;
    delete overlay;
    delete onoff;
    delete bold;
    delete font;
    delete scene;
    delete audio;
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
    engine->window->Size(1152, 648);
    engine->window->Color(0, 0, 0);
    engine->window->Title("Particles");
    engine->window->Icon(IDI_ICON);
    engine->window->Cursor(IDC_CURSOR);
    //engine->graphics->VSync(true);

    // inicia o jogo
    int status = engine->Start(new Refinery());

    delete engine;
    return status;
}

// ----------------------------------------------------------------------------

