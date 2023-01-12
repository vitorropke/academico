/**********************************************************************************
// Stripes (C�digo Fonte)
//
// Cria��o:     11 Jul 2019
// Atualiza��o: 06 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Faixas brancas da pista
//
**********************************************************************************/

#include "Stripes.h"
#include "TopGear.h"
#include <sstream>
using std::stringstream;

// ---------------------------------------------------------------------------------

Stripes::Stripes() : speed(TopGear::speed)
{
    // carrega imagem das faixas
    lines = new Image("Resources/Stripes.png");

    // cria sprite para as faixas
    sprite = new Sprite(lines);

    // posi��es iniciais das faixas
    pos[0] = 250.0f;  // 0
    pos[1] = 280.0f;  // 30 
    pos[2] = 340.0f;  // 60 
    pos[3] = 460.0f;  // 120

    // �ndice da primeira e �ltima faixa
    first = 0;
    last = 3;

    // Ao longo de 340 pixels (290 da altura da pista + 4 antes + 46 depois da pista)
    // a escala deve ir de 1.0 at� 0.074889. Esse valor foi obtido a partir
    // do c�lculo abaixo, que usa a largura das linhas no final da pista (454 pixels), 
    // e a largura delas no inicio da pista (34 pixels):
    // 
    //   454 * escala = 34, ou seja, escala = 0.074889
    // 
    // Ent�o a varia��o da escala ser� de 0.925110 em 340 pixels. Isso implica em um 
    // acr�scimo de 0.00272091 no valor da escala a cada pixel do eixo Y:
    //
    //    1.0 - 0.074889 = 0.925110
    //    0.925110/340 = 0.00272091
    //
    // Dada uma posi��o "pos" de in�cio do desenho, podemos encontrar a escala
    // correta para esse desenho multiplicando a dist�ncia j� percorrida (em 
    // rela��o a posi��o m�xima do eixo Y) por 0.00272091 e tirando esse resultado
    // da escala original (1.0f)

    // ajusta a escala conforme a posi��o inicial
    for (int i = 0; i < 4; ++i)
        scale[i] = 1.0f - (586.0f - pos[i]) * 0.00272091f;
}

// ---------------------------------------------------------------------------------

Stripes::~Stripes()
{
    delete sprite;
    delete lines;
}

// ---------------------------------------------------------------------------------

void Stripes::Update()
{
    for (int i = 0; i < 4; ++i)
    {
        // deslocamento varia com a escala e a velocidade do carro
        delta[i] = 1.2f * speed * scale[i] * gameTime;

        // desloca faixas
        pos[i] += delta[i];

        // aumenta a escala de acordo com a dist�ncia percorrida
        scale[i] += delta[i] * 0.00272091f;
    }

    // verifica a dist�ncia da primeira faixa para o in�cio da pista
    if (pos[first] - 246.5 >= 30)
    {
        // restaura escala da �ltima faixa para o in�cio da pista
        scale[last] = 0.074889f;

        // posiciona �ltima faixa no in�cio da pista
        pos[last] = 250.0f - (sprite->Height() * scale[last] / 2.0f);

        // a �ltima faixa se tornou a primeira e agora existe uma nova �ltima
        first = last--;

        // trata vetor de forma circular
        if (last < 0)
            last = 3;
    }
}

// -------------------------------------------------------------------------------

void Stripes::Draw()
{
    // desenha linhas usando a escala definida
    for (int i = 0; i < 4; ++i)
        sprite->Draw(window->CenterX(), pos[i], Layer::MIDDLE, scale[i]);
}

// -------------------------------------------------------------------------------