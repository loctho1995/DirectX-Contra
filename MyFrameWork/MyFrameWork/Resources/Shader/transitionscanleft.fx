/*

% Description of my shader.
% Second line of description for my shader.

keywords: material classic

date: YYMMDD

*/
struct VS_IN
{
	float3 Pos: POSITION;
	float4 Color: COLOR;
	float2 TexCoord: TEXCOORD;
};

struct VS_OUT
{
	float4 Pos: POSITION;
	float4 Color: COLOR;
	float2 TexCoord: TEXCOORD;
};

float4x4 WorldViewProj : WorldViewProjection;
Texture2D texture0;
Texture2D texture1;
float timer;
float posMove;

SamplerState textureSampler0
{
	Texture = <texture0>;
    Filter = MIN_MAG_MIP_LINEAR;
    AddressU = Wrap;
    AddressV = Wrap;
};

SamplerState textureSampler1
{
	Texture = <texture1>;
    AddressU = Wrap;
    AddressV = Wrap;
};

VS_OUT doVS(VS_IN input)
{
	VS_OUT output;
	output.Pos = mul(float4(input.Pos.xyz, 1.0), WorldViewProj);
	output.TexCoord = input.Pos;
	output.Color = input.Color;
	
	return output;
}

float4 doPX(VS_OUT input) : COLOR
{
	/*
	D3DX9 
	Center: 0, 0
	Top-Left: -1, -1
	Bot-Right: 1, 1
	*/
	
	float2 pos = input.TexCoord;

	float4 color0 = tex2D(textureSampler0, pos);
	float4 color1 = tex2D(textureSampler1, pos);
	
	if(pos.x < posMove)
	{
		return color0;
	}
	else
	{
		return color1;
	}
}

technique technique0 {
	pass p0 {
		CullMode = None;

		VertexShader = compile vs_3_0 doVS();
		PixelShader = compile ps_3_0 doPX();
	}
}
