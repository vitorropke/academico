/**********************************************************************************
// Cars (C�digo Fonte)
//
// Cria��o:     14 Jul 2019
// Atualiza��o: 06 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Carros advers�rios
//
**********************************************************************************/

#include "Cars.h"

// ---------------------------------------------------------------------------------

Cars::Cars() 
{
    // cria sprite para o carro
    sprite = new Sprite("Resources/WhiteCar.png");

    // deslocamentos no eixo X e Y
    deltaX = 0;
    deltaY = 0;

    // velocidade inicial do carro
    speed = 100;

    // --- ajuste a posi��o inicial do carro ---
    MoveTo(window->CenterX(), 246);

    // --- ajuste a escala inicial do carro ---
    ScaleTo(0.1f);
}

// ---------------------------------------------------------------------------------

Cars::~Cars()
{
    delete sprite;
}

// ---------------------------------------------------------------------------------

void Cars::Update()
{
    // deslocamento varia com a escala e a velocidade
    deltaY = speed * scale * gameTime;

    // desloca carro
    Translate(deltaX, deltaY);

    // --- aumente a escala de acordo com a dist�ncia percorrida ---
    ScaleTo(scale + deltaY * 0.00396475f);
    
    // verifica a dist�ncia do carro para o in�cio da pista
    if (y - 246 >= 500)
    {
        // restaura posi��o e escala do in�cio da pista
        ScaleTo(0.1f);
        MoveTo(window->CenterX(), 246);
    }
}

// -------------------------------------------------------------------------------

void Cars::Draw()
{
    // --- desenha carro usando a escala definida ---
    sprite->Draw(x, y, Layer::UPPER, scale);
}

// -------------------------------------------------------------------------------