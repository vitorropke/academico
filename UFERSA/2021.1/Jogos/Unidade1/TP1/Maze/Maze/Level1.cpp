/**********************************************************************************
// Level1 (Código Fonte) 
// 
// Criação:     18 Jan 2013
// Atualização: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Nível 1 do jogo Maze
//
**********************************************************************************/

#include "Level1.h"

#include "Congratulations.h"
#include "GameOver.h"
#include "GhostVision.h"
#include "Home.h"
#include "Spawner.h"
#include "Wall.h"

#include "Engine.h"

#include <fstream>
#include <random>
#include <string>
#include <vector>

using std::ifstream;
using std::string;
using namespace std;

// ------------------------------------------------------------------------------
// Inicialização de membros estáticos da classe

Scene* Level1::scene = nullptr;		// gerenciador de cena

// ------------------------------------------------------------------------------
// Constantes Globais

// define um número pseudoaleatório que será onde fantasma e power-ups irão aparecer
random_device rd;
mt19937 mt(rd());

uniform_int_distribution<uint> randPowerUp(0, 1);

// ---------------------------------------------------------------------------------

void Level1::Init()
{
	// cria gerenciador de cena
	scene = new Scene();

	// cria background
	backg = new Sprite("Resources/Levels/Level1.png");

	// cria corações e não corações
	for (int i = 0; i < 3; i++) {
		heart[i] = new Sprite("Resources/Icons/Heart.png");
		noHeart[i] = new Sprite("Resources/Icons/NoHeart.png");
	}

	// cria relógio com contagem regressiva
	countdown = new Font("Resources/Font/CourierNew32.png");
	countdown->Spacing(20);

	// cria alvo do jogador
	target = new Sprite("Resources/Icons/Target.png");
	
	// cria muros a partir do arquivo
	Wall* wall;
	float left, top, right, bottom;
	
	ifstream fileWalls;
	fileWalls.open("WallsL1.txt");
	fileWalls >> left;
	while (!fileWalls.eof())
	{
		if (fileWalls.good())
		{
			// lê linha de informações do muro
			fileWalls >> top; fileWalls >> right; fileWalls >> bottom;
			wall = new Wall(left, top, right, bottom);
			scene->Add(wall, STATIC);
		}
		else
		{
			// ignora comentários
			fileWalls.clear();
			char temp[80];
			fileWalls.getline(temp, 80);
		}
		fileWalls >> left;
	}
	fileWalls.close();

	// cria spawners a partir do arquivo
	Spawner* spawner;
	float posX, posY;
	uint numSpawners = 0;
	vector<Spawner*> spawnersList;

	ifstream fileSpawners;
	fileSpawners.open("SpawnersL1.txt");
	fileSpawners >> posX;
	while (!fileSpawners.eof())
	{
		if (fileSpawners.good())
		{
			// lê linha de informações do spawner
			fileSpawners >> posY;
			spawner = new Spawner();
			spawner->MoveTo(posX, posY);
			scene->Add(spawner, STATIC);
			numSpawners++;
			spawnersList.push_back(spawner);
		}
		else
		{
			// ignora comentários
			fileSpawners.clear();
			char temp[80];
			fileSpawners.getline(temp, 80);
		}
		fileSpawners >> posX;
	}
	fileSpawners.close();

	uint index = 0;
	uniform_int_distribution<uint> randSpawner(0, numSpawners - 1);

	// escolhe o spawner para o fantasma
	Spawner* chosenSpawnerGhost = nullptr;
	// verifica se o spawner não está ocupado
	do
	{
		index = randSpawner(mt);
	} while (spawnersList[index]->occupied);

	spawnersList[index]->occupied = true;
	chosenSpawnerGhost = spawnersList[index];

	// escolhe o spawner para o powerUp 1
	Spawner* chosenSpawnerPowerUp1 = nullptr;
	// verifica se o spawner não está ocupado
	do
	{
		index = randSpawner(mt);
	} while (spawnersList[index]->occupied);

	spawnersList[index]->occupied = true;
	chosenSpawnerPowerUp1 = spawnersList[index];

	// escolhe o spawner para o powerUp 2
	Spawner* chosenSpawnerPowerUp2 = nullptr;
	// verifica se o spawner não está ocupado
	do
	{
		index = randSpawner(mt);
	} while (spawnersList[index]->occupied);

	spawnersList[index]->occupied = true;
	chosenSpawnerPowerUp2 = spawnersList[index];

	// cria jogador
	player = new Player();
	player->MoveTo(window->CenterX(), window->CenterY());
	scene->Add(player, MOVING);

	// cria inimigo
	ghostPositionX = chosenSpawnerGhost->X();
	ghostPositionY = chosenSpawnerGhost->Y();

	ghost = new Ghost(player);

	ghost->MoveTo(ghostPositionX, ghostPositionY);
	scene->Add(ghost, MOVING);

	// cria a visão do inimigo
	GhostVision* ghostVision = new GhostVision(ghost);
	scene->Add(ghostVision, STATIC);

	// cria power ups para o jogador
	powerUp1 = new PowerUp(randPowerUp(mt), chosenSpawnerPowerUp1);
	scene->Add(powerUp1, STATIC);

	powerUp2 = new PowerUp(randPowerUp(mt), chosenSpawnerPowerUp2);
	scene->Add(powerUp2, STATIC);

	// começa a contar o tempo da rodada
	roundTime.Start();
}

// ------------------------------------------------------------------------------

void Level1::Finalize()
{
	delete backg;
	for (int i = 0; i < 3; i++) {
		delete heart[i];
		delete noHeart[i];
	}
	delete countdown;
	delete target;
	delete scene;
}

// ------------------------------------------------------------------------------

void Level1::Update()
{
	if (window->KeyDown(VK_ESCAPE))
	{
		// volta para a tela de abertura
		Engine::Next<Home>();
	}
	else if (
				(
					((player->Y() + player->Radius() / 2) >= (targetPositionY - target->Height() / 2)) &&
					((player->Y() - player->Radius() / 2) <= (targetPositionY + target->Height() / 2)) &&
					((player->X() + player->Radius() / 2) >= (targetPositionX - target->Width() / 2)) &&
					((player->X() - player->Radius() / 2) <= (targetPositionX + target->Width() / 2))
				)
			)
	{
		// passa para o próximo nível
		Engine::Next<Congratulations>();
	}
	else if (roundTime.Elapsed(timeLimit))
	{
		player->arrested = true;
		roundTime.Reset();
	}
	else if (player->arrested)
	{
		// fim do tempo
		player->lives--;
		player->arrested = false;

		if (player->lives != 0)
		{
			Sleep(2000);
			Engine::Resume();

			player->MoveTo(window->CenterX(), window->CenterY());
			ghost->MoveTo(ghostPositionX, ghostPositionY);
		}
		roundTime.Reset();
	}
	else if (player->lives == 0)
	{
		// fim do jogo
		Sleep(3000);
		Engine::Next<GameOver>();
	}
	else
	{
		// atualiza cena
		scene->Update();
		scene->CollisionDetection();
	}
}

// ------------------------------------------------------------------------------

void Level1::Draw()
{
	// desenha cena
	backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
	scene->Draw();

	// desenha corações
	if (player->lives == 0)
	{
		noHeart[0]->Draw(20.0f, 20.0f);
		noHeart[1]->Draw(60.0f, 20.0f);
		noHeart[2]->Draw(100.0f, 20.0f);
	}
	else if (player->lives == 1)
	{
		heart[0]->Draw(20.0f, 20.0f);
		noHeart[1]->Draw(60.0f, 20.0f);
		noHeart[2]->Draw(100.0f, 20.0f);
	}
	else if (player->lives == 2)
	{
		heart[0]->Draw(20.0f, 20.0f);
		heart[1]->Draw(60.0f, 20.0f);
		noHeart[2]->Draw(100.0f, 20.0f);
	}
	else
	{
		heart[0]->Draw(20.0f, 20.0f);
		heart[1]->Draw(60.0f, 20.0f);
		heart[2]->Draw(100.0f, 20.0f);
	}

	// desenha relógio com contagem regressiva
	int intCountdown = static_cast<int>(timeLimit - roundTime.Elapsed());

	if (intCountdown <= 15)
	{
		countdown->Draw(
			940,
			23,
			std::to_string(intCountdown),
			Color(1.0f, 0.0f, 0.0f, 1.0f)
		);
	}
	else
	{
		countdown->Draw(
			940,
			23,
			std::to_string(intCountdown),
			Color(0.0f, 0.0f, 0.0f, 1.0f)
		);
	}

	// desenha alvo do jogador
	target->Draw(targetPositionX, targetPositionY);
}

// ------------------------------------------------------------------------------
