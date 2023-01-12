/**********************************************************************************
// Refinery (Arquivo de Cabe�alho)
//
// Cria��o:     07 Out 2012
// Atualiza��o: 27 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Demonstra��o do sistema de part�culas
//
**********************************************************************************/

#ifndef _REFINERY_H_
#define _REFINERY_H_

// ------------------------------------------------------------------------------

#include "Game.h"
#include "Sprite.h"
#include "Audio.h"
#include "Scene.h"
#include "Font.h"
#include "Resources.h"         
#include "Smoke.h"
#include "Fireworks.h"
#include <sstream>
#include <random>

// ---------------------------------------------------------------------------------

using std::stringstream;
using std::random_device;
using std::uniform_real_distribution;
using std::mt19937;
using Rnd = uniform_real_distribution<float>;

// ------------------------------------------------------------------------------

enum ObjectTypes  { SMOKE, FIREWORKS };
enum SoundIds { MACHINERY };

// ------------------------------------------------------------------------------

class Refinery : public Game
{
private:
    Sprite * backg = nullptr;       // pano de fundo
    Sprite * overlay = nullptr;     // moldura da interface
    Sprite * onoff = nullptr;       // indica��o de ligado/desligado
    Smoke  * exhausts[4] = {0};     // exaustores de fuma�a
    Font   * font = nullptr;        // fonte normal
    Font   * bold = nullptr;        // fonte negrito

    bool smokeOn = false;           // estado da refinaria
    bool nightOn = false;           // estado da ilumina��o

    stringstream text;              // texto tempor�rio
    random_device rd;               // gerador aleat�rio para a semente
    mt19937 mt { rd() };            // gerador pseudoaleat�rio de n�meros
    Rnd smokeAng { 30, 150 };       // faixa de valores aleat�rios para o �ngulo

public:
    static Audio * audio;           // sistema de �udio
    static Scene * scene;           // cena do jogo

    void Init();                    // inicializa��o
    void Update();                  // atualiza��o
    void Draw();                    // desenho
    void Finalize();                // finaliza��o
};

// ---------------------------------------------------------------------------------

#endif