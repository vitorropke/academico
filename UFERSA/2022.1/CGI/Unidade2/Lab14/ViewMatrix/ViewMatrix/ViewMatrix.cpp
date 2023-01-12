#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <iostream>
using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

// sobrecarrega operador << para usar cout com XMVECTOR
ostream& XM_CALLCONV operator << (ostream& os, FXMVECTOR v)
{
	XMFLOAT4 dest;
	XMStoreFloat4(&dest, v);

	os << "(" << dest.x << ", " << dest.y << ", " << dest.z << ", " << dest.w << ")";
	return os;
}

// sobrecarrega operador << para usar cout com XMMATRIX
ostream& XM_CALLCONV operator << (ostream& os, FXMMATRIX m)
{
	for (int i = 0; i < 4; ++i)
	{
		os << left; os.width(5); os << XMVectorGetX(m.r[i]) << ' ';
		os << left; os.width(5); os << XMVectorGetY(m.r[i]) << ' ';
		os << left; os.width(5); os << XMVectorGetZ(m.r[i]) << ' ';
		os << left; os.width(5); os << XMVectorGetW(m.r[i]) << ' ';
		os << '\n';
	}
	return os;
}

int main()
{
	// verifica suporte a SSE2
	if (!XMVerifyCPUSupport())
	{
		cout << "DirectX Math não é suportado pela CPU" << endl;
		return 0;
	}
	
	//   y     z
	//        
	//   ^   ^
	//   |  /
	//   | /
	//   ------->  x

	// câmera está 10 unidades na direção negativa do eixo z
	XMVECTOR pos = XMVectorSet(0, 0, -10, 1);

	// o alvo da câmera é a origem do sistema (0,0,0)
	XMVECTOR target = XMVectorZero();

	// direção "para cima" coincide com o eixo y do mundo
	XMVECTOR up = XMVectorSet(0, 1, 0, 0);
	
	// calcula matriz de visualização
	XMMATRIX V = XMMatrixLookAtLH(pos, target, up);

	cout << "pos    = " << pos << endl;
	cout << "target = " << target << endl;
	cout << "up     = " << up << endl << endl;
	cout << "V = " << endl << V << endl;

	// um vértice na posição (0,1,0) nas coordenadas do mundo
	XMVECTOR vertex = XMVectorSet(0, 1, 0, 1);

	// vértice transformado para as coordenadas da câmera
	cout << "vertex = " << XMVector3TransformCoord(vertex,V) << endl << endl << endl;

	// questão 1
	cout << "Questao 1" << endl << endl;
	// câmera está a 20 unidades na direção negativa do eixo x, 35 unidades na direção positiva do eixo y e 50 unidades na direção negativa do eixo z
	pos = XMVectorSet(-20, 35, -50, 1);
	// o alvo da câmera é o ponto (10, 0, 30)
	target = XMVectorSet(10, 0, 30, 1);
	// direção "para cima" coincide com o eixo y do mundo
	up = XMVectorSet(0, 1, 0, 0);
	// calcula matriz de visualização
	V = XMMatrixLookAtLH(pos, target, up);

	cout << "pos    = " << pos << endl;
	cout << "target = " << target << endl;
	cout << "up     = " << up << endl << endl;
	cout << "Matriz de visualizacao = " << endl << V << endl << endl;

	// questão 2
	cout << "Questao 2" << endl << endl;
	// ângulo de campo de visão vertical de 45º
	float vertical_view_field_angle = 45.0f * XM_PI / 180.0f;
	// proporção da tela de 4/3
	float aspect_ratio = 4.0f / 3.0f;
	// distância para o plano próximo
	float near_plane_distance = 1.0f;
	// distância para o plano distante
	float far_plane_distance = 100.0f;
	// calcula matriz de projeção perspectiva
	V = XMMatrixPerspectiveFovLH(vertical_view_field_angle, aspect_ratio, near_plane_distance, far_plane_distance);

	cout << "angulo do campo de visao vertical = " << vertical_view_field_angle << endl;
	cout << "proporcao da tela                 = " << aspect_ratio << endl;
	cout << "distancia para o plano proximo    = " << near_plane_distance << endl;
	cout << "distancia para o plano distante   = " << far_plane_distance << endl << endl;
	cout << "Matriz de projecao perspectiva = " << endl << V << endl;
	
	return 0;
}
