/**********************************************************************************
// Missile (Arquivo de Cabeçalho)
// 
// Criação:     23 Nov 2011
// Atualização: 01 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define uma classe para um míssil
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
	static Player*& player;				// referência para o player
	Sprite* sprite;						// sprite do míssil
	Vector speed;						// velocidade do míssil    
	
public:
	Missile(float angle);				// construtor
	~Missile();							// destrutor

	Vector& Speed();					// retorna vetor velocidade
	void Update();						// atualização
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
