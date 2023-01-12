#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <iostream>
using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

// sobrecarrega operador << para usar cout com XMVECTOR
ostream& XM_CALLCONV operator << (ostream& os, FXMVECTOR v)
{
	XMFLOAT3 dest;
	XMStoreFloat3(&dest, v);

	os << "(" << dest.x << ", " << dest.y << ", " << dest.z << ")";
	return os;
}

int main()
{
	cout.setf(ios_base::boolalpha);

	// verifica suporte a SSE2
	if (!XMVerifyCPUSupport())
	{
		cout << "DirectX Math não é suportado pela CPU" << endl;
		return 0;
	}

	// vetores
	XMVECTOR n = XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);
	XMVECTOR u = XMVectorSet(1.0f, 2.0f, 3.0f, 0.0f);
	XMVECTOR v = XMVectorSet(-2.0f, 1.0f, -3.0f, 0.0f);
	XMVECTOR w = XMVectorSet(0.707f, 0.707f, 0.0f, 0.0f);

	// escalares
	const int c = 2;
	const int k = 5;

	// soma: XMVECTOR operator + 
	XMVECTOR a = u + v;

	// subtração: XMVECTOR operator - 
	XMVECTOR b = u - v;

	// multiplicação por escalar: XMVECTOR operator * 
	XMVECTOR C = 10.0f * u;

	// comprimento do vetor: ||u||
	XMVECTOR L = XMVector3Length(u);

	// normalização do vetor: u / ||u||
	XMVECTOR d = XMVector3Normalize(u);

	// produto escalar: u dot v
	XMVECTOR s = XMVector3Dot(u, v);

	// produto vetorial: u x v
	XMVECTOR e = XMVector3Cross(u, v);

	
	// o vetor n já está normalizado?
	bool equal = XMVector3Equal(n, XMVector3Normalize(n));
	
	// o ângulo entre os vetores n e w deve ser 45 graus
	XMVECTOR angleVec = XMVector3AngleBetweenVectors(n, w);
	float angleRadians = XMVectorGetX(angleVec);
	float angleDegrees = XMConvertToDegrees(angleRadians);

	cout << "u                   = " << u << endl;
	cout << "v                   = " << v << endl;
	cout << "w                   = " << w << endl;
	cout << "n                   = " << n << endl;
	cout << "a = u + v           = " << a << endl;
	cout << "b = u - v           = " << b << endl;
	cout << "C = 10 * u          = " << C << endl;
	cout << "d = u / ||u||       = " << d << endl;
	cout << "e = u x v           = " << e << endl;
	cout << "L = ||u||           = " << L << endl;
	cout << "s = u.v             = " << s << endl;
	cout << "n normalizado       = " << equal << endl;
	cout << "angle               = " << angleDegrees << endl << endl << endl;

	// questão 3
	cout << "Questao 3" << endl << endl;
	// item a
	if (XMVector3Equal(u + v, v + u))
		cout << "a. u + v = v + u" << endl;
	// item b
	if (XMVector3Equal(u + (v + w), (u + v) + w))
		cout << "b. u + (v + w) = (u + v) + w" << endl;
	// item c
	if (XMVector3Equal((c * k) * u, c * (k * u)))
		cout << "c. (ck)u = c(ku)" << endl;
	// item d
	if (XMVector3Equal(k * (u + v), k * u + k * v))
		cout << "d. k(u + v) = ku + kv" << endl;
	// item e
	if (XMVector3Equal(u * (k + c), u * k + u * c))
		cout << "e. u(k + c) = uk + uc" << endl << endl << endl;

	// questão 4
	cout << "Questao 4" << endl << endl;
	// item a
	if (XMVector3Equal(XMVector3Dot(u, v), XMVector3Dot(v, u)))
		cout << "a. u.v = v.u" << endl;
	// item b
	if (XMVector3Equal(XMVector3Dot(u, v + w), XMVector3Dot(u, v) + XMVector3Dot(u, w)))
		cout << "b. u.(v + w) = u.v + u.w" << endl;
	// item c
	if (XMVector3Equal(k * XMVector3Dot(u, v), XMVector3Dot(k * u, v)) and (XMVector3Equal(k * XMVector3Dot(u, v), XMVector3Dot(u, k * v))))
		cout << "c. k(u.v) = (ku).v = u.(kv)" << endl;
	// item d
	if (XMVector3Equal(XMVector3Dot(v, v), XMVector3Length(v) * XMVector3Length(v)))
		cout << "d. v.v = |v|^2" << endl;
	else
		cout << XMVector3Dot(v, v) << XMVector3Length(v) * XMVector3Length(v) << endl;
	// item e
	if (XMVector3Equal(XMVector3Dot(XMVectorZero(), v), XMVectorZero()))
		cout << "e. 0.v = 0" << endl;

	return 0;
}
