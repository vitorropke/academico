/**********************************************************************************
// Platform (Código Fonte)
// 
// Criação:     21 Abr 2012
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Plataformas do jogo
//
**********************************************************************************/

#include "Platform.h"

#include "LandTheBooster.h"

// ---------------------------------------------------------------------------------

Platform::Platform(uint platType)
{
	switch (platType)
	{
	case GROUND:
		type = GROUND;
		platform = new Sprite("Resources/Platform/Grass.png");
		BBox(new Rect(-10000, 3, 10000, platform->Height() / 2.0f));
		break;

	case LAND_ZONE:
		type = LAND_ZONE;
		platform = new Sprite("Resources/Platform/LandingZone.png");
		BBox(new Rect(-platform->Width() / 2.0f,
			0.0f,
			platform->Width() / 2.0f,
			platform->Height() / 2.0f));
		break;
	}

	landIndicator = new Sprite("Resources/Platform/LandIndicator.png");
}

// ---------------------------------------------------------------------------------

Platform::~Platform()
{
	delete platform;
	delete landIndicator;
}

// -------------------------------------------------------------------------------

void Platform::Update()
{
	// move plataforma no eixo y
	MoveTo(window->CenterX(), window->Height() + 650 - LandTheBooster::player->Y() * 1.5f);
}

// -------------------------------------------------------------------------------

void Platform::Draw()
{
	platform->Draw(x, y, z);

	if (LAND_ZONE && ((y - platform->Height() / 2.0f) > window->Height()))
	{
		landIndicator->Draw(x, window->Height() - 130.0f, Layer::FRONT);
	}
}

// -------------------------------------------------------------------------------
