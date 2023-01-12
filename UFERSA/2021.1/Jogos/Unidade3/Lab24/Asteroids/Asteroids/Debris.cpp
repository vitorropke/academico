/**********************************************************************************
// Debris (Código Fonte)
//
// Criação:     07 Fev 2013
// Atualização: 25 Out 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Animação de explosão
//
**********************************************************************************/

#include "Debris.h"
#include "Asteroids.h"

// ---------------------------------------------------------------------------------

Debris::Debris(float posX, float posY)
{
    // configura gerador de partículas
    Generator generator;

    generator.imgFile = "Resources/Particle.png";   // arquivo de imagem
    generator.angle = RandAngle(mt);                // direção das estrelas
    generator.spread = 360.0f;                      // espalhamento em graus
    generator.lifetime = 10.0f;                     // tempo de vida (em segundos)
    generator.frequency = 0.000f;                   // tempo entre geração de novas partículas
    generator.percentToDim = 0.6f;                  // desaparece após 60% da vida
    generator.minSpeed = 25.0f;                     // velocidade mínima das partículas
    generator.maxSpeed = 250.0f;                    // velocidade máxima das partículas
    generator.color.r = 1.0f;                       // proporção de cor vermelha
    generator.color.g = 1.0f;                       // proporção de cor verde
    generator.color.b = 1.0f;                       // proporção de cor azul
    generator.color.a = 1.0f;                       // transparência da partícula

    // cria sistema de partículas
    debris = new Particles(generator);

    // gera 10 partículas na posição do impacto
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
    // atualiza posição de cada partícula
    debris->Update(gameTime);

    if (debris->Inactive())
        Asteroids::scene->Delete();    
}

// ---------------------------------------------------------------------------------