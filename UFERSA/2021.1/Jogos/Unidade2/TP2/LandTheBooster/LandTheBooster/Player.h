/**********************************************************************************
// Player (Arquivo de Cabe�alho)
// 
// Cria��o:     20 Abr 2012
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define uma classe para o jogador 
//
**********************************************************************************/

#ifndef _LAND_THE_BOOSTER_PLAYER_H_
#define _LAND_THE_BOOSTER_PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Animation.h"										// anima��o de sprites
#include "Font.h"											// fontes para imprimir texto na tela
#include "Object.h"											// interface de Object
#include "Types.h"											// tipos espec�ficos da engine

// ------------------------------------------------------------------------------

enum State { FLIGHT, LANDED };								// estado

// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
	TileSet* rocket = nullptr;								// folha de sprites do personagem
	TileSet* engineExhaust = nullptr;						// folha de psrites da exaust�o do motor
	TileSet* rcs = nullptr;									// folha de sprites do RCS
	TileSet* explosion = nullptr;							// folha de sprites do personagem explodindo

	Animation* rocketAnim = nullptr;						// anima��o do personagem
	Animation* engineExhaustAnim = nullptr;					// anima��o do personagem
	Animation* rcsAnim = nullptr;							// anima��os do RCS
	Animation* explosionAnim = nullptr;						// anima��o do personagem explodindo

	Font* bankGothic = nullptr;								// fonte que mostra a quantidade de combust�vel

	Sprite* escButton = nullptr;							// bot�o esc
	Sprite* enterButton = nullptr;							// bot�o enter

	uint state = FLIGHT;									// estado atual

	Timer landTime;											// controla o tempo ap�s o pouso ou explos�o para dar tempo
															// de concluir a anima��o e o �udio
	
	float verticalSpeed = 1.0f;								// velocidade vertical do jogador
	float lateralSpeed = 0.0f;								// velocidade lateral do jogador

	float fuel = 500.0f;									// combust�vel do jogador

	float wind = 0.0f;										// vento

	float windRange[2] = { -10.0f, 10.0f };					// limite de velocidade do vento
	float positionXRangeSpawn[2] = { 300.0f, 1000.0f };		// limite da posi��o horizontal onde o foguete pode spawnar
	
	int level = 0;											// n�vel finalizado

	bool leftRCSActivated = false;							// RCS esquerdo ligado
	bool rightRCSActivated = false;							// RCS direito ligado
	
	bool engineIgnited = false;								// motor ligado
	bool exploded = false;									// jogador explodiu
	bool landed = false;									// jogador pousou
	
	bool endExplosion = false;								// fim da explos�o

public:
	Player();												// construtor
	~Player();												// destrutor

	void Reset();											// volta ao estado inicial
	int Level();											// �ltimo n�vel finalizado
	float Bottom();											// coordenadas da base
	float Top();											// coordenadas do topo
	bool EndExlosion();										// explodiu ou n�o

	void OnCollision(Object* obj);							// resolu��o da colis�o
	void Update();											// atualiza��o do objeto
	void Draw();											// desenho do objeto
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

inline int Player::Level()
{
	return level;
}

inline float Player::Bottom()
{
	return y + rocket->TileHeight();
}

inline float Player::Top()
{
	return y - rocket->TileHeight();
}

inline bool Player::EndExlosion()
{
	return endExplosion;
}

// ---------------------------------------------------------------------------------

#endif
