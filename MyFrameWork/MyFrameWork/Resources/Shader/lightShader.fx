float4x4 WVPMatrix : WorldViewProjection;

float4 lightingPosition : POSITION;
float4 lightingColor;
float lightingCutoff;
float4 lightingDirection : DIRECTION;
float AmbientlightIntensity;

texture shaderTexture;

sampler SampleType =  sampler_state
{
	Texture   = <shaderTexture>;
    Filter = MIN_MAG_MIP_LINEAR;
    AddressU = Wrap;
    AddressV = Wrap;
};



struct VertexInputType
{
    float4 position : POSITION;
    float2 tex : TEXCOORD0;
};

struct PixelInputType
{
    float4 position : SV_POSITION;
    float2 tex : TEXCOORD0;
	float4 worldPos : TEXCOORD01;
};


PixelInputType mainVS(VertexInputType input)
{
	input.position.w = 1.0f;
	PixelInputType returnVal;
	returnVal.position = mul( input.position , WVPMatrix);
	returnVal.tex = input.tex;
	returnVal.worldPos = mul( input.position , WVPMatrix);

	return returnVal;
}

float4 mainPS(PixelInputType input) : COLOR
{
	float4 returnVal;
	
	returnVal = tex2D(SampleType, input.tex);
	
	float4 spotlight;
	float4 worldPos = input.worldPos;
	worldPos.w = 0;
	float4 toPixel = worldPos - lightingPosition;
	toPixel = normalize(toPixel);
	float4 normallightD = normalize(lightingDirection);
	float dotProduct = dot(toPixel, normallightD );
	
	float brightness = 0;
	if(dotProduct >= lightingCutoff)
	{
		brightness = ( dotProduct - lightingCutoff ) / ( 1 - lightingCutoff);
		if(brightness < AmbientlightIntensity)
		{
			brightness = AmbientlightIntensity;
		}
		returnVal  = returnVal * brightness + lightingColor;
	}
	else
	{
		returnVal = returnVal *  AmbientlightIntensity;
	}
	
	return returnVal ;
}

technique technique0 {
	pass p0 {
		CullMode = None;
		VertexShader = compile vs_2_0 mainVS();
		PixelShader = compile ps_2_0 mainPS();
	}
}