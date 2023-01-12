/**********************************************************************************
// HellowWindow
// 
// Cria��o:     06 Mai 2011
// Atualiza��o: 24 Jul 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Esqueleto b�sico de cria��o de uma janela no Windows 
//              usando a API Win32. Este esqueleto pode ser usado como ponto
//              de partida para cria��o de qualquer aplica��o.
//
**********************************************************************************/

// inclui tipos b�sicos e fun��es da API Win32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <windowsx.h>   // extens�es do windows
#include "Resources.h"  // identificadores de recursos

// prot�tipo do procedimento da janela
LRESULT CALLBACK WinProc (HWND, UINT, WPARAM, LPARAM);

//--------------------------------------------------------------------------------

// programa principal
int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
     HWND hwnd;            // identificador da janela
     MSG msg;              // mensagem
     WNDCLASS wndclass;    // classe da janela

     // Definindo uma classe de janela chamada "BasicWindow" 
     wndclass.style         = CS_HREDRAW | CS_VREDRAW;
     wndclass.lpfnWndProc   = WinProc;
     wndclass.cbClsExtra    = 0;
     wndclass.cbWndExtra    = 0;
     wndclass.hInstance     = hInstance;
     wndclass.hIcon         = LoadIcon (hInstance, MAKEINTRESOURCE(IDI_ICON));
     wndclass.hCursor       = LoadCursor (hInstance, MAKEINTRESOURCE(IDC_CURSOR));
     wndclass.hbrBackground = (HBRUSH) GetStockObject (GRAY_BRUSH);
     wndclass.lpszMenuName  = NULL;
     wndclass.lpszClassName = "BasicWindow";

     // Registrando a classe "BasicWindow"
     if (!RegisterClass (&wndclass))
     {
          MessageBox (NULL, "Erro na cria��o da janela!", "Aplica��o", MB_ICONERROR);
          return 0 ;
     }

     int windowWidth;
     int windowHeight;

     // tamanho da janela igual ao tamanho da tela
     //windowWidth = GetSystemMetrics(SM_CXSCREEN);
     //windowHeight = GetSystemMetrics(SM_CYSCREEN);
     
     // tamanho da janela fixo
     windowWidth = 960;
     windowHeight = 540;

     // usado para centralizar janela na tela
     int windowPosX = GetSystemMetrics(SM_CXSCREEN) / 2 - windowWidth / 2;
     int windowPosY = GetSystemMetrics(SM_CYSCREEN) / 2 - windowHeight / 2;

     /*
     // Criando uma janela baseada na classe "BasicWindow" 
     hwnd = CreateWindow (
                "BasicWindow",              // classe da janela
                "Aplica��o",                // t�tulo da janela
                WS_OVERLAPPED | WS_SYSMENU, // estilo da janela
                windowPosX,                 // posi��o x inicial
                windowPosY,                 // posi��o y inicial
                windowWidth,                // largura inicial
                windowHeight,               // altura inicial
                NULL,                       // identificador da janela pai
                NULL,                       // identificador do menu
                hInstance,                  // identificador da aplica��o
                NULL);                      // par�metros de cria��o
     */

     // cria a janela principal
     hwnd = CreateWindowEx(
                NULL,                       // estilos extras
                "BasicWindow",              // classe da janela
                "Aplica��o",                // t�tulo da janela
                WS_OVERLAPPED | WS_SYSMENU, // estilo da janela
                CW_USEDEFAULT,              // posi��o x inicial
                CW_USEDEFAULT,              // posi��o y inicial
                windowWidth,                // largura da janela
                windowHeight,               // altura da janela
                NULL,                       // identificador do objeto pai
                NULL,                       // identificador do menu
                hInstance,                  // identificador da aplica��o
                NULL);                      // par�metros de cria��o

     // o ret�ngulo com o tamanho da �rea cliente desejada
     RECT winRect = { 0, 0, windowWidth, windowHeight };

     // ajuste do tamanho da janela
     AdjustWindowRectEx(&winRect, GetWindowStyle(hwnd), GetMenu(hwnd) != NULL, GetWindowExStyle(hwnd));

     // usado para centralizar janela na tela
     windowPosX = (GetSystemMetrics(SM_CXSCREEN) / 2) - ((winRect.right - winRect.left) / 2);
     windowPosY = (GetSystemMetrics(SM_CYSCREEN) / 2) - ((winRect.bottom - winRect.top) / 2);

     // redimensiona janela com uma chamada a MoveWindow
     MoveWindow(
            hwnd,                           // identificador da janela
            windowPosX,                     // posi��o x
            windowPosY,                     // posi��o y
            winRect.right - winRect.left,   // largura
            winRect.bottom - winRect.top,   // altura
            TRUE);                          // repintar

     // Mostra e atualiza a janela
     ShowWindow(hwnd, nCmdShow);
     UpdateWindow(hwnd);
     
     // Tratamento de mensagens destinadas a janela da aplica��o
     while (GetMessage(&msg, NULL, 0, 0))
     {
          TranslateMessage(&msg);
          DispatchMessage(&msg);
     }

     // fim do programa
     return int(msg.wParam);
}

//-------------------------------------------------------------------------------

// procedimento da janela
LRESULT CALLBACK WinProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
     switch (message)
     {
     case WM_DESTROY:
         PostQuitMessage(0);
         return 0;
     }
     return DefWindowProc(hwnd, message, wParam, lParam);
}

//-------------------------------------------------------------------------------