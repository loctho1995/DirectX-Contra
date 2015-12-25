float4x4 WVPMatrix : WorldViewProjection;

float4 lightingPosition : POSITION;
float4 lightingColor;
float lightingCutoff;
float4 lightingDirection : DIRECTION;

float4 lightingPosition2 : POSITION;
float4 lightingColor2;
float lightingCutoff2;
float4 lightingDirection2 : DIRECTION;
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
	float3 temp;
	returnVal = tex2D(SampleType, input.tex);

	temp = returnVal.xyz;
	float4 worldPos = input.worldPos;
	worldPos.w = 0;

	float4 toPixel = worldPos - lightingPosition;
	float4 toPixel2 = worldPos - lightingPosition2;

	
	toPixel = normalize(toPixel);
	toPixel2 = normalize(toPixel2);
	
	float4 normallightD = normalize(lightingDirection);
	float4 normallightD2 = normalize(lightingDirection2);

	float dotProduct = dot(toPixel, normallightD );
	float dotProduct2 = dot(toPixel2, normallightD2);
	float brightness = 0;
	float brightness2 = 0;
	float finalBrighness = 0;
	float lightIntensity = 0;
	float4 totalColorLight = float4(0, 0, 0 ,0 );
	if(dotProduct >= lightingCutoff  || dotProduct2 >= lightingCutoff2 )
	{
		lightIntensity = 1 - AmbientlightIntensity;
		if(dotProduct >= lightingCutoff )
		{
			brightness = ( dotProduct - lightingCutoff ) / ( 1 - lightingCutoff);
			brightness = max (brightness , AmbientlightIntensity );
			totalColorLight = totalColorLight + lightIntensity * brightness *  lightingColor ;
		}
		if( dotProduct2 >= lightingCutoff2)
		{
			brightness2 = ( dotProduct2 - lightingCutoff2 ) / ( 1 - lightingCutoff2);
			brightness2 = max(brightness2, AmbientlightIntensity );
			totalColorLight = totalColorLight + lightIntensity * brightness2 *  lightingColor2;
		}
		finalBrighness = brightness + brightness2;
		finalBrighness = min(finalBrighness, 1.0);
		
		temp = temp * finalBrighness + totalColorLight.xyz ;
	}
	else
	{
		temp = temp *  AmbientlightIntensity;
	}
	
	
	
	
	
	returnVal.x = temp.x;
	returnVal.y = temp.y;
	returnVal.z = temp.z;
	return returnVal ;
}

technique technique0 {
	pass p0 {
		CullMode = None;
		VertexShader = compile vs_2_0 mainVS();
		PixelShader = compile ps_2_0 mainPS();
	}
}