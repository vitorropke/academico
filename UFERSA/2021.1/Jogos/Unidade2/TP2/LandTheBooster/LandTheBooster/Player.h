/**********************************************************************************
// Player (Arquivo de Cabeçalho)
// 
// Criação:     20 Abr 2012
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define uma classe para o jogador 
//
**********************************************************************************/

#ifndef _LAND_THE_BOOSTER_PLAYER_H_
#define _LAND_THE_BOOSTER_PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Animation.h"										// animação de sprites
#include "Font.h"											// fontes para imprimir texto na tela
#include "Object.h"											// interface de Object
#include "Types.h"											// tipos específicos da engine

// ------------------------------------------------------------------------------

enum State { FLIGHT, LANDED };								// estado

// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
	TileSet* rocket = nullptr;								// folha de sprites do personagem
	TileSet* engineExhaust = nullptr;						// folha de psrites da exaustão do motor
	TileSet* rcs = nullptr;									// folha de sprites do RCS
	TileSet* explosion = nullptr;							// folha de sprites do personagem explodindo

	Animation* rocketAnim = nullptr;						// animação do personagem
	Animation* engineExhaustAnim = nullptr;					// animação do personagem
	Animation* rcsAnim = nullptr;							// animaçãos do RCS
	Animation* explosionAnim = nullptr;						// animação do personagem explodindo

	Font* bankGothic = nullptr;								// fonte que mostra a quantidade de combustível

	Sprite* escButton = nullptr;							// botão esc
	Sprite* enterButton = nullptr;							// botão enter

	uint state = FLIGHT;									// estado atual

	Timer landTime;											// controla o tempo após o pouso ou explosão para dar tempo
															// de concluir a animação e o áudio
	
	float verticalSpeed = 1.0f;								// velocidade vertical do jogador
	float lateralSpeed = 0.0f;								// velocidade lateral do jogador

	float fuel = 500.0f;									// combustível do jogador

	float wind = 0.0f;										// vento

	float windRange[2] = { -10.0f, 10.0f };					// limite de velocidade do vento
	float positionXRangeSpawn[2] = { 300.0f, 1000.0f };		// limite da posição horizontal onde o foguete pode spawnar
	
	int level = 0;											// nível finalizado

	bool leftRCSActivated = false;							// RCS esquerdo ligado
	bool rightRCSActivated = false;							// RCS direito ligado
	
	bool engineIgnited = false;								// motor ligado
	bool exploded = false;									// jogador explodiu
	bool landed = false;									// jogador pousou
	
	bool endExplosion = false;								// fim da explosão

public:
	Player();												// construtor
	~Player();												// destrutor

	void Reset();											// volta ao estado inicial
	int Level();											// último nível finalizado
	float Bottom();											// coordenadas da base
	float Top();											// coordenadas do topo
	bool EndExlosion();										// explodiu ou não

	void OnCollision(Object* obj);							// resolução da colisão
	void Update();											// atualização do objeto
	void Draw();											// desenho do objeto
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

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
