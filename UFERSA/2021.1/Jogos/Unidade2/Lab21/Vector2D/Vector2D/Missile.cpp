/**********************************************************************************
// Missile (C�digo Fonte)
// 
// Cria��o:     23 Nov 2011
// Atualiza��o: 13 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define uma classe para um m�ssil/proj�til
//
**********************************************************************************/

#include "Missile.h"
#include "Vector2D.h"

// ------------------------------------------------------------------------------

Missile::Missile(Plane * plane, Image * img, float delta)
{
    // inicializa sprite
    sprite = new Sprite(img);

    // inicializa vetor velocidade
    speed.angle = plane->Angle() + delta;
    speed.magnitude = 500;
    
    // rotaciona a imagem do m�ssil
    RotateTo(plane->Rotation() + delta);
    
    // move para posi��o
    float dx = ((plane->Height() * plane->Scale()) / 2.0f) * cos(speed.Radians());
    float dy = ((plane->Height() * plane->Scale()) / 2.0f) * sin(speed.Radians());

    MoveTo(plane->X() + dx, plane->Y() - dy);
}

// ------------------------------------------------------------------------------

Missile::~Missile()
{
    delete sprite;
}

// -------------------------------------------------------------------------------

void Missile::Update()
{
    // desloca m�ssil pelas componentes do vetor speed
    Translate(speed.X() * gameTime, -speed.Y() * gameTime);
    
    // se o m�ssil sair da janela
    if (x > window->Width() || x < 0 || y > window->Height() || y < 0)
    {
        Vector2D::audio->Play(EXPLOSION);
        Vector2D::scene->Delete();
    }
}

// -------------------------------------------------------------------------------

void Missile::Draw()
{
    sprite->Draw(x, y, z, scale, rotation);
}

// -------------------------------------------------------------------------------
