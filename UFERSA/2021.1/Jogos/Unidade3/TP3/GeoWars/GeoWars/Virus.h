/**********************************************************************************
// V�rus (Arquivo de Cabe�alho)
//
// Cria��o:     05 Ago 2019
// Atualiza��o: 01 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Objeto faz movimento aleat�rio
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
	Vector* speed;						// velocidade e dire��o
	Timer time;							// tempo para mudar de dire��o e criar novos v�rus
	int milestone = 10;					// momento ap�s in�cio do jogo onde se deve criar novos v�rus
	RandI randXDirection{ 0, 3840 };	// dire��o aleat�ria X
	RandI randYDirection{ 0, 2160 };	// dire��o aleat�ria Y

public:
	Virus(float corX, float corY);		// construtor
	~Virus();							// destrutor

	void OnCollision(Object* obj);		// resolu��o da colis�o
	void Update();						// atualiza��o
	void Draw();						// desenho
};

// ---------------------------------------------------------------------------------

inline void Virus::Draw()
{
	sprite->Draw(x, y, Layer::LOWER, scale, rotation);
}

// ---------------------------------------------------------------------------------

#endif
