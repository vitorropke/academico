/**********************************************************************************
// Player (Código Fonte)
// 
// Criação:     20 Abr 2012
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define uma classe para o jogador 
//
**********************************************************************************/

#include "Player.h"

#include "LandTheBooster.h"
#include "Level1.h"
#include "Platform.h"

#include <random>
#include <sstream>

using namespace std;

// ---------------------------------------------------------------------------------

Player::Player()
{
	rocket = new TileSet("Resources/Player/Rocket.png", 126, 275, 9, 43);
	engineExhaust = new TileSet("Resources/Player/EngineExhaust.png", 20, 120, 4, 7);
	rcs = new TileSet("Resources/Player/RCS.png", 42, 9, 4, 8);
	explosion = new TileSet("Resources/Player/Explosion.png", 248, 197, 4, 12);

	rocketAnim = new Animation(rocket, 0.05f, false);
	engineExhaustAnim = new Animation(engineExhaust, 0.02f, true);
	rcsAnim = new Animation(rcs, 0.05f, true);
	explosionAnim = new Animation(explosion, 0.08f, false);

	uint deployingLegs[25];
	uint retractingGridFins[18];

	for (int i = 0; i < 25; i++)
	{
		deployingLegs[i] = i;
	}
	for (int i = 0; i < 18; i++)
	{
		retractingGridFins[i] = i + 25;
	}

	rocketAnim->Add(FLIGHT, deployingLegs, 25);
	rocketAnim->Add(LANDED, retractingGridFins, 18);

	// fonte que mostra o combustível
	bankGothic = new Font("Resources/Font/BankGothic40.png");

	escButton = new Sprite("Resources/Player/EscButton.png");
	enterButton = new Sprite("Resources/Player/EnterButton.png");
	
	// formato da caixa de colisão
	BBox(new Rect(rocket->TileWidth() / -2.0f, rocket->TileHeight() / -2.0f,
		rocket->TileWidth() / 2.0f, rocket->TileHeight() / 2.0f));

	random_device rd;
	mt19937 mt(rd());
	uniform_real_distribution<float> randXPosition(positionXRangeSpawn[0], positionXRangeSpawn[1]);
	uniform_real_distribution<float> randWindSpeed(windRange[0], windRange[1]);

	// velocidade do vento
	wind = randWindSpeed(mt);

	// posição inicial
	MoveTo(randXPosition(mt), 24.0f, Layer::FRONT);
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
	delete rocket;
	delete engineExhaust;
	delete rcs;
	delete explosion;
	delete rocketAnim;
	delete engineExhaustAnim;
	delete rcsAnim;
	delete explosionAnim;
	delete bankGothic;
	delete escButton;
	delete enterButton;
}

// ---------------------------------------------------------------------------------

void Player::Reset()
{
	LandTheBooster::audio->Stop(ENGINE);
	LandTheBooster::audio->Stop(RCS);

	random_device rd;
	mt19937 mt(rd());
	uniform_real_distribution<float> randXPosition(positionXRangeSpawn[0], positionXRangeSpawn[1]);
	uniform_real_distribution<float> randWindSpeed(windRange[0], windRange[1]);

	// posição inicial
	MoveTo(randXPosition(mt), 24.0f, Layer::FRONT);

	explosionAnim->Restart();
	rocketAnim->Restart();

	state = FLIGHT;

	verticalSpeed = 1.0f;
	lateralSpeed = 0.0f;

	fuel = 500.0f;

	wind = randWindSpeed(mt);

	level = 0;

	leftRCSActivated = false;
	rightRCSActivated = false;

	engineIgnited = false;
	exploded = false;
	landed = false;

	endExplosion = false;
}

// ---------------------------------------------------------------------------------

void Player::OnCollision(Object * obj)
{
	Platform* platform = (Platform*)obj;

	// é a zona de pouso
	// velocidade vertical é menor que 60
	// velocidade horizontal é menor que 40 para direita ou esquerda
	// foguete está dentro da zona de pouso, ou seja, não está 'pousando' a perna fora dela
	if (
		(obj->Type() == LAND_ZONE) && (verticalSpeed < 60.0f) &&
		((lateralSpeed > -40.0f) && (lateralSpeed < 40.0f)) &&
		(((x + rocket->TileWidth() / 2.0f) <= (platform->X() + platform->Width() / 2.0f + 20.0f)) &&
			((x - rocket->TileWidth() / 2.0f) >= (platform->X() - platform->Width() / 2.0f - 20.0f)))
		)
	{
		// inicia contagem do tempo e executa o som de aplausos
		if (!landed)
		{
			state = LANDED;
			landed = true;
			landTime.Start();
			LandTheBooster::audio->Play(CHEERS);
		}
		// espera terminar animação e som dos aplausos
		if (landTime.Elapsed(3.7f))
		{
			level++;
		}
	}
	// inicia contagem do tempo e executa o som de aplausos
	else if (!exploded)
	{
		LandTheBooster::audio->Play(EXPLOSION);
		exploded = true;
		landTime.Start();
	}
	// espera terminar animação e som da explosão
	else if(landTime.Elapsed(1.5f))
	{
		endExplosion = true;
	}
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
	// se o foguete tiver combustível, não tiver pousado nem explodido
	if ((fuel > 0.0f) && (!landed) && (!exploded))
	{
		// motor
		if (window->KeyDown(VK_SPACE))
		{
			// só toca o som do motor uma vez após apertar espaço
			if (!engineIgnited)
			{
				LandTheBooster::audio->Play(ENGINE, true);
			}
			engineIgnited = true;
			verticalSpeed -= 150.0f * gameTime;
			fuel -= 100.0f * gameTime;
		}
		if (window->KeyUp(VK_SPACE))
		{
			LandTheBooster::audio->Stop(ENGINE);
			engineIgnited = false;
		}

		float rcsPower = 30.0f;
		float rcsFuelUse = 2.0f;
		// deslocamento para esquerda
		if (window->KeyDown(VK_LEFT))
		{
			// só toca o som do RCS uma vez após apertar esquerda
			if (!rightRCSActivated)
			{
				LandTheBooster::audio->Play(RCS, true);
			}
			rightRCSActivated = true;
			lateralSpeed -= rcsPower * gameTime;
			fuel -= rcsFuelUse * gameTime;
		}
		if (window->KeyUp(VK_LEFT))
		{
			rightRCSActivated = false;
		}

		// deslocamento para direita
		if (window->KeyDown(VK_RIGHT))
		{
			// só toca o som do RCS uma vez após apertar direita
			if (!leftRCSActivated)
			{
				LandTheBooster::audio->Play(RCS, true);
			}
			leftRCSActivated = true;
			lateralSpeed += rcsPower * gameTime;
			fuel -= rcsFuelUse * gameTime;
		}
		if (window->KeyUp(VK_RIGHT))
		{
			leftRCSActivated = false;
		}

		// verifica se o rcs está desativado em ambos os lados
		if (window->KeyUp(VK_LEFT) && window->KeyUp(VK_RIGHT))
		{
			LandTheBooster::audio->Stop(RCS);
		}
	}
	else
	{
		// se o combustível acabou ou o foguete pousou ou explodiu
		// corte todos os meios de propulsão
		LandTheBooster::audio->Stop(ENGINE);
		LandTheBooster::audio->Stop(RCS);
		engineIgnited = false;
		rightRCSActivated = false;
		leftRCSActivated = false;
	}

	// aplicação da gravidade e do vento
	if (!landed)
	{
		verticalSpeed += 100.0f * gameTime;
		lateralSpeed += wind * gameTime;
	}
	else
	{
		verticalSpeed = 0.0f;
		lateralSpeed = 0.0f;
		wind = 0.0f;
	}

	if (!exploded)
	{
		// atualiza posição
		Translate((lateralSpeed + wind) * gameTime, verticalSpeed * gameTime);
		
		// seleciona qual conjunto de tiles mostrar na animação do foguete
		rocketAnim->Select(state);
		
		// atualiza o tile da animação
		rocketAnim->NextFrame();
		engineExhaustAnim->NextFrame();
		rcsAnim->NextFrame();
	}
	else
	{
		explosionAnim->NextFrame();
	}
}

// ---------------------------------------------------------------------------------

void Player::Draw()
{
	if (!exploded)
	{
		float rcsXPositionConst = 10.0f;
		float rcsYPosition = y - 110.0f;
		rocketAnim->Draw(x, y);
		if (engineIgnited)
		{
			engineExhaustAnim->Draw(x, y + rocket->TileHeight() / 2.0f + 38.0f);
		}
		if (leftRCSActivated)
		{
			rcsAnim->Draw(x - rcsXPositionConst - rcs->TileWidth() / 2.0f, rcsYPosition);
		}
		if (rightRCSActivated)
		{
			rcsAnim->Draw(x + rcsXPositionConst + rcs->TileWidth() / 2.0f, rcsYPosition, Layer::MIDDLE, 1.0f, 180.0f);
		}
	}
	else
	{
		explosionAnim->Draw(x, y + 40.0f);
	}
	
	stringstream strFuel;
	strFuel.str("");
	strFuel << int(fuel);
	
	float textXPosition = window->Width() - 150.0f;
	float textYPosition = 20.0f;
	// texto de quantidade de combustível no foguete
	if (fuel >= 300.0f)
	{
		bankGothic->Draw(textXPosition, textYPosition, strFuel.str());
	}
	else if ((fuel >= 150) && (fuel < 300.0f))
	{
		bankGothic->Draw(textXPosition, textYPosition, strFuel.str(), Color(1, 1, 0, 1));
	}
	else
	{
		bankGothic->Draw(textXPosition, textYPosition, strFuel.str(), Color(1, 0, 0, 1));
	}

	// espera terminar animação e som dos aplausos
	if (landTime.Elapsed(3.7f) && landed)
	{
		escButton->Draw(300.0f, window->Height() - 180.0f);
		enterButton->Draw(window->Width() - 230.0f, window->Height() - 180.0f);
	}
}

// ---------------------------------------------------------------------------------
