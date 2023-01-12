/**********************************************************************************
// WinGame 
// 
// Criação:     19 Mai 2007
// Atualização: 04 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Um jogo para Windows é uma classe derivada de Game.
//              Crie uma classe derivada e sobrescreva os métodos Init, 
//              Update, Draw e Finalize.
//
**********************************************************************************/

#include "Resources.h"
#include "Engine.h"
#include "Game.h"
#include <random>
#include <sstream>
using std::stringstream;
using namespace std;

// ------------------------------------------------------------------------------

class WinGame : public Game
{
private:
	HDC hdc;
	int xStart, xEnd, yStart, yEnd;
	int speedXStart, speedYStart, speedXEnd, speedYEnd;
	int red, green, blue;

public:
	void Init();
	void Update();
	void Draw();
	void Finalize();
};

// ------------------------------------------------------------------------------

void WinGame::Init() 
{
	hdc = GetDC(window->Id());

	random_device rd;
	mt19937 mt(rd());

	uniform_int_distribution<int> randomXStart(0, window->Width());
	uniform_int_distribution<int> randomYStart(0, window->Height());
	uniform_int_distribution<int> randomXEnd(0, window->Width());
	uniform_int_distribution<int> randomYEnd(0, window->Height());

	uniform_int_distribution<int> randomSpeedXStart(1, 5);
	uniform_int_distribution<int> randomSpeedYStart(1, 5);
	uniform_int_distribution<int> randomSpeedXEnd(1, 5);
	uniform_int_distribution<int> randomSpeedYEnd(1, 5);

	xStart = randomXStart(mt);
	yStart = randomYStart(mt);
	xEnd = randomXEnd(mt);
	yEnd = randomYEnd(mt);

	speedXStart = randomSpeedXStart(mt);
	speedYStart = randomSpeedYStart(mt);
	speedXEnd = randomSpeedXEnd(mt);
	speedYEnd = randomSpeedYEnd(mt);
}

// ------------------------------------------------------------------------------

void WinGame::Update()
{
	if (window->KeyDown(VK_LBUTTON))
		window->Close();

	xStart += speedXStart;
	yStart += speedYStart;
	xEnd += speedXEnd;
	yEnd += speedYEnd;

	random_device rd;
	mt19937 mt(rd());

	uniform_int_distribution<int> randomRed(0, 255);
	uniform_int_distribution<int> randomGreen(0, 255);
	uniform_int_distribution<int> randomBlue(0, 255);

	red = randomRed(mt);
	green = randomGreen(mt);
	blue = randomBlue(mt);

	// Ponto inicial da linha
	if (xStart >= window->Width())
	{
		speedXStart = -speedXStart;
	}
	if (xStart <= 0)
	{
		speedXStart = -speedXStart;
	}
	if (yStart >= window->Height())
	{
		speedYStart = -speedYStart;
	}
	if (yStart <= 0)
	{
		speedYStart = -speedYStart;
	}

	// Ponto final da linha
	if (xEnd >= window->Width())
	{
		speedXEnd = -speedXEnd;
	}
	if (xEnd <= 0)
	{
		speedXEnd = -speedXEnd;
	}
	if (yEnd >= window->Height())
	{
		speedYEnd = -speedYEnd;
	}
	if (yEnd <= 0)
	{
		speedYEnd = -speedYEnd;
	}
} 

// ------------------------------------------------------------------------------

void WinGame::Draw()
{
	// https://cboard.cprogramming.com/windows-programming/101542-movetoex-lineto-functions.html
	HPEN pen, oldPen;

	pen = CreatePen(PS_SOLID, 2, RGB(red, green, blue));
	oldPen = (HPEN)SelectObject(hdc, pen);

	MoveToEx(hdc, xStart, yStart, NULL);
	LineTo(hdc, xEnd, yEnd);

	SelectObject(hdc, oldPen);
	DeleteObject(pen);
}

// ------------------------------------------------------------------------------

void WinGame::Finalize()
{
	ReleaseDC(window->Id(), hdc);
}


// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, 
	                 _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	// cria motor e configura a janela
	Engine * engine = new Engine();
	engine->window->Mode(WINDOWED);
	engine->window->Size(960, 540);
	engine->window->Color(100, 100, 100);
	engine->window->Title("Window Game");
	engine->window->Icon(IDI_ICON);
	engine->window->Cursor(IDC_CURSOR);

	// cria e inicia o jogo
	engine->Start(new WinGame());
}

// ----------------------------------------------------------------------------

