/**********************************************************************************
// Fireworks (C�digo Fonte)
// 
// Cria��o:     17 Mar 2013
// Atualiza��o: 27 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Efeito de explos�o usando sistema de part�culas
//
**********************************************************************************/

#include "Refinery.h"
#include "Fireworks.h"

// ---------------------------------------------------------------------------------

Fireworks::Fireworks()
{
    // configura gerador de part�culas
    Generator starmaker;
    starmaker.imgFile = "Resources/Star.png";   // arquivo de imagem
    starmaker.angle = 0.0f;                     // dire��o das estrelas
    starmaker.spread = 10.0f;                   // espalhamento em graus
    starmaker.lifetime = 0.5f;                  // tempo de vida (em segundos)
    starmaker.frequency = 0.000f;               // tempo entre gera��o de novas part�culas
    starmaker.percentToDim = 0.1f;              // desaparece ap�s 10% da vida
    starmaker.minSpeed = 1500.0f;               // velocidade m�nima das part�culas
    starmaker.maxSpeed = 4000.0f;               // velocidade m�xima das part�culas
    starmaker.color.r = 1.0f;                   // cor aleat�ria para part�cula
    starmaker.color.g = 0.5f;                   // cor aleat�ria para part�cula
    starmaker.color.b = 0.5f;                   // cor aleat�ria para part�cula
    starmaker.color.a = 1.0f;                   // transpar�ncia da part�cula

    // cria sistema de part�culas
    starGen = new Particles(starmaker);

    // gera 300 part�culas na posi��o do mouse
    starGen->Generate(window->MouseX(), window->MouseY(), 300);
    type = FIREWORKS;
}

// ---------------------------------------------------------------------------------

Fireworks::~Fireworks()
{
    delete starGen;
}

// -------------------------------------------------------------------------------

void Fireworks::Update()
{
    // atualiza posi��o de cada part�cula
    starGen->Update(gameTime);

    // remove da cena quando todas as part�culas est�o inativas
    if (starGen->Inactive())
        Refinery::scene->Delete();
}

// -------------------------------------------------------------------------------