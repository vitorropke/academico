/**********************************************************************************
// Mouse (Arquivo de Cabe�alho)
// 
// Cria��o:     27 Jul 2019
// Atualiza��o: 25 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Gerencia mouse na tela
//
**********************************************************************************/

#ifndef _COLLISIONT_MOUSE_H_
#define _COLLISIONT_MOUSE_H_

// ---------------------------------------------------------------------------------

#include "Object.h"        
#include "Types.h"        

// ---------------------------------------------------------------------------------

class Mouse : public Object
{
public:
    Mouse();                            // construtor
    ~Mouse();                           // destrutor

    void OnCollision(Object* obj);      // resolu��o de colis�o
    void Update();                      // atualiza��o
    void Draw();                        // desenho
}; 

// ---------------------------------------------------------------------------------

#endif