/**********************************************************************************
// Object (Arquivo de Cabe�alho)
//
// Cria��o:     14 Out 2022
// Atualiza��o: 14 Out 2022
// Compilador:  Visual C++ 2022
//
// Descri��o:   Define armazenamento para objeto de uma cena
//
**********************************************************************************/

#ifndef DXUT_OBJECT_H_
#define DXUT_OBJECT_H_

#include <d3d12.h>
#include "Types.h"
#include "Mesh.h"
#include <DirectXMath.h>
using namespace DirectX;

struct Object
{
	XMFLOAT4X4 world;		// matriz de mundo
	uint cbIndex;			// �ndice para o constant buffer
	SubMesh mesh;			// malha de v�rtices

	Object();				// construtor
};

#endif
