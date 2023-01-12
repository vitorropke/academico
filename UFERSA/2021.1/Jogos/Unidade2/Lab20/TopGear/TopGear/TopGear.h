/**********************************************************************************
// TopGear (Arquivo de Cabe�alho)
//
// Cria��o:     11 Jul 2019
// Atualiza��o: 06 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Uso da escala em um jogo estilo TopGear
//
**********************************************************************************/

#ifndef _TOPGEAR_H_
#define _TOPGEAR_H_

// ---------------------------------------------------------------------------------

#include "Game.h"
#include "Image.h"
#include "Sprite.h"
#include "Scene.h"
#include "Audio.h"
#include "Resources.h"

// ------------------------------------------------------------------------------

enum SoundIds { MUSIC, ENGINE, COLLISION };

// ------------------------------------------------------------------------------

class TopGear : public Game
{
private:
    Scene * scene = nullptr;            // gerenciador de cena
    Sprite * sky = nullptr;             // desenho do c�u
    Sprite * track = nullptr;           // desenho da pista

    bool viewBBox = false;              // visualiza��o da bbox

public:
    static Audio * audio;               // gerenciador de �udio
    static float speed;                 // velocidade do carro

    void Init();                        // inicializa��o
    void Update();                      // atualiza��o
    void Draw();                        // desenho
    void Finalize();                    // finaliza��o
};

// ---------------------------------------------------------------------------------

#endif