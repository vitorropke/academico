/**********************************************************************************
// Object (C�digo Fonte)
//
// Cria��o:     14 Out 2022
// Atualiza��o: 14 Out 2022
// Compilador:  Visual C++ 2022
//
// Descri��o:   Define classe para um objeto de uma cena
//
**********************************************************************************/

#include "Object.h"

Object::Object()
{
    // inicializa com a matriz identidade
    world = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f };

    cbIndex = -1;
}

// ------------------------------------------------------------------------------