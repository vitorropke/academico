/**********************************************************************************
// Player (Arquivo de Cabeçalho)
// 
// Criação:     10 Out 2012
// Atualização: 01 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define a classe jogador
//
**********************************************************************************/

#ifndef _GEOWARS_PLAYER_H_
#define _GEOWARS_PLAYER_H_

// ---------------------------------------------------------------------------------

#include "Controller.h"                 // entrada pelo controle
#include "Object.h"						// objetos do jogo
#include "Particles.h"					// sistema de partículas
#include "Sprite.h"						// desenho de sprites
#include "Vector.h"						// representação de vetores

// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
	Sprite* sprite;						// sprite do objeto
	Particles* tail;					// calda do jogador

	Controller* gamepad;				// leitura do controle
	bool gamepadOn;						// controle está ligado

	Timer timer;						// controla tempo dos disparos
	llong start;						// marcação de início do disparo
	bool axisCtrl;						// habilita leitura de disparos
	bool keysCtrl;						// habilita disparos pelas setas
	bool keysPressed;					// qualquer seta pressionada
	float firingAngle;					// direção dos disparos

public:
	bool killed;						// jogador foi morto na rodada

	uint lives;							// vidas do jogador

	Vector* speed;						// velocidade e direção

	Player();							// construtor
	~Player();							// destrutor

	bool AxisTimed(int axisX, int axisY, float time);
	bool KeysTimed(bool pressed, float time);
	
	void Move(Vector&& v);				// movimenta jogador
	void OnCollision(Object* obj);		// resolução da colisão
	void Update();						// atualização
	void Draw();						// desenho
}; 
// ---------------------------------------------------------------------------------

#endif
