/**********************************************************************************
// Platform (Arquivo de Cabeçalho)
// 
// Criação:     21 Abr 2012
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Plataformas do jogo
//
**********************************************************************************/

#ifndef _LAND_THE_BOOSTER_PLATFORM_H_
#define _LAND_THE_BOOSTER_PLATFORM_H_

// ---------------------------------------------------------------------------------

#include "Object.h"							// interface de Object
#include "Sprite.h"							// desenho de sprites
#include "Types.h"							// tipos específicos da engine

// ---------------------------------------------------------------------------------

enum PLATTYPES { GROUND, LAND_ZONE };

// ---------------------------------------------------------------------------------

class Platform : public Object
{
private:
	Sprite* platform = nullptr;				// sprite da plataforma
	Sprite* landIndicator = nullptr;		// sprite do indicador que mostra onde está o local de pouso

public:
	Platform(uint platType);				// construtor    
	~Platform();							// destrutor

	int Width();							// retorna tamanho horizontal da plataforma
	int Height();							// retorna tamanho vertical da plataforma
	
	void Update();							// atualização do objeto
	void Draw();							// desenho do objeto
}; 

// ---------------------------------------------------------------------------------
// Função Membro Inline

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
