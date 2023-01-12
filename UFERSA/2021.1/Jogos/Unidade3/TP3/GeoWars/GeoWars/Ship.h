/**********************************************************************************
// Ship (Arquivo de Cabe�alho)
// 
// Cria��o:     10 Out 2012
// Atualiza��o: 01 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Objeto faz uma persegui��o suavizada
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
	Vector* speed;							// velocidade e dire��o
	Player* player;							// ponteiro para jogador
	Particles* tail;						// calda da nave
	float factor;							// fator de escala
	
public:
	Ship(float pX, float pY, Player* p);	// construtor
	~Ship();								// destrutor
	
	void OnCollision(Object* obj);			// resolu��o da colis�o
	void Update();							// atualiza��o
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
