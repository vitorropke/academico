/**********************************************************************************
// Geometry (Arquivo de Cabe�alho)
//
// Cria��o:     03 Fev 2013
// Atualiza��o: 11 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define v�rtices e �ndices para v�rias geometrias
//
**********************************************************************************/

#ifndef DXUT_GEOMETRY_H_
#define DXUT_GEOMETRY_H_

// -------------------------------------------------------------------------------

#include "Types.h"
#include <vector>
#include <DirectXMath.h>
#include <DirectXColors.h>
using namespace DirectX;
using std::vector;

// -------------------------------------------------------------------------------

struct Vertex
{
    XMFLOAT3 pos;
    XMFLOAT4 color;
    XMFLOAT3 normal;
};

// -------------------------------------------------------------------------------
// Geometry
// -------------------------------------------------------------------------------

struct Geometry
{
    vector<Vertex> vertices;                            // v�rtices da geometria
    vector<uint>   indices;                             // �ndices da geometria

    Geometry();                                         // construtor
    virtual ~Geometry();                                // destrutor
};

// -------------------------------------------------------------------------------
// Box
// -------------------------------------------------------------------------------

struct Box : public Geometry
{
    Box(float width, float height, float depth);
};

// -------------------------------------------------------------------------------
// Cylinder
// -------------------------------------------------------------------------------

struct Cylinder : public Geometry
{
    Cylinder(float bottom, float top, float height, uint sliceCount, uint stackCount);
};

// -------------------------------------------------------------------------------
// Sphere
// -------------------------------------------------------------------------------

struct Sphere : public Geometry
{
    Sphere(float radius, uint sliceCount, uint stackCount);
};

// -------------------------------------------------------------------------------
// GeoSphere
// -------------------------------------------------------------------------------

struct GeoSphere : public Geometry
{
    GeoSphere(float radius, uint subdivisions);

    // subdivide os tri�ngulos
    void Subdivide();                                   
};


// -------------------------------------------------------------------------------
// Grid
// -------------------------------------------------------------------------------

struct Grid : public Geometry
{
    Grid(float width, float depth, uint m, uint n);
};

// -------------------------------------------------------------------------------
// Quad
// -------------------------------------------------------------------------------

struct Quad : public Geometry
{
    Quad(float width, float height);
};

// -------------------------------------------------------------------------------

#endif
