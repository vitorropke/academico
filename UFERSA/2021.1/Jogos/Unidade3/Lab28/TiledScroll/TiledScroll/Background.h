/**********************************************************************************
// Background (Arquivo de Cabe�alho)
// 
// Cria��o:     07 Dez 2011
// Atualiza��o: 12 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Representa um pano de fundo maior que a janela
//
**********************************************************************************/

#ifndef _PROGJOGOS_BACKGROUND_H_
#define _PROGJOGOS_BACKGROUND_H_

// -------------------------------------------------------------------------------

#include "Types.h"                      // tipos espec�ficos da engine
#include "Image.h"                      // carregamento de imagens
#include "Sprite.h"                     // desenho de sprites
#include <string>                       // biblioteca string da STL
using std::string;                      // permite usar string sem std::

// -------------------------------------------------------------------------------

class Background
{
private:
    SpriteData spriteData;              // informa��es do sprite 
    const Image * image;                // imagem de fundo
    bool localImage;                    // imagem local ou externa

public:
    Background(string filename);        // construtor padr�o
    Background(const Image* img);       // construtor a partir de imagem
    ~Background();                      // destrutor

    void Draw(ViewPort & sourceRect);   // desenha uma por��o da imagem 
    float Width();                      // retorna a largura do pano de fundo
    float Height();                     // retorna a altura do pano de fundo
}; 

// ---------------------------------------------------------------------------------

// retorna a largura do sprite
inline float Background::Width()
{ return float(image->Width()); }

// retorna a altura do sprite
inline float Background::Height()
{ return float(image->Height()); }

// -------------------------------------------------------------------------------


#endif