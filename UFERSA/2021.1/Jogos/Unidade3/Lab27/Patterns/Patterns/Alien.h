/**********************************************************************************
// Alien (Arquivo de Cabe�alho)
// 
// Cria��o:     25 Mar 2013
// Atualiza��o: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Executa scripts com padr�es de movimenta��o
//
**********************************************************************************/

#ifndef _PATTERNS_ALIEN_H_
#define _PATTERNS_ALIEN_H_

// ---------------------------------------------------------------------------------

#include "Object.h"    
#include "Types.h"
#include "Sprite.h"
#include "TileSet.h"
#include "Animation.h"
#include "Vector.h"
#include "Timer.h"
#include "Player.h"
#include "Random.h"

// --------------------------------------------------------------------------------

struct Instruction
{
    int instruction;
    float angle;
    float magnitude;
    float duration;
};

// MOVE      | �ngulo    | Magnitude | Dura��o
// MOVETO    | PosX      | PosY      | Magnitude
// SLIDE     | �ngulo    | Magnitude | Dura��o
// SLIDETO   | PosX      | PosY      | Magnitude
// TURN      | �ngulo    | Magnitude | Dura��o
// ROTATE    | �ngulo    | Magnitude | Dura��o
// RANDOM    | -         | -         | Dura��o
// JUMP      | Instru��o | -         | -

enum InstructionTypes 
{
    MOVE,           // move em uma dire��o e velocidade por um tempo
    MOVETO,         // move para uma posi��o x, y
    SLIDE,          // o mesmo que MOVE, por�m sem rotacionar
    SLIDETO,        // o mesmo que MOVETO, por�m sem rotacionar
    TURN,           // indica a dire��o que o objeto deve seguir
    ROTATE,         // rotaciona a dire��o do objeto por um tempo
    RANDOM,         // move em uma dire��o aleat�ria por um tempo
    JUMP            // pula para uma instru��o podendo fazer um loop
};

// ---------------------------------------------------------------------------------

class Alien : public Object
{
private:
    TileSet * alienSet;                 // tileset do objeto
    Animation * anim;                   // anima��o do objeto
    Vector speed;                       // velocidade e dire��o
    
    Instruction * script;               // vetor de instru��es
    int index;                          // �ndice da instru��o atual
    int end;                            // �ndice da �ltima instru��o
    float duration;                     // dura��o da instru��o atual
    
    Timer timer;                        // timer para instru��es
    RandF angle;                        // valor aleat�rio para �ngulo
    RandF magnitude;                    // valor aleat�rio para magnitude
    
public:
    Alien(uint alien, Instruction * vet, int tam, float pX, float pY);    
    ~Alien();
    
    void OnCollision(Object * obj);     // resolu��o da colis�o
    void Update();                      // atualiza��o
    void Draw();                        // desenho
}; 

// ---------------------------------------------------------------------------------

inline void Alien::Draw()
{ anim->Draw(x, y, Layer::MIDDLE, scale, rotation ); }

// ---------------------------------------------------------------------------------


#endif