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
		cout << "DirectX Math n�o � suportado pela CPU" << endl;
		return 0;
	}
	
	//   y     z
	//        
	//   ^   ^
	//   |  /
	//   | /
	//   ------->  x

	// c�mera est� 10 unidades na dire��o negativa do eixo z
	XMVECTOR pos = XMVectorSet(0, 0, -10, 1);

	// o alvo da c�mera � a origem do sistema (0,0,0)
	XMVECTOR target = XMVectorZero();

	// dire��o "para cima" coincide com o eixo y do mundo
	XMVECTOR up = XMVectorSet(0, 1, 0, 0);
	
	// calcula matriz de visualiza��o
	XMMATRIX V = XMMatrixLookAtLH(pos, target, up);

	cout << "pos    = " << pos << endl;
	cout << "target = " << target << endl;
	cout << "up     = " << up << endl << endl;
	cout << "V = " << endl << V << endl;

	// um v�rtice na posi��o (0,1,0) nas coordenadas do mundo
	XMVECTOR vertex = XMVectorSet(0, 1, 0, 1);

	// v�rtice transformado para as coordenadas da c�mera
	cout << "vertex = " << XMVector3TransformCoord(vertex,V) << endl << endl << endl;

	// quest�o 1
	cout << "Questao 1" << endl << endl;
	// c�mera est� a 20 unidades na dire��o negativa do eixo x, 35 unidades na dire��o positiva do eixo y e 50 unidades na dire��o negativa do eixo z
	pos = XMVectorSet(-20, 35, -50, 1);
	// o alvo da c�mera � o ponto (10, 0, 30)
	target = XMVectorSet(10, 0, 30, 1);
	// dire��o "para cima" coincide com o eixo y do mundo
	up = XMVectorSet(0, 1, 0, 0);
	// calcula matriz de visualiza��o
	V = XMMatrixLookAtLH(pos, target, up);

	cout << "pos    = " << pos << endl;
	cout << "target = " << target << endl;
	cout << "up     = " << up << endl << endl;
	cout << "Matriz de visualizacao = " << endl << V << endl << endl;

	// quest�o 2
	cout << "Questao 2" << endl << endl;
	// �ngulo de campo de vis�o vertical de 45�
	float vertical_view_field_angle = 45.0f * XM_PI / 180.0f;
	// propor��o da tela de 4/3
	float aspect_ratio = 4.0f / 3.0f;
	// dist�ncia para o plano pr�ximo
	float near_plane_distance = 1.0f;
	// dist�ncia para o plano distante
	float far_plane_distance = 100.0f;
	// calcula matriz de proje��o perspectiva
	V = XMMatrixPerspectiveFovLH(vertical_view_field_angle, aspect_ratio, near_plane_distance, far_plane_distance);

	cout << "angulo do campo de visao vertical = " << vertical_view_field_angle << endl;
	cout << "proporcao da tela                 = " << aspect_ratio << endl;
	cout << "distancia para o plano proximo    = " << near_plane_distance << endl;
	cout << "distancia para o plano distante   = " << far_plane_distance << endl << endl;
	cout << "Matriz de projecao perspectiva = " << endl << V << endl;
	
	return 0;
}
