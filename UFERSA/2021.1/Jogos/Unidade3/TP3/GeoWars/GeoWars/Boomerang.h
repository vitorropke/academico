/**********************************************************************************
// Boomerang (Arquivo de Cabeçalho)
//
// Criação:     05 Ago 2019
// Atualização: 01 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Objeto faz movimentos como se fosse um bumerangue
//
**********************************************************************************/

#ifndef _GEOWARS_BOOMERANG_H_
#define _GEOWARS_BOOMERANG_H_

// ---------------------------------------------------------------------------------

#include "Player.h"

#include "Object.h"
#include "Sprite.h"
#include "Types.h"
#include "Vector.h"

// ---------------------------------------------------------------------------------

struct Instruction
{
	int instruction;
	float angle;
	float magnitude;
	float duration;
};

// MOVE		| Ângulo	| Magnitude	| Duração
// MOVETO	| PosX		| PosY		| Magnitude
// SLIDE	| Ângulo	| Magnitude	| Duração
// SLIDETO	| PosX		| PosY		| Magnitude
// TURN		| Ângulo	| Magnitude	| Duração
// ROTATE	| Ângulo	| Magnitude	| Duração
// RANDOM	| -			| -			| Duração
// JUMP		| Instrução	| -			| -

enum InstructionTypes
{
	MOVE,			// move em uma direção e velocidade por um tempo
	MOVETO,			// move para uma posição x, y
	SLIDE,			// o mesmo que MOVE, porém sem rotacionar
	SLIDETO,		// o mesmo que MOVETO, porém sem rotacionar
	TURN,			// indica a direção que o objeto deve seguir
	ROTATE,			// rotaciona a direção do objeto por um tempo
	RANDOM,			// move em uma direção aleatória por um tempo
	JUMP			// pula para uma instrução podendo fazer um loop
};

// ---------------------------------------------------------------------------------

class Boomerang : public Object
{
private:
	Sprite* sprite;						// sprite do objeto
	Vector* speed;						// velocidade e direção
	RandI randXDirection{ 0, 3840 };	// direção aleatória X
	RandI randYDirection{ 0, 2160 };	// direção aleatória Y

	Instruction* script = nullptr;		// vetor de instruções
	int index = 0;						// índice da instrução atual
	int end = 0;						// índice da última instrução
	float duration = 0.0f;				// duração da instrução atual

	Timer timer;						// timer para instruções
	RandF angle;						// valor aleatório para ângulo
	RandF magnitude;					// valor aleatório para magnitude

public:
	Boomerang(float pX, float pY);		// construtor
	~Boomerang();						// destrutor

	void OnCollision(Object* obj);		// resolução da colisão
	void Update();						// atualização
	void Draw();						// desenho
};

// ---------------------------------------------------------------------------------

inline void Boomerang::Draw()
{
	sprite->Draw(x, y, Layer::LOWER, scale, rotation);
}

// ---------------------------------------------------------------------------------

#endif
