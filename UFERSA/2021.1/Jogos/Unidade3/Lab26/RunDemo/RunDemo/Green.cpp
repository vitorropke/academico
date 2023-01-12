/**********************************************************************************
// Green (C�digo Fonte)
// 
// Cria��o:     15 Out 2012
// Atualiza��o: 05 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Objeto faz uma fuga suavizada
//
**********************************************************************************/

#include "Green.h"
#include "RunDemo.h"
#include "Random.h" 

// ---------------------------------------------------------------------------------

Green::Green(float pX, float pY, Player * p)
{
    player = p;
    sprite = new Sprite("Resources/Green.png");
    BBox(new Circle(20.0f));
    speed.RotateTo(0.0f);
    speed.ScaleTo(0.0f);

    // mant�m certa dist�ncia do jogador
    RandI dist{ 100, 300 };
    distance = dist.Rand();

    MoveTo(pX, pY);
    type = GREEN;

    // incrementa contador
    ++Hud::enemies;
}

// ---------------------------------------------------------------------------------

Green::~Green()
{
    delete sprite;

    // decrementa contador
    --Hud::enemies;
}

// -------------------------------------------------------------------------------

void Green::OnCollision(Object * obj)
{
    if (obj->Type() == MISSILE)
    {
        RunDemo::scene->Delete(obj, STATIC);
        RunDemo::scene->Delete(this, MOVING);
        RunDemo::audio->Play(EXPLODE);
    }
    else if (obj->Type() == GREEN)
    {
        // vetor de 'repel�ncia'
        Vector target = Vector(Line::Angle(Point(x, y), Point(obj->X(), obj->Y())), 20.0f * gameTime);

        target.Rotate(180.0f);
        target.ScaleTo(100.0f * gameTime);

        speed.Add(target);
    }
}

// -------------------------------------------------------------------------------

void Green::Update()
{
    // a magnitude do vetor target controla qu�o 
    // r�pido o objeto converge para a dire��o do alvo
    Vector target = Vector(Line::Angle(Point(x, y), Point(player->X(), player->Y())), 20.0f * gameTime);
    
    // fugir se o player chegar muito perto
    if (Point::Distance(Point(x, y), Point(player->X(), player->Y())) < distance)
    {
        target.Rotate(180.0f);
        target.ScaleTo(100.0f * gameTime);
    }

    speed.Add(target);
    
    // limita a magnitude da velocidade para impedir 
    // seu crescimento indefinido na soma vetorial
    if (speed.Magnitude() > 8)
        speed.ScaleTo(8.0f);

    // move o objeto pelo seu vetor velocidade
    Translate(speed.XComponent() * 50.0f * gameTime, -speed.YComponent() * 50.0f * gameTime);
    Rotate(50 * gameTime);

    // mant�m o objeto dentro do mundo do jogo
    if (x < 0)
        MoveTo(0, y);
    if (y < 0)
        MoveTo(x, 0);
    if (x > game->Width())
        MoveTo(game->Width(), y);
    if (y > game->Height())
        MoveTo(x, game->Height());
}

// -------------------------------------------------------------------------------