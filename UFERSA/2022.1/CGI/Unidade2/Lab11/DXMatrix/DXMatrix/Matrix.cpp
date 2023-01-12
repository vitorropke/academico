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

	XMMATRIX A(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 2.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 4.0f, 0.0f,
		1.0f, 2.0f, 3.0f, 1.0f
	);

	XMMATRIX B = XMMatrixIdentity();

	// multiplicação de matrizes
	XMMATRIX C = A * B;

	// calculando a transposta
	XMMATRIX D = XMMatrixTranspose(A);

	// calculando a inversa
	XMVECTOR det = XMMatrixDeterminant(A);
	XMMATRIX E = XMMatrixInverse(&det, A);

	XMMATRIX F = A * E;

	cout << "A = " << endl << A << endl;
	cout << "B = " << endl << B << endl;
	cout << "C = A*B = " << endl << C << endl;
	cout << "D = Transposta(A) = " << endl << D << endl;
	cout << "det = Determinante(A) = " << endl << det << endl << endl;
	cout << "E = Inversa(A) = " << endl << E << endl;
	cout << "F = A*E = " << endl << F << endl << endl << endl;

	// questão 1
	cout << "Questao 1" << endl << endl;
	// item a
	/*
		-2	0	3
		4	1	-1
	*/
	XMMATRIX G(
		-2.0f, 0.0f, 3.0f, 0.0f,
		4.0f, 1.0f, -1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f
	);
	/*
		2	-1
		0	6
		2	-3
	*/
	XMMATRIX H(
		2.0f, -1.0f, 0.0f, 0.0f,
		0.0f, 6.0f, 0.0f, 0.0f,
		2.0f, -3.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f
	);
	// produto de matrizes
	cout << "a) G x H = " << endl << G * H << endl;
	// item b
	/*
		2	0	2
		0	-1	-3
		0	0	1
	*/
	XMMATRIX I(
		2.0f, 0.0f, 2.0f, 0.0f,
		0.0f, -1.0f, -3.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f
	);
	/*
		1
		2
		1
	*/
	XMMATRIX J(
		1.0f, 0.0f, 0.0f, 0.0f,
		2.0f, 0.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f
	);
	// produto de matrizes
	cout << "b) I x J = " << endl << I * J << endl << endl<< endl;
	
	// questão 2
	cout << "Questao 2" << endl << endl;
	// item a
	/*
		1	2	3
	*/
	XMMATRIX K(
		1.0f, 2.0f, 3.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f
	);
	// calculando a transposta
	cout << "a) Transposta = " << endl << XMMatrixTranspose(K) << endl;
	// item b
	/*
		1	0	0
		0	1	0
		0	0	1
	*/
	XMMATRIX L(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f
	);
	// calculando a transposta
	cout << "a) Transposta = " << endl << XMMatrixTranspose(L) << endl << endl << endl;

	// questão 4
	cout << "Questao 4" << endl << endl;
	// item a
	/*
		1	2	3
		0	4	5
		0	0	0
	*/
	XMMATRIX M(
		1.0f, 2.0f, 3.0f, 0.0f,
		0.0f, 4.0f, 5.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f
	);
	// calculando a inversa
	XMVECTOR Mdet = XMMatrixDeterminant(M);
	cout << "a) Inversa = " << endl << XMMatrixInverse(&Mdet, M);
	cout << "Nao tem inversa" << endl << endl << endl;

	// questão 5
	cout << "Questao 5" << endl << endl;
	// item a
	/*
		21	-4
		10	7
	*/
	XMMATRIX N(
		21.0f, -4.0f, 0.0f, 0.0f,
		10.0f, 7.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
	// calculando a inversa
	XMVECTOR Ndet = XMMatrixDeterminant(N);
	cout << "a) Inversa = " << endl << XMMatrixInverse(&Ndet, N) << endl;
	// item b
	/*
		2	0	0
		0	3	0
		0	0	7
	*/
	XMMATRIX O(
		2.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 3.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 7.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
	// calculando a inversa
	XMVECTOR Odet = XMMatrixDeterminant(O);
	cout << "b) Inversa = " << endl << XMMatrixInverse(&Odet, O) << endl;

	return 0;
}
