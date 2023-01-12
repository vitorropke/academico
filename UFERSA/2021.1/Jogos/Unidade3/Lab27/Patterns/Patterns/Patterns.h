/**********************************************************************************
// Patterns (Arquivo de Cabe�alho)
// 
// Cria��o:     17 Out 2012
// Atualiza��o: 10 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Aplica��o de padr�es e scripts em jogos
//
**********************************************************************************/

#ifndef _PATTERNS_H_
#define _PATTERNS_H_

// ------------------------------------------------------------------------------

enum { MUSIC, ALIEN1, ALIEN2, ALIEN3, ALIEN4, PLAYER, MISSILE };

// ------------------------------------------------------------------------------

#include "Game.h"                   // defini��o de um game
#include "Scene.h"                  // defini��o da cena do jogo
#include "Audio.h"                  // sistema de �udio
#include "Sprite.h"                 // desenho de sprites
#include "Resources.h"              // recursos utilizados no jogo
#include "Player.h"                 // defini��o do jogador
#include "Alien.h"                  // defin��o do inimigo
#include "Backg.h"                  // pano de fundo din�mico
#include <sstream>                  // sa�da para strings
using std::stringstream;    

// ------------------------------------------------------------------------------

class Patterns : public Game
{
private:
    Instruction script[10] = {0};   // script de movimento
    bool viewBBox = false;          // visualiza bounding box
    stringstream text;              // texto tempor�rio

public:
    static Audio * audio;           // gerenciador de �udio
    static Scene * scene;           // gerenciador de cena

    void Init();                    // inicializa��o
    void Update();                  // atualiza��o
    void Draw();                    // desenho
    void Finalize();                // finaliza��o
};

// ---------------------------------------------------------------------------------

#endif