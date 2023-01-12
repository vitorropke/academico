/**********************************************************************************
// GeoWars (Arquivo de Cabeçalho)
// 
// Criação:     23 Out 2012
// Atualização: 01 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Demonstração da versão final do motor
//
**********************************************************************************/

#ifndef _GEOWARS_H_
#define _GEOWARS_H_

// ------------------------------------------------------------------------------

#include "Hud.h"
#include "Player.h"

#include "Audio.h"
#include "Background.h"
#include "Game.h"
#include "Scene.h"

// ------------------------------------------------------------------------------

enum ObjectIds { PLAYER, MISSILE, ARROW, BOOMERANG, SHIP, SHURIKEN, SPIKES, VIRUS, WALLHIT, EXPLOSION };

// ------------------------------------------------------------------------------

enum SoundIds { START, THEME, SHOT, HITWALL, SPAWN, EXPLODE, GAMEOVER };

// ------------------------------------------------------------------------------

class GeoWars : public Game
{
private:
	Background* backg = nullptr;	// pano de fundo
	Hud* hud = nullptr;				// painel de informações
	bool viewBBox = false;			// visualização das bouding boxes

public:
	static Player* player;			// nave controlada pela jogador
	static Audio* audio;			// sitema de áudio
	static Scene* scene;			// cena do jogo
	static bool viewHUD;			// visualização do painel

	void Init();					// inicialização
	void Update();					// atualização
	void Draw();					// desenho
	void Finalize();				// finalização
};

// ---------------------------------------------------------------------------------

#endif
