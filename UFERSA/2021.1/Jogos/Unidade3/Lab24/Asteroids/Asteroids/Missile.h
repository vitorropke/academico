/**********************************************************************************
// Missile (Arquivo de Cabe�alho)
// 
// Cria��o:     23 Nov 2011
// Atualiza��o: 25 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define uma classe para um m�ssil/proj�til
//
**********************************************************************************/

#ifndef _ASTEROIDS_MISSILE_H_
#define _ASTEROIDS_MISSILE_H_

// --------------------------------------------------------------------------------

#include "Vector.h"
#include "Object.h"
#include "Sprite.h"
#include "Ship.h" 

// --------------------------------------------------------------------------------

class Missile : public Object
{
private:
    Sprite * sprite;            // sprite do m�ssil
    Vector   speed;             // velocidade do m�ssil
    
public:
    Missile(Ship * ship);       // construtor
    ~Missile();                 // destrutor

    void Update();              // atualiza��o
    void Draw();                // desenho
}; 

// ------------------------------------------------------------------------------

#endif