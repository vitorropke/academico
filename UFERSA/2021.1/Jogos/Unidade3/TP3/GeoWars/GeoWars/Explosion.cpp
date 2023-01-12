/**********************************************************************************
// Explosion (Código Fonte)
//
// Criação:     17 Mar 2013
// Atualização: 15 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Efeito de explosão usando sistema de partículas
//
**********************************************************************************/

#include "Explosion.h"

#include "GeoWars.h"
#include "Hud.h"

#include "Random.h"

// ---------------------------------------------------------------------------------

Explosion::Explosion(float pX, float pY)
{
	// número aleatório entre 0 e 1
	RandF color{ 0, 1 };

	// configura emissor de partículas
	Generator explosion;
	explosion.imgFile = "Resources/Spark.png";		// arquivo de imagem
	explosion.angle = 0.0f;							// direção da explosão
	explosion.spread = 360.0f;						// espalhamento em graus
	explosion.lifetime = 1.5f;						// tempo de vida em segundos
	explosion.frequency = 0.0f;						// tempo entre geração de novas partículas
	explosion.percentToDim = 0.8f;					// desaparece após 60% da vida
	explosion.minSpeed = 25.0f;						// velocidade mínima das partículas
	explosion.maxSpeed = 250.0f;					// velocidade máxima das partículas
	explosion.color.r = color.Rand();				// cor da partícula entre 0 e 1
	explosion.color.g = color.Rand();				// cor da partícula entre 0 e 1
	explosion.color.b = color.Rand();				// cor da partícula entre 0 e 1
	explosion.color.a = 1.0f;						// transparência da partícula

	// cria sistema de partículas
	sparks = new Particles(explosion);

	// gera 50 partículas na posição indicada
	sparks->Generate(pX, pY, 50);
	type = EXPLOSION;
}

// ---------------------------------------------------------------------------------

Explosion::~Explosion()
{
	delete sparks;
}

// -------------------------------------------------------------------------------

void Explosion::Update()
{
	// atualiza posição de cada partícula
	sparks->Update(gameTime);

	// remove da cena quando todas as partículas estão inativas
	if (sparks->Inactive())
	{
		GeoWars::scene->Delete();
	}
}

// -------------------------------------------------------------------------------
