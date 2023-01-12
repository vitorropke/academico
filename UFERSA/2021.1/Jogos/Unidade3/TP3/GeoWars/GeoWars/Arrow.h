/**********************************************************************************
// Arrow (Arquivo de Cabe�alho)
// 
// Cria��o:     10 Out 2012
// Atualiza��o: 01 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Objeto faz persegui��o direta
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
	Vector* speed;							// velocidade e dire��o
	Player* player;							// ponteiro para jogador
	
public:
	Arrow(float pX, float pY, Player* p);	// construtor
	~Arrow();								// destrutor
	
	void OnCollision(Object* obj);			// resolu��o da colis�o
	void Update();							// atualiza��o
	void Draw();							// desenho
}; 

// ---------------------------------------------------------------------------------

inline void Arrow::Draw()
{
	sprite->Draw(x, y, Layer::LOWER, scale, -speed->Angle() + 90.0f);
}

// ---------------------------------------------------------------------------------

#endif
