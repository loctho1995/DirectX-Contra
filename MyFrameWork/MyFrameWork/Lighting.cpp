#include "Lighting.h"


Lighting::Lighting(void)
{
	position = D3DXVECTOR4(0.0f, 0.0f, 0.0f, 0.0f);
	direction = D3DXVECTOR4(0.0f, 0.0f, 0.0f, 0.0f);
	color = D3DXVECTOR4(0.0f, 0.0f, 0.0f, 0.0f);
	cutOff  = 1;
	ambientLightIntensity = 1;
	isFadeIn = false;
	isFadeOut  = true;
	nWaitingFrames  = 300;
	fadingFrames  = 120;
	isFading = false;
	nCounter = 0;


}

Lighting:: Lighting(D3DXVECTOR4 position,
					D3DXVECTOR4 direction,
					float cutOff,
					float ambientLightIntensity,
					D3DXVECTOR4 color)
	:
 position(position),
 direction(direction),
 cutOff(cutOff),
 ambientLightIntensity(ambientLightIntensity),
 color(color)
{
	isFadeIn = false;
	isFadeOut  = true;
	nWaitingFrames  = 300;
	fadingFrames  = 120;
	isFading = false;
	nCounter = 0;
}

D3DXVECTOR4 Lighting:: getPosition()
{
	return position;
}
D3DXVECTOR4 Lighting::  getDirection()
{
	return direction;
}
float Lighting:: getCutOff()
{
	return cutOff;
}
D3DXVECTOR4 Lighting:: getColor()
{
	return color;
}
void Lighting:: setPosition(float x, float y)
{
	position.x = x;
	position.y = y;
}
void Lighting:: setDirection(D3DXVECTOR4 val)
{
	direction = val;
}
void Lighting:: setCutOff(float cutoff)
{
	cutOff = cutoff;
}
void Lighting:: setColor(D3DXVECTOR4 val)
{
	color = color;
}

float  Lighting:: getAmbientLightIntensity()
{
	return ambientLightIntensity;
}
void  Lighting:: setAmbientLightIntensity( float val )
{
	ambientLightIntensity = val;
}

void Lighting:: update()
{
	nCounter++;
	if(isFadeOut)
	{
		if( !isFading )
		{
			if((nCounter %= nWaitingFrames) == 0)
			{
				isFading = true;
			}
		}
		else
		{
			if((nCounter %= fadingFrames) == 0)
			{
				isFading = false;
				isFadeOut  = false;
				isFadeIn = true;
			}
			ambientLightIntensity += 1.0f / (float)fadingFrames;
			ambientLightIntensity = min (ambientLightIntensity, 1.0f);
		}
		
	}
	else if(isFadeIn)
	{
		if( !isFading )
		{
			if((nCounter %= nWaitingFrames) == 0)
			{
				isFading = true;
			}
		}
		else
		{
			ambientLightIntensity -= 1.0f / (float)fadingFrames;
			ambientLightIntensity = max (ambientLightIntensity, 0.0f);
			if((nCounter %= fadingFrames) == 0)
			{
				isFading = false;
				isFadeOut  = true;
				isFadeIn = false;
			}
			
		}
	}
}

Lighting::~Lighting(void)
{
}
