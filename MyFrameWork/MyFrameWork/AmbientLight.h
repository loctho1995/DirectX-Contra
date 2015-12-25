#pragma once
#include <D3dx9tex.h>
class AmbientLight
{
public:
	AmbientLight(void);
	~AmbientLight(void);
	void update();
	float getAmbientLightIntensity();
	void setAmbientLightIntensity( float val );
private:
	float ambientLightIntensity;
	bool isFadeIn;
	bool isFadeOut;
	bool isFading;
	int nWaitingFrames;
	int fadingFrames;
	int nCounter;
};

