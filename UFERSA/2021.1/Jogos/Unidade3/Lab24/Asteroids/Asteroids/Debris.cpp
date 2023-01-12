/**********************************************************************************
// Debris (C�digo Fonte)
//
// Cria��o:     07 Fev 2013
// Atualiza��o: 25 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Anima��o de explos�o
//
**********************************************************************************/

#include "Debris.h"
#include "Asteroids.h"

// ---------------------------------------------------------------------------------

Debris::Debris(float posX, float posY)
{
    // configura gerador de part�culas
    Generator generator;

    generator.imgFile = "Resources/Particle.png";   // arquivo de imagem
    generator.angle = RandAngle(mt);                // dire��o das estrelas
    generator.spread = 360.0f;                      // espalhamento em graus
    generator.lifetime = 10.0f;                     // tempo de vida (em segundos)
    generator.frequency = 0.000f;                   // tempo entre gera��o de novas part�culas
    generator.percentToDim = 0.6f;                  // desaparece ap�s 60% da vida
    generator.minSpeed = 25.0f;                     // velocidade m�nima das part�culas
    generator.maxSpeed = 250.0f;                    // velocidade m�xima das part�culas
    generator.color.r = 1.0f;                       // propor��o de cor vermelha
    generator.color.g = 1.0f;                       // propor��o de cor verde
    generator.color.b = 1.0f;                       // propor��o de cor azul
    generator.color.a = 1.0f;                       // transpar�ncia da part�cula

    // cria sistema de part�culas
    debris = new Particles(generator);

    // gera 10 part�culas na posi��o do impacto
    debris->Generate(posX, posY, 10);
}

// ---------------------------------------------------------------------------------

Debris::~Debris()
{
    delete debris;
}

// ---------------------------------------------------------------------------------

void Debris::Update()
{
    // atualiza posi��o de cada part�cula
    debris->Update(gameTime);

    if (debris->Inactive())
        Asteroids::scene->Delete();    
}

// ---------------------------------------------------------------------------------