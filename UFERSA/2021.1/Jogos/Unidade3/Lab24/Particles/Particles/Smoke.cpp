/**********************************************************************************
// Smoke (C�digo Fonte)
// 
// Cria��o:     17 Mar 2013
// Atualiza��o: 27 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Efeito de fuma�a usando sistema de part�culas
//
**********************************************************************************/

#include "Smoke.h"
#include "Refinery.h"

// ---------------------------------------------------------------------------------

Smoke::Smoke(float pX, float pY, float angle, bool night)
{
    // configura gerador de part�culas
    Generator fogger;
    fogger.imgFile   = "Resources/Smoke.png";    // arquivo de imagem
    fogger.angle     = angle;                    // dire��o da fuma�a
    fogger.spread    = 30;                       // espalhamento em graus
    fogger.lifetime  = 1.0f;                     // tempo de vida em segundos
    fogger.frequency   = 0.010f;                 // tempo entre gera��o de novas part�culas
    fogger.percentToDim = 0.60f;                 // desaparece ap�s 60% da vida
    fogger.minSpeed  = 75.0f;                    // velocidade m�nima das part�culas
    fogger.maxSpeed  = 100.0f;                   // velocidade m�xima das part�culas

    // cor da part�cula depende da ilumina��o
    if (night)
    {
        fogger.color.r = 0.2f;                   // cor da part�cula
        fogger.color.g = 0.2f;                   // cor da part�cula
        fogger.color.b = 0.2f;                   // cor da part�cula
        fogger.color.a = 1.0f;                   // cor da part�cula
    }
    else
    {
        fogger.color.r = 1.0f;                   // cor da part�cula
        fogger.color.g = 1.0f;                   // cor da part�cula
        fogger.color.b = 1.0f;                   // cor da part�cula
        fogger.color.a = 1.0f;                   // cor da part�cula
    }

    // cria sistema de part�culas
    smokeGen = new Particles(fogger);
    MoveTo(pX, pY);
    stop = false;
    type = SMOKE;
}

// ---------------------------------------------------------------------------------

Smoke::~Smoke()
{
    delete smokeGen;
}

// -------------------------------------------------------------------------------

void Smoke::TurnOff()
{
    stop = true;
}

// -------------------------------------------------------------------------------

void Smoke::Update()
{
    if (stop)
    {
        if (smokeGen->Inactive())
            Refinery::scene->Delete();
    }
    else
    {
        smokeGen->Generate(x, y);
    }

    smokeGen->Update(gameTime);
}

// -------------------------------------------------------------------------------
