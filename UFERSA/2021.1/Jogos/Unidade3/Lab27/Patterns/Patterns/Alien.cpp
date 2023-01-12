/**********************************************************************************
// Alien (C�digo Fonte)
// 
// Cria��o:     25 Mar 2013
// Atualiza��o: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Executa scripts com padr�es de movimenta��o
//
**********************************************************************************/

#include "Alien.h"
#include "Stage.h"
#include "Patterns.h"
#include "Explosion.h"
#include <cmath>

// ---------------------------------------------------------------------------------

Alien::Alien(uint alien, Instruction * vet, int tam, float pX, float pY) 
    : angle(-8,8), magnitude(1,8)
{
    // tipo do alien
    type = alien;

    // faz c�pia do script 
    script = new Instruction[tam];
    for (int i=0; i < tam; i++)
        script[i] = vet[i];

    // carrega tileset do objeto
    switch (type)
    {
    case ALIEN1: alienSet = new TileSet("Resources/Alien1.png", 26, 20, 2, 2); break;
    case ALIEN2: alienSet = new TileSet("Resources/Alien2.png", 26, 20, 2, 2); break;
    case ALIEN3: alienSet = new TileSet("Resources/Alien3.png", 28, 28, 2, 2); break;
    case ALIEN4: alienSet = new TileSet("Resources/Alien4.png", 28, 28, 2, 2); break;
    }
    anim = new Animation(alienSet, 0.500, true);
    
    // configura��o inicial do objeto
    BBox(new Rect(-13, -10, 13, 10));
    MoveTo(pX, pY);
    speed = { 0.0f, 0.0f };

    // inicia execu��o do script
    index = 0;
    end = tam - 1;
    duration = script[index].duration;
    timer.Start();

    // mais um inimigo
    ++Stage::enemies;
}

// ---------------------------------------------------------------------------------

Alien::~Alien()
{
    delete [] script;
    delete alienSet;
    delete anim;

    // menos um inimigo
    --Stage::enemies;
}

// ---------------------------------------------------------------------------------

void Alien::OnCollision(Object * obj)
{
    // se colidiu com um m�ssil
    if (obj->Type() == MISSILE)
    {
        // deleta miss�l
        Patterns::scene->Delete(obj, STATIC);

        // toca som de acordo com o alien atingido
        switch (type)
        {
        case ALIEN1: Patterns::audio->Play(ALIEN1); break;
        case ALIEN2: Patterns::audio->Play(ALIEN2); break;
        case ALIEN3: Patterns::audio->Play(ALIEN3); break;
        case ALIEN4: Patterns::audio->Play(ALIEN4); break;
        }

        if (type == ALIEN3)
        {
            // o alien 3 vira o alien 4 ao ser atingido
            delete anim;
            delete alienSet;
            alienSet = new TileSet("Resources/Alien4.png", 28, 28, 2, 2);
            anim = new Animation(alienSet, 0.500, true);
            type = ALIEN4;
        }
        else
        {
            // qualquer outro alien morre com um tiro
            Patterns::scene->Add(new Explosion(x, y), STATIC);
            Patterns::scene->Delete(this, MOVING);            
        }
    }
}

// -------------------------------------------------------------------------------

void Alien::Update()
{
    // deslocamento padr�o
    float delta = 50 * gameTime;

    // atualiza anima��es
    anim->NextFrame();

    // ----------------------------
    // Pr�xima instru��o do script
    // ----------------------------

    if (script[index].instruction == MOVETO || script[index].instruction == SLIDETO)
    {
        // pega posi��o X e Y de destino
        float targetX = script[index].angle;
        float targetY = script[index].magnitude;

        // se chegou bem pr�ximo do destino
        if (abs(x - targetX) < 2 && abs(y - targetY) < 2)
        {
            // move exatamente para a posi��o de destino
            MoveTo(targetX, targetY);

            // passa para a pr�xima instru��o
            index = (index == end ? index : ++index);
            duration = script[index].duration;
            timer.Start();
        }
    }
    else
    {
        // se esgotou o tempo da instru��o
        if (timer.Elapsed(duration))
        {
            // passa para a pr�xima instru��o
            index = (index == end ? index : ++index);
            duration = script[index].duration;
            timer.Start();
        }
    }

    // ------------------------
    // Interpretador do script
    // ------------------------
  
    // realiza salto antes de qualquer outra instru��o
    if (script[index].instruction == JUMP)
    {
        index = int(script[index].angle);
        duration = script[index].duration;
        timer.Start();
    }

    switch (script[index].instruction)
    {
    case MOVE:    // MOVE | �ngulo | Magnitude | Dura��o
        speed.RotateTo(script[index].angle);
        speed.ScaleTo(script[index].magnitude);
        RotateTo(-speed.Angle() + 90);
        break;

    case MOVETO:  // MOVETO | PosX | PosY | Magnitude
        speed.RotateTo(Line::Angle(Point(x, y), Point(script[index].angle, script[index].magnitude)));
        speed.ScaleTo(script[index].duration);
        RotateTo(-speed.Angle() + 90);
        break;

    case SLIDE:   // SLIDE | �ngulo | Magnitude | Dura��o
        speed.RotateTo(script[index].angle);
        speed.ScaleTo(script[index].magnitude);
        break;

    case SLIDETO: // SLIDETO | PosX | PosY | Magnitude
        speed.RotateTo(Line::Angle(Point(x, y), Point(script[index].angle, script[index].magnitude)));
        speed.ScaleTo(script[index].duration);
        break;

    case TURN:    // TURN | �ngulo | Magnitude | Dura��o
    {
        Vector target{ script[index].angle, script[index].magnitude * delta };
        speed.Add(target);
        RotateTo(-speed.Angle() + 90);
        break;
    }
    case ROTATE:  // ROTATE | �ngulo | Magnitude | Dura��o
        speed.Rotate(-script[index].angle * delta);
        speed.ScaleTo(script[index].magnitude);
        Rotate(-script[index].angle * delta);
        break;

    case RANDOM:  // RANDOM | �ngulo | Magnitude | Dura��o
        speed.Rotate(-angle.Rand());
        speed.ScaleTo(magnitude.Rand());
        RotateTo(-speed.Angle() + 90);
        break;
    }

    // desloca objeto pelo seu vetor velocidade
    Translate(speed.XComponent() * delta, -speed.YComponent() * delta);
}

// -------------------------------------------------------------------------------