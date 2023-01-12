/**********************************************************************************
// Ghost (Código Fonte)
// 
// Criação:     01 Jan 2013
// Atualização: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Fantasmas do Maze
//
**********************************************************************************/

#include "Ghost.h"

#include "Maze.h"
#include "Player.h"
#include "Wall.h"

#include <random>

using namespace std;

// ---------------------------------------------------------------------------------

Ghost::Ghost(Player* p)
{
	spriteL = new Sprite("Resources/Ghost/KnifeLeft.png");
	spriteR = new Sprite("Resources/Ghost/KnifeRight.png");

	player = p;

	BBox(new Circle(spriteL->Width() / 2.0f));
	
	type = GHOST;
}

// ---------------------------------------------------------------------------------

Ghost::~Ghost()
{
	delete spriteL;
	delete spriteR;
}

// ---------------------------------------------------------------------------------

void Ghost::OnCollision(Object* obj)
{
	random_device rd;
	mt19937 mt(rd());

	uniform_int_distribution<uint> randDirection(0, 3);

	// Colisão com muro
	if (obj->Type() == WALL)
	{
		WallCollision(obj);

		// define a nova direção do fantasma e garante que não seja igual à direção atual
		do
		{
			direction = randDirection(mt);
		} while (currState == direction);
	}
}

// ---------------------------------------------------------------------------------

void Ghost::WallCollision(Object* obj)
{
	Wall* wall = (Wall*)obj;

	// quando o fantasma colide na esquerda do muro
	if (((x - spriteL->Width() / 2.0f) <= wall->Left()) && !((x + spriteL->Width() / 2.0f - 1) > wall->Left()))
	{
		MoveTo(wall->Left() - spriteL->Width() / 2.0f - 4.0f, y);
	}
	// quando o fantasma colide na direita do muro
	else if ((x >= wall->Right()) && !((x - spriteL->Width() / 2.0f + 1) < wall->Right()))
	{
		MoveTo(wall->Right() + spriteL->Width() / 2.0f + 4.0f, y);
	}
	// quando o fantasma colide no topo do muro
	else if (y < wall->Top())
	{
		MoveTo(x, wall->Top() - spriteL->Height() / 2.0f - 4.0f);
	}
	// quando o fantasma colide na base do muro
	else if (y >= wall->Bottom())
	{
		MoveTo(x, wall->Bottom() + spriteL->Height() / 2.0f + 4.0f);
	}
}

// ---------------------------------------------------------------------------------

void Ghost::Update()
{
	if (sightedPlayer)
	{
		// jogador está no primeiro quadrante
		if ((player->X() >= X()) && (player->Y() < Y()))
		{
			Translate(velX * gameTime, -velY * gameTime);
			currState = RIGHT;
		}
		// jogador está no segundo quadrante
		else if ((player->X() < X()) && (player->Y() <= Y()))
		{
			Translate(-velX * gameTime, -velY * gameTime);
			currState = LEFT;
		}
		// jogador está no terceiro quadrante
		else if ((player->X() <= X()) && (player->Y() > Y()))
		{
			Translate(-velX * gameTime, velY * gameTime);
			currState = LEFT;
		}
		// jogador está no quarto quadrante
		else if ((player->X() > X()) && (player->Y() >= Y()))
		{
			Translate(velX * gameTime, velY * gameTime);
			currState = RIGHT;
		}
		sightedPlayer = false;
	}
	else
	{
		// deslocamento para esquerda
		if (direction == 0)
		{
			Translate(-velX * gameTime, 0);
			currState = LEFT;
		}
		// deslocamento para direita
		else if (direction == 1)
		{
			Translate(velX * gameTime, 0);
			currState = RIGHT;
		}
		// deslocamento para cima
		else if (direction == 2)
		{
			Translate(0, -velY * gameTime);
			currState = UP;
		}
		// deslocamento para baixo
		else if (direction == 3)
		{
			Translate(0, velY * gameTime);
			currState = DOWN;
		}
	}

	// mantém o fantasma na tela
	// esquerda
	if ((x - spriteL->Width() / 2.0f) < 0)
	{
		MoveTo(spriteL->Width() / 2.0f, Y());
	}
	// direita
	if ((x + spriteL->Width() / 2.0f) > window->Width())
	{
		MoveTo(window->Width() - spriteL->Width() / 2.0f, Y());
	}
	// cima
	if ((Y() - spriteL->Height() / 2.0f) < 0)
	{
		MoveTo(x, spriteL->Height() / 2.0f);
	}
	// baixo
	if ((Y() + spriteL->Height() / 2.0f) > window->Height())
	{
		MoveTo(x, window->Height() - spriteL->Height() / 2.0f);
	}
}

// ---------------------------------------------------------------------------------

inline void Ghost::Draw()
{
	if (currState == LEFT) {
		spriteL->Draw(x, y, z);
	}
	else
	{
		spriteR->Draw(x, y, z);
	}
}

// ---------------------------------------------------------------------------------
