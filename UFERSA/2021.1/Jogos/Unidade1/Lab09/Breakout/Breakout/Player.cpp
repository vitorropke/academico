/**********************************************************************************
// Player (Arquivo de Cabeçalho)
// 
// Criação:     22 Dez 2012
// Atualização: 18 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Player do jogo Breakout
//
**********************************************************************************/

#include "Player.h"

// ---------------------------------------------------------------------------------

Player::Player()
{
	sprite = new Sprite("Resources/Player.png");
	velocidade = 300.0f;

	tamanhoX = sprite->Width();

	// Posição inicial do jogador
	MoveTo(window->CenterX() - sprite->Width() / 2, window->Height() - 50);
}

Player::~Player()
{
	delete sprite;
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
	// Desloca jogador para esquerda
	if (window->KeyDown(VK_LEFT))
	{
		Translate(-velocidade * gameTime, 0);
	}

	// Desloca jogador para direita
	if (window->KeyDown(VK_RIGHT))
	{
		Translate(velocidade * gameTime, 0);
	}

	// Mantém o jogador dentro da janela
	if (x < 0)
	{
		MoveTo(0, y);
	}
	if (x + sprite->Width() > window->Width())
	{
		MoveTo(window->Width() - sprite->Width(), y);
	}
}

void Player::Draw()
{
	sprite->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------
