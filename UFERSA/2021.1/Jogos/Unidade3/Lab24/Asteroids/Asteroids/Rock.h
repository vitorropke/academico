/**********************************************************************************
// Rock (Arquivo de Cabe�alho)
//
// Cria��o:     18 Mar 2013
// Atualiza��o: 25 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Rocha espacial
//
**********************************************************************************/

#ifndef _ASTEROIDS_ROCK_H_
#define _ASTEROIDS_ROCK_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                          // tipos espec�ficos da engine
#include "Object.h"                         // interface de um objeto
#include "Animation.h"                      // desenha anima��o
#include "TileSet.h"                        // folha de sprites
#include "Vector.h"                         // representa��o de vetores

// n�meros aleat�rios
#include <random>
using std::random_device;
using std::mt19937;
using DistInt = std::uniform_int_distribution<int>;
using DistFlt = std::uniform_real_distribution<float>;

// ---------------------------------------------------------------------------------

class Rock : public Object
{
private:
    static TileSet * tile;                  // tileset das rochas

    Animation * anim;                       // anima��o da rocha
    Vector speed;                           // velocidade da rocha
    uint frame;                             // quadro da folha a ser utilizado
    float spin;                             // delta de rota��o em cada atualiza��o 

    // n�meros aleat�rios
    random_device rd;
    mt19937 mt { rd() };
    DistInt RandFrame { 0, 3 };
    DistFlt RandAngle { 0.0f, 359.0f };
    DistFlt RandFactor { 0.0f, 10.0f };
    DistFlt RandWidth { 0.0f, float(window->Width()) };
    DistFlt RandHeight { 0.0f, float(window->Height()) };

public:
    static uint count;                      // quantidade de rochas criadas

    Rock();                                 // construtor
    ~Rock();                                // destrutor

    void OnCollision(Object * obj);         // resolu��o da colis�o
    void Update();                          // atualiza��o 
    void Draw();                            // desenho
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

inline void Rock::Draw()
{ anim->Draw(frame, x, y, Layer::MIDDLE, scale, rotation); }

// ---------------------------------------------------------------------------------

#endif