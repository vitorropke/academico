/**********************************************************************************
// Green (Arquivo de Cabe�alho)
// 
// Cria��o:     15 Out 2012
// Atualiza��o: 01 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Objeto faz uma fuga suavizada
//
**********************************************************************************/

#ifndef _GEOWARS_SPIKES_H_
#define _GEOWARS_SPIKES_H_

// ---------------------------------------------------------------------------------

#include "Player.h"

#include "Object.h"
#include "Sprite.h"
#include "Types.h"
#include "Vector.h"

// ---------------------------------------------------------------------------------

class Spikes : public Object
{
private:
	Sprite* sprite;							// sprite do objeto
	Vector* speed;							// velocidade e dire��o
	Player* player;							// ponteiro para jogador
	int distance;							// mant�m dist�ncia do jogador
	
public:
	Spikes(float pX, float pY, Player* p);	// construtor
	~Spikes();								// destrutor
	
	void OnCollision(Object* obj);			// resolu��o da colis�o
	void Update();							// atualiza��o
	void Draw();							// desenho
}; 

// ---------------------------------------------------------------------------------

inline void Spikes::Draw()
{
	sprite->Draw(x, y, Layer::LOWER, scale, rotation);
}

// ---------------------------------------------------------------------------------

#endif
