/**********************************************************************************
// TimerDXUT (Código Fonte)
//
// Criação:		16 Jan 2020
// Atualização:	31 Jul 2021
// Compilador:	Visual C++ 2019
//
// Descrição:	Testa as funcionalidades de animação do motor DXUT
//
**********************************************************************************/

#include "DXUT.h"

// ------------------------------------------------------------------------------

class WinApp : public App
{
private:
	HDC hdc;

	int startX, startY, endX, endY, speedXStart, speedYStart, speedXEnd, speedYEnd;

public:
	void Init();
	void Update();
	void Draw();
	void Finalize();
};

// ------------------------------------------------------------------------------

void WinApp::Init()
{
	hdc = GetDC(window->Id());

	startX = 0;
	startY = 0;

	endX = window->CenterX();
	endY = window->CenterY();

	speedXStart = 10;
	speedYStart = 10;

	speedXEnd = 10;
	speedYEnd = 10;
}

// ------------------------------------------------------------------------------

void WinApp::Update()
{
	// sai com o pressionamento da tecla ESC
	if (input->KeyPress(VK_ESCAPE))
		window->Close();

	startX += speedXStart;
	startY += speedYStart;

	endX += speedXEnd;
	endY += speedYEnd;

	// Mantém o ponto inicial da linha na tela
	if (startX >= window->Width()) {
		speedXStart = -speedXStart;
	}
	else if (startX <= 0) {
		speedXStart = -speedXStart;
	}

	if (startY >= window->Height()) {
		speedYStart = -speedYStart;
	}
	else if (startY <= 0) {
		speedYStart = -speedYStart;
	}

	// Mantém o ponto final da linha na tela
	if (endX >= window->Width()) {
		speedXEnd = -speedXEnd;
	}
	else if (endX <= 0) {
		speedXEnd = -speedXEnd;
	}

	if (endY >= window->Height()) {
		speedYEnd = -speedYEnd;
	}
	else if (endY <= 0) {
		speedYEnd = -speedYEnd;
	}
}

// ------------------------------------------------------------------------------

void WinApp::Draw()
{
	window->Clear();

	MoveToEx(
		hdc,	// contexto do dispositivo
		startX,	// posição inicial no eixo x
		startY,	// posição inicial no eixo y
		NULL	// guarda última coordenada em um POINT
	);

	LineTo(
		hdc,	// contexto do dispositivo
		endX,	// posição final no eixo x
		endY	// posição final no eixo y
	);
}

// ------------------------------------------------------------------------------

void WinApp::Finalize()
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
	Engine* engine = new Engine();
	engine->window->Mode(WINDOWED);
	engine->window->Size(1024, 600);
	engine->window->Color(0, 122, 204);
	engine->window->Title("Timer DXUT");
	engine->window->Icon(IDI_ICON);
	engine->window->Cursor(IDC_CURSOR);

	// cria e executa a aplicação
	int exitCode = engine->Start(new WinApp());

	// finaliza execução
	delete engine;
	return exitCode;
}

// ----------------------------------------------------------------------------

