/**********************************************************************************
// Hud (Código Fonte)
//
// Criação:     02 Ago 2019
// Atualização: 01 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Heads Up Display
//
**********************************************************************************/

#include "Hud.h"

#include "GeoWars.h"

// ------------------------------------------------------------------------------

// inicializa contadores
uint Hud::missiles = 0;
uint Hud::arrows = 0;
uint Hud::boomerangs = 0;
uint Hud::ships = 0;
uint Hud::shurikens = 0;
uint Hud::spikes = 0;
uint Hud::viruses = 0;

uint Hud::killedArrows = 0;
uint Hud::killedBoomerangs = 0;
uint Hud::killedShips = 0;
uint Hud::killedShurikens = 0;
uint Hud::killedSpikes = 0;
uint Hud::killedViruses = 0;

// ------------------------------------------------------------------------------

Hud::Hud()
{
	// cria fonte para exibição de texto
	font = new Font("Resources/Fonts/Tahoma14.png");
	font->Spacing("Resources/Fonts/Tahoma14.dat");
	bold = new Font("Resources/Fonts/Tahoma14b.png");
	bold->Spacing("Resources/Fonts/Tahoma14b.dat");

	// carrega sprites
	infoBox = new Sprite("Resources/SceneContent/InfoBox.png");
	keyMap = new Sprite("Resources/SceneContent/Comandos.png");
	killStatus = new Sprite("Resources/SceneContent/KillStatus.png");
}

// ------------------------------------------------------------------------------

Hud::~Hud()
{
	delete font;
	delete bold;
	delete infoBox;
	delete keyMap;
	delete killStatus;
}

// -------------------------------------------------------------------------------

void Hud::Update()
{

}

// -------------------------------------------------------------------------------

void Hud::Draw()
{
	// desenha elementos da interface
	infoBox->Draw(game->viewport.left + 140, game->viewport.top + 110, Layer::FRONT);
	keyMap->Draw(game->viewport.left + window->CenterX(), game->viewport.top + window->Height() - 45.0f, Layer::FRONT);
	killStatus->Draw(game->viewport.left + window->CenterX(), game->viewport.top + 22.0f, Layer::FRONT);

	// define cor do texto
	Color textColor{ 0.7f, 0.7f, 0.7f, 1.0f };

	// desenha texto
	text.str("");
	text << "Geometry Wars";
	bold->Draw(40, 62, text.str(), textColor);

	text.str("");
	text << "Janela: " << window->Width() << " x " << window->Height();
	font->Draw(40, 92, text.str(), textColor);

	text.str("");
	text << "Mundo: " << game->Width() << " x " << game->Height();
	font->Draw(40, 112, text.str(), textColor);

	text.str("");
	text << "Viewport: (" << uint(game->viewport.left) << "," << uint(game->viewport.top) << ") a (" << uint(game->viewport.right) << "," << uint(game->viewport.bottom) << ")";
	font->Draw(40, 132, text.str(), textColor);

	text.str("");
	text << "Inimigos: " << arrows + boomerangs + ships + shurikens + spikes + viruses;
	font->Draw(40, 152, text.str(), textColor);

	text.str("");
	text << "Mísseis: " << missiles;
	font->Draw(40, 172, text.str(), textColor);

	text.str("");
	text << "Vidas: " << GeoWars::player->lives;
	font->Draw(40, 192, text.str(), textColor);

	text.str("");
	text << "Kills";
	font->Draw(window->CenterX(), 20, text.str(), textColor);

	text.str("");
	text << "Flechas: " << killedArrows;
	font->Draw(350, 40, text.str(), textColor);

	text.str("");
	text << "Bumerangues: " << killedBoomerangs;
	font->Draw(480, 40, text.str(), textColor);

	text.str("");
	text << "Naves: " << killedShips;
	font->Draw(650, 40, text.str(), textColor);

	text.str("");
	text << "Shurikens: " << killedShurikens;
	font->Draw(800, 40, text.str(), textColor);

	text.str("");
	text << "Espigões: " << killedSpikes;
	font->Draw(950, 40, text.str(), textColor);

	text.str("");
	text << "Vírus: " << killedViruses;
	font->Draw(1100, 40, text.str(), textColor);
}

// -------------------------------------------------------------------------------
