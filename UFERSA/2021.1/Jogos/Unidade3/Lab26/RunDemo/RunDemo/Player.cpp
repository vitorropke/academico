/**********************************************************************************
// Player (C�digo Fonte)
// 
// Cria��o:     10 Out 2012
// Atualiza��o: 05 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define a classe jogador
//
**********************************************************************************/

#include "Player.h" 
#include "Missile.h"
#include "RunDemo.h"

// -------------------------------------------------------------------------------

Player::Player()
{
    // inicializa controle
    gamepad = new Controller();
    gamepadOn = gamepad->Initialize();

    // configura��o do objeto
    sprite = new Sprite("Resources/Player.png");
    speed  = new Vector(90.0f, 0.0f);
    BBox(new Circle(18.0f));
    MoveTo(game->CenterX(), game->CenterY());
    type = PLAYER;

    // configura��o do emissor de part�culas
    Generator emitter;
    emitter.imgFile = "Resources/Spark.png";    // arquivo de imagem
    emitter.angle = 270.0f;                     // �ngulo base do emissor
    emitter.spread = 50;                        // espalhamento em graus
    emitter.lifetime = 0.3f;                    // tempo de vida em segundos
    emitter.frequency = 0.010f;                 // tempo entre gera��o de novas part�culas
    emitter.percentToDim = 0.6f;                // desaparece ap�s 60% da vida
    emitter.minSpeed = 50.0f;                   // velocidade m�nima das part�culas
    emitter.maxSpeed = 100.0f;                  // velocidade m�xima das part�culas
    emitter.color.r = 1.0f;                     // componente Red da part�cula 
    emitter.color.g = 1.0f;                     // componente Green da part�cula 
    emitter.color.b = 1.0f;                     // componente Blue da part�cula 
    emitter.color.a = 1.0f;                     // transpar�ncia da part�cula

    // cria sistema de part�culas
    tail = new Particles(emitter);
}

// -------------------------------------------------------------------------------

Player::~Player()
{
    delete sprite;
    delete speed;
    delete tail;
    delete gamepad;
}

// -------------------------------------------------------------------------------

void Player::Move(Vector && v)
{
    speed->Add(v);

    // limita velocidade m�xima
    if (speed->Magnitude() > 10.0f)
        speed->ScaleTo(10.0f);
}

// -------------------------------------------------------------------------------

void Player::Update()
{
    // magnitude do vetor acelera��o
    float accel = 40.0f * gameTime;

    // -----------------
    // Controle
    // -----------------

    if (gamepadOn)
    {
        gamepad->UpdateState();

        float ang = Line::Angle(Point(0, 0), Point(gamepad->Axis(AxisX) / 25.0f, gamepad->Axis(AxisY) / 25.0f));
        float mag = Point::Distance(Point(0, 0), Point(gamepad->Axis(AxisX) / 25.0f, gamepad->Axis(AxisY) / 25.0f));

        // nenhuma dire��o selecionada
        if (mag == 0)
        {
            // se a velocidade estiver muita baixa
            if (speed->Magnitude() < 0.1)
            {
                // apenas pare
                speed->ScaleTo(0.0f);
            }
            else
            {
                // comece a frear
                Move(Vector(speed->Angle() + 180.0f, 5.0f * gameTime));
            }
        }
        else
        {
            // ande na dire��o selecionada
            Move(Vector(ang, mag * gameTime));
        }

        // dispara m�ssil
        if (gamepad->ButtonPress(0))
        {
            RunDemo::audio->Play(FIRE);
            RunDemo::scene->Add(new Missile(), STATIC);
        }
    }

    // -----------------
    // Teclado
    // -----------------

    else
    {
        // modifica vetor velocidade do player
        if (window->KeyDown(VK_RIGHT) && window->KeyDown(VK_UP))
            Move(Vector(45.0f, accel));
        else if (window->KeyDown(VK_LEFT) && window->KeyDown(VK_UP))
            Move(Vector(135.0f, accel));
        else if (window->KeyDown(VK_LEFT) && window->KeyDown(VK_DOWN))
            Move(Vector(225.0f, accel));
        else if (window->KeyDown(VK_RIGHT) && window->KeyDown(VK_DOWN))
            Move(Vector(315.0f, accel));
        else if (window->KeyDown(VK_RIGHT))
            Move(Vector(0.0f, accel));
        else if (window->KeyDown(VK_LEFT))
            Move(Vector(180.0f, accel));
        else if (window->KeyDown(VK_UP))
            Move(Vector(90.0f, accel));
        else if (window->KeyDown(VK_DOWN))
            Move(Vector(270.0f, accel));
        else
            // se nenhuma tecla est� pressionada comece a frear
            if (speed->Magnitude() > 0.1f)
                Move(Vector(speed->Angle() + 180.0f, 5.0f * gameTime));
            else
                // velocidade muita baixa, n�o use soma vetorial, apenas pare
                speed->ScaleTo(0.0f);

        // dispara m�ssil
        if (window->KeyPress(VK_SPACE))
        {
            RunDemo::audio->Play(FIRE);
            RunDemo::scene->Add(new Missile(), STATIC);
        }
    }

    // movimenta objeto pelo seu vetor velocidade
    Translate(speed->XComponent() * 50.0f * gameTime, -speed->YComponent() * 50.0f * gameTime);

    // atualiza calda do jogador
    tail->Config().angle = speed->Angle() + 180;
    tail->Generate(x - 10 * cos(speed->Radians()), y + 10 * sin(speed->Radians()));
    tail->Update(gameTime);

    // restringe a �rea do jogo
    if (x < 0)
        MoveTo(0, y);
    if (y < 0)
        MoveTo(x, 0);
    if (x > game->Width())
        MoveTo(game->Width(), y);
    if (y > game->Height())
        MoveTo(x, game->Height());
}

// ---------------------------------------------------------------------------------

void Player::Draw()
{
    sprite->Draw(x, y, Layer::MIDDLE, 1.0f, -speed->Angle() + 90.0f);
    tail->Draw(Layer::LOWER, 1.0f);
}

// -------------------------------------------------------------------------------
