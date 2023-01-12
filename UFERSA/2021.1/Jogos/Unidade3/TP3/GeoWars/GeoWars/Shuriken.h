/**********************************************************************************
// Shuriken (Arquivo de Cabe�alho)
// 
// Cria��o:     05 Ago 2019
// Atualiza��o: 01 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Objeto faz movimento retil�neo
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
	Vector* speed;								// velocidade e dire��o
	Player* player;								// ponteiro para jogador
	float multiplier;							// multiplicador da velocidade
	float rotationVelocity = 200.0f;			// velocidade de rota��o da shuriken
	
public:
	Shuriken(float pX, float pY, Player* p);	// construtor
	~Shuriken();								// destrutor
	
	void OnCollision(Object* obj);				// resolu��o da colis�o
	void Update();								// atualiza��o
	void Draw();								// desenho
}; 

// ---------------------------------------------------------------------------------

inline void Shuriken::Draw()
{
	sprite->Draw(x, y, Layer::LOWER, scale, rotation);
}

// ---------------------------------------------------------------------------------

#endif
