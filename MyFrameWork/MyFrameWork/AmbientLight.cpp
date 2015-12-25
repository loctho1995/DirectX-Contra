#include "AmbientLight.h"


AmbientLight::AmbientLight(void)
{
	ambientLightIntensity = 1;
	isFadeIn = true;
	isFadeOut  = false;
	nWaitingFrames  = 300;
	fadingFrames  = 120;
	isFading = false;
	nCounter = 0;
}


AmbientLight::~AmbientLight(void)
{
}

void AmbientLight:: update()
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

float  AmbientLight:: getAmbientLightIntensity()
{
	return ambientLightIntensity;
}
void  AmbientLight:: setAmbientLightIntensity( float val )
{
	ambientLightIntensity = val;
}
