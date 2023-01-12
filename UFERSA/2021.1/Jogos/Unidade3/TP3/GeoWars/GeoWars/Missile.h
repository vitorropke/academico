/**********************************************************************************
// Missile (Arquivo de Cabe�alho)
// 
// Cria��o:     23 Nov 2011
// Atualiza��o: 01 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define uma classe para um m�ssil
//
**********************************************************************************/

#ifndef _GEOWARS_MISSILE_H_
#define _GEOWARS_MISSILE_H_

// --------------------------------------------------------------------------------

#include "Player.h" 

#include "Object.h"
#include "Sprite.h"
#include "Vector.h"

// --------------------------------------------------------------------------------

class Missile : public Object
{
private:
	static Player*& player;				// refer�ncia para o player
	Sprite* sprite;						// sprite do m�ssil
	Vector speed;						// velocidade do m�ssil    
	
public:
	Missile(float angle);				// construtor
	~Missile();							// destrutor

	Vector& Speed();					// retorna vetor velocidade
	void Update();						// atualiza��o
	void Draw();						// desenho
}; 

// ------------------------------------------------------------------------------

inline Vector& Missile::Speed()
{
	return speed;
}

inline void Missile::Draw()
{
	sprite->Draw(x, y, Layer::UPPER, scale, rotation);
}

// ------------------------------------------------------------------------------

#endif
