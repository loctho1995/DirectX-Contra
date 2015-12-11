#pragma once
#include <D3dx9tex.h>
class Lighting
{
public:
	Lighting(void);
	~Lighting(void);
	Lighting(D3DXVECTOR4 position, D3DXVECTOR4 direction, float cutOff,	float ambientLightIntensity, D3DXVECTOR4 color);
	D3DXVECTOR4 getPosition();
	D3DXVECTOR4 getDirection();
	float getCutOff();
	D3DXVECTOR4 getColor();
	void setPosition(float x, float y);
	void setDirection(D3DXVECTOR4 val);
	void setCutOff(float cutoff);
	void setColor(D3DXVECTOR4 val);
	float getAmbientLightIntensity();
	void setAmbientLightIntensity( float val );
	virtual void update();
private:
	// lightingCore
	D3DXVECTOR4 position;
	D3DXVECTOR4 direction;
	float cutOff;
	D3DXVECTOR4 color;
	float ambientLightIntensity;
private:
	// update
	bool isFadeIn;
	bool isFadeOut;
	bool isFading;
	int nWaitingFrames;
	int fadingFrames;
	int nCounter;

};


