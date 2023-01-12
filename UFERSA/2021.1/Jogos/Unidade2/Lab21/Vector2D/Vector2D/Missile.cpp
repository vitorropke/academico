/**********************************************************************************
// Missile (Código Fonte)
// 
// Criação:     23 Nov 2011
// Atualização: 13 Out 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define uma classe para um míssil/projétil
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
    
    // rotaciona a imagem do míssil
    RotateTo(plane->Rotation() + delta);
    
    // move para posição
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
    // desloca míssil pelas componentes do vetor speed
    Translate(speed.X() * gameTime, -speed.Y() * gameTime);
    
    // se o míssil sair da janela
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
