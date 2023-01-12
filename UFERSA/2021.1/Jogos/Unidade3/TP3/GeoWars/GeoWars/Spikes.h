/**********************************************************************************
// Green (Arquivo de Cabeçalho)
// 
// Criação:     15 Out 2012
// Atualização: 01 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Objeto faz uma fuga suavizada
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
	Vector* speed;							// velocidade e direção
	Player* player;							// ponteiro para jogador
	int distance;							// mantém distância do jogador
	
public:
	Spikes(float pX, float pY, Player* p);	// construtor
	~Spikes();								// destrutor
	
	void OnCollision(Object* obj);			// resolução da colisão
	void Update();							// atualização
	void Draw();							// desenho
}; 

// ---------------------------------------------------------------------------------

inline void Spikes::Draw()
{
	sprite->Draw(x, y, Layer::LOWER, scale, rotation);
}

// ---------------------------------------------------------------------------------

#endif
