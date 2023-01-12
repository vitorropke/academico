/**********************************************************************************
// Arrow (Arquivo de Cabeçalho)
// 
// Criação:     10 Out 2012
// Atualização: 01 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Objeto faz perseguição direta
//
**********************************************************************************/

#ifndef _GEOWARS_ARROW_H_
#define _GEOWARS_ARROW_H_

// ---------------------------------------------------------------------------------

#include "Player.h"

#include "Object.h"
#include "Sprite.h"
#include "Types.h"
#include "Vector.h"

// ---------------------------------------------------------------------------------

class Arrow : public Object
{
private:
	Sprite* sprite;							// sprite do objeto
	Vector* speed;							// velocidade e direção
	Player* player;							// ponteiro para jogador
	
public:
	Arrow(float pX, float pY, Player* p);	// construtor
	~Arrow();								// destrutor
	
	void OnCollision(Object* obj);			// resolução da colisão
	void Update();							// atualização
	void Draw();							// desenho
}; 

// ---------------------------------------------------------------------------------

inline void Arrow::Draw()
{
	sprite->Draw(x, y, Layer::LOWER, scale, -speed->Angle() + 90.0f);
}

// ---------------------------------------------------------------------------------

#endif
