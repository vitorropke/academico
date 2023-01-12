/**********************************************************************************
// Vírus (Arquivo de Cabeçalho)
//
// Criação:     05 Ago 2019
// Atualização: 01 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Objeto faz movimento aleatório
//
**********************************************************************************/

#ifndef _GEOWARS_VIRUS_H_
#define _GEOWARS_VIRUS_H_

// ---------------------------------------------------------------------------------

#include "Player.h"

#include "Object.h"    
#include "Sprite.h"
#include "Types.h"
#include "Vector.h"

// ---------------------------------------------------------------------------------

class Virus : public Object
{
private:
	Sprite* sprite;						// sprite do objeto
	Vector* speed;						// velocidade e direção
	Timer time;							// tempo para mudar de direção e criar novos vírus
	int milestone = 10;					// momento após início do jogo onde se deve criar novos vírus
	RandI randXDirection{ 0, 3840 };	// direção aleatória X
	RandI randYDirection{ 0, 2160 };	// direção aleatória Y

public:
	Virus(float corX, float corY);		// construtor
	~Virus();							// destrutor

	void OnCollision(Object* obj);		// resolução da colisão
	void Update();						// atualização
	void Draw();						// desenho
};

// ---------------------------------------------------------------------------------

inline void Virus::Draw()
{
	sprite->Draw(x, y, Layer::LOWER, scale, rotation);
}

// ---------------------------------------------------------------------------------

#endif
