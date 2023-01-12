/**********************************************************************************
// Boomerang (Arquivo de Cabe�alho)
//
// Cria��o:     05 Ago 2019
// Atualiza��o: 01 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Objeto faz movimentos como se fosse um bumerangue
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

// MOVE		| �ngulo	| Magnitude	| Dura��o
// MOVETO	| PosX		| PosY		| Magnitude
// SLIDE	| �ngulo	| Magnitude	| Dura��o
// SLIDETO	| PosX		| PosY		| Magnitude
// TURN		| �ngulo	| Magnitude	| Dura��o
// ROTATE	| �ngulo	| Magnitude	| Dura��o
// RANDOM	| -			| -			| Dura��o
// JUMP		| Instru��o	| -			| -

enum InstructionTypes
{
	MOVE,			// move em uma dire��o e velocidade por um tempo
	MOVETO,			// move para uma posi��o x, y
	SLIDE,			// o mesmo que MOVE, por�m sem rotacionar
	SLIDETO,		// o mesmo que MOVETO, por�m sem rotacionar
	TURN,			// indica a dire��o que o objeto deve seguir
	ROTATE,			// rotaciona a dire��o do objeto por um tempo
	RANDOM,			// move em uma dire��o aleat�ria por um tempo
	JUMP			// pula para uma instru��o podendo fazer um loop
};

// ---------------------------------------------------------------------------------

class Boomerang : public Object
{
private:
	Sprite* sprite;						// sprite do objeto
	Vector* speed;						// velocidade e dire��o
	RandI randXDirection{ 0, 3840 };	// dire��o aleat�ria X
	RandI randYDirection{ 0, 2160 };	// dire��o aleat�ria Y

	Instruction* script = nullptr;		// vetor de instru��es
	int index = 0;						// �ndice da instru��o atual
	int end = 0;						// �ndice da �ltima instru��o
	float duration = 0.0f;				// dura��o da instru��o atual

	Timer timer;						// timer para instru��es
	RandF angle;						// valor aleat�rio para �ngulo
	RandF magnitude;					// valor aleat�rio para magnitude

public:
	Boomerang(float pX, float pY);		// construtor
	~Boomerang();						// destrutor

	void OnCollision(Object* obj);		// resolu��o da colis�o
	void Update();						// atualiza��o
	void Draw();						// desenho
};

// ---------------------------------------------------------------------------------

inline void Boomerang::Draw()
{
	sprite->Draw(x, y, Layer::LOWER, scale, rotation);
}

// ---------------------------------------------------------------------------------

#endif
