/**********************************************************************************
// Ship (Arquivo de Cabeçalho)
// 
// Criação:     10 Out 2012
// Atualização: 01 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Objeto faz uma perseguição suavizada
//
**********************************************************************************/

#ifndef _GEOWARS_SHIP_H_
#define _GEOWARS_SHIP_H_

// ---------------------------------------------------------------------------------

#include "Player.h"

#include "Object.h"
#include "Sprite.h"
#include "Types.h"
#include "Vector.h"

// ---------------------------------------------------------------------------------

class Ship : public Object
{
private:
	Sprite* sprite;							// sprite do objeto
	Vector* speed;							// velocidade e direção
	Player* player;							// ponteiro para jogador
	Particles* tail;						// calda da nave
	float factor;							// fator de escala
	
public:
	Ship(float pX, float pY, Player* p);	// construtor
	~Ship();								// destrutor
	
	void OnCollision(Object* obj);			// resolução da colisão
	void Update();							// atualização
	void Draw();							// desenho
}; 

// ---------------------------------------------------------------------------------

inline void Ship::Draw()
{
	sprite->Draw(x, y, Layer::LOWER, scale, -speed->Angle() + 90.0f);
	tail->Draw(Layer::LOWER, 1.0f);
}

// ---------------------------------------------------------------------------------

#endif
