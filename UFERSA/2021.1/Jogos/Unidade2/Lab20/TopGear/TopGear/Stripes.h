/**********************************************************************************
// Stripes (Arquivo de Cabe�alho)
//
// Cria��o:     11 Jul 2019
// Atualiza��o: 06 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Faixas brancas da pista
//
**********************************************************************************/

#ifndef _TOPGEAR_STRIPES_H_
#define _TOPGEAR_STRIPES_H_

// ---------------------------------------------------------------------------------

#include "Object.h"                             // objetos do jogo 
#include "Image.h"                              // carrega imagens
#include "Sprite.h"                             // desenho de sprites
#include "Types.h"                              // tipos espec�ficos do motor

// ---------------------------------------------------------------------------------

class Stripes : public Object
{
private:
    Image * lines;                              // imagem das faixas brancas
    Sprite * sprite;                            // sprite das faixas brancas
    
    int first;                                  // �ndice da primeira faixa
    int last;                                   // �ndice da �ltima faixa
    float pos[4] = {0};                         // posi��o das faixas
    float scale[4] = {0};                       // escala de desenho
    float delta[4] = {0};                       // valor do deslocamento
    float & speed;                              // velocidade do carro

public:
    Stripes();                                  // construtor
    ~Stripes();                                 // destrutor

    void Update();                              // atualiza��o
    void Draw();                                // desenho
};

// ---------------------------------------------------------------------------------

#endif
