/**********************************************************************************
// Shuriken (Arquivo de Cabeçalho)
// 
// Criação:     05 Ago 2019
// Atualização: 01 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Objeto faz movimento retilíneo
//
**********************************************************************************/

#ifndef _GEOWARS_SHURIKEN_H_
#define _GEOWARS_SHURIKEN_H_

// ---------------------------------------------------------------------------------

#include "Player.h"

#include "Object.h"
#include "Sprite.h"
#include "Types.h"
#include "Vector.h"

// ---------------------------------------------------------------------------------

class Shuriken : public Object
{
private:
	Sprite* sprite;								// sprite do objeto
	Vector* speed;								// velocidade e direção
	Player* player;								// ponteiro para jogador
	float multiplier;							// multiplicador da velocidade
	float rotationVelocity = 200.0f;			// velocidade de rotação da shuriken
	
public:
	Shuriken(float pX, float pY, Player* p);	// construtor
	~Shuriken();								// destrutor
	
	void OnCollision(Object* obj);				// resolução da colisão
	void Update();								// atualização
	void Draw();								// desenho
}; 

// ---------------------------------------------------------------------------------

inline void Shuriken::Draw()
{
	sprite->Draw(x, y, Layer::LOWER, scale, rotation);
}

// ---------------------------------------------------------------------------------

#endif
