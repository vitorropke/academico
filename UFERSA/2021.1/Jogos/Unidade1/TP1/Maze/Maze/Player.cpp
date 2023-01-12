/**********************************************************************************
// Player (Código Fonte)
// 
// Criação:     01 Jan 2013
// Atualização: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Player do jogo Maze
//
**********************************************************************************/

#include "Player.h"

#include "Level1.h"
#include "Maze.h"
#include "PowerUp.h"
#include "Wall.h"

// ---------------------------------------------------------------------------------

Player::Player()
{
	spriteDefault = new Sprite("Resources/Player/Smiley.png");
	spritePursued = new Sprite("Resources/Player/Surprise.png");
	spriteArrested = new Sprite("Resources/Player/Sad.png");
	spriteDead = new Sprite("Resources/Player/Dead.png");
	spriteInvisible = new Sprite("Resources/Player/Invisible.png");

	BBox(new Circle(spriteDefault->Width() / 2.0f));

	type = PLAYER;
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
	delete spriteDefault;
	delete spritePursued;
	delete spriteArrested;
	delete spriteDead;
	delete spriteInvisible;
}

// ---------------------------------------------------------------------------------

void Player::OnCollision(Object* obj)
{
	// Colisão com muro
	if (obj->Type() == WALL)
	{
		WallCollision(obj);
	}

	// colisão com a faca do fantasma
	if (obj->Type() == GHOST)
	{
		arrested = true;
	}

	// colisão com a visão do fantasma
	if (obj->Type() == GHOST_VISION)
	{
		pursued = true;
	}

	// colisão com o power up
	if (obj->Type() == POWER_UP)
	{
		PowerUp* powerUp = (PowerUp*)obj;

		// aceleração
		if (powerUp->CurrentPowerUp() == ACCELERATION)
		{
			accelerated = true;
			powerUp->spawner->occupied = false;
			Level1::scene->Delete(obj, STATIC);
		}
		// invisibilidade
		else if (powerUp->CurrentPowerUp() == INVISIBILITY)
		{
			invisible = true;
			powerUp->spawner->occupied = false;
			Level1::scene->Delete(obj, STATIC);
		}
	}
}

// ---------------------------------------------------------------------------------

void Player::WallCollision(Object* obj)
{
	Wall* wall = (Wall*)obj;

	// quando o jogador colide na esquerda do muro
	if (((x - spriteDefault->Width() / 2.0f) <= wall->Left()) && !((x + spriteDefault->Width() / 2.0f - 1) > wall->Left()))
	{
		MoveTo(wall->Left() - spriteDefault->Width() / 2.0f, y);
	}
	// quando o jogador colide na direita do muro
	else if ((x >= wall->Right()) && !((x - spriteDefault->Width() / 2.0f + 1) < wall->Right()))
	{
		MoveTo(wall->Right() + spriteDefault->Width() / 2.0f, y);
	}
	// quando o jogador colide no topo do muro
	else if (y < wall->Top())
	{
		MoveTo(x, wall->Top() - spriteDefault->Height() / 2.0f);
	}
	// quando o jogador colide na base do muro
	else if (y >= wall->Bottom())
	{
		MoveTo(x, wall->Bottom() + spriteDefault->Height() / 2.0f);
	}
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
	// Velocidade em caso de power up
	if (accelerated)
	{
		velX = 110;
		velY = 110;
	}
	else
	{
		velX = 80;
		velY = 80;
	}

	// movimento para esquerda
	if ((window->KeyDown(VK_LEFT)) || (window->KeyDown(0x41)))
	{
		Translate(-velX * gameTime, 0);
	}
	// movimento para direita
	if ((window->KeyDown(VK_RIGHT) || (window->KeyDown(0x44))))
	{
		 Translate(velX * gameTime, 0);
	}
	// movimento para cima
	if ((window->KeyDown(VK_UP)) || (window->KeyDown(0x57)))
	{
		Translate(0, -velY * gameTime);
	}
	// movimento para baixo
	if ((window->KeyDown(VK_DOWN)) || (window->KeyDown(0x53)))
	{
		Translate(0, velY * gameTime);
	}

	// mantém o jogador na tela
	// esquerda
	if ((x - spriteDefault->Width() / 2.0f) < 0)
	{
		MoveTo(spriteDefault->Width() / 2.0f, Y());
	}
	// direita
	if ((x + spriteDefault->Width() / 2.0f) > window->Width())
	{
		MoveTo(window->Width() - spriteDefault->Width() / 2.0f, Y());
	}
	// cima
	if ((Y() - spriteDefault->Height() / 2.0f) < 0)
	{
		MoveTo(x, spriteDefault->Height() / 2.0f);
	}
	// baixo
	if ((Y() + spriteDefault->Height() / 2.0f) > window->Height())
	{
		MoveTo(x, window->Height() - spriteDefault->Height() / 2.0f);
	}
}

// ---------------------------------------------------------------------------------

void Player::Draw()
{
	if (lives == 0)
	{
		spriteDead->Draw(x, y, Layer::UPPER);
	}
	else if (arrested)
	{
		spriteArrested->Draw(x, y, Layer::UPPER);
		invisible = false;
		accelerated = false;
	}
	else if (invisible)
	{
		spriteInvisible->Draw(x, y, Layer::UPPER);
	}
	else if (pursued)
	{
		spritePursued->Draw(x, y, Layer::UPPER);
		pursued = false;
	}
	else
	{
		spriteDefault->Draw(x, y, Layer::UPPER);
	}
}

// ---------------------------------------------------------------------------------
