/**********************************************************************************
// Platform (Arquivo de Cabe�alho)
// 
// Cria��o:     21 Abr 2012
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Plataformas do jogo
//
**********************************************************************************/

#ifndef _LAND_THE_BOOSTER_PLATFORM_H_
#define _LAND_THE_BOOSTER_PLATFORM_H_

// ---------------------------------------------------------------------------------

#include "Object.h"							// interface de Object
#include "Sprite.h"							// desenho de sprites
#include "Types.h"							// tipos espec�ficos da engine

// ---------------------------------------------------------------------------------

enum PLATTYPES { GROUND, LAND_ZONE };

// ---------------------------------------------------------------------------------

class Platform : public Object
{
private:
	Sprite* platform = nullptr;				// sprite da plataforma
	Sprite* landIndicator = nullptr;		// sprite do indicador que mostra onde est� o local de pouso

public:
	Platform(uint platType);				// construtor    
	~Platform();							// destrutor

	int Width();							// retorna tamanho horizontal da plataforma
	int Height();							// retorna tamanho vertical da plataforma
	
	void Update();							// atualiza��o do objeto
	void Draw();							// desenho do objeto
}; 

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

inline int Platform::Width()
{
	return platform->Width();
}

inline int Platform::Height()
{
	return platform->Height();
}

// ---------------------------------------------------------------------------------

#endif
