/**********************************************************************************
// Vertex (Arquivo de Sombreamento)
//
// Cria��o:     22 Jul 2020
// Atualiza��o: 25 Set 2021
// Compilador:  D3DCompiler
//
// Descri��o:   Um vertex shader simples que apenas passa a posi��o e cor
//              do v�rtice para frente sem realizar nenhuma transforma��o.
//
**********************************************************************************/

cbuffer cbPerObject : register(b0)
{
    float4x4 WorldViewProj;
    // quest�o 2
    float gTime;
};

struct VertexIn
{
    float3 PosL  : POSITION;
    float4 Color : COLOR;
};

struct VertexOut
{
    float4 PosH  : SV_POSITION;
    float4 Color : COLOR;
};

VertexOut main(VertexIn vin)
{
    VertexOut vout;

    // quest�o 2
    vin.PosL.xy += 0.5f * sin(vin.PosL.x) * sin(3.0f * gTime);
    vin.PosL.z *= 0.6f + 0.4f * sin(2.0f * gTime);

    // transforma para espa�o homog�neo de recorte
    vout.PosH = mul(float4(vin.PosL, 1.0f), WorldViewProj);

    // apenas passa a cor do v�rtice para o pixel shader
    vout.Color = vin.Color;

    return vout;
}