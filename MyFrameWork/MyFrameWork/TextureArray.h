#pragma once

#include "Texture.h"
#include "string"
class TextureArray
{
public:
	TextureArray(std::string fileName, std::string name, std :: string state, const unsigned int nTextures, const unsigned int nFrames, D3DCOLOR colorKey = 0);
	//TextureArray(std::string baseArrayName, const unsigned int nTextures, const unsigned int nFrames, D3DCOLOR colorKey = 0);
	~TextureArray();
	void draw(int x, int y, Camera* cam, float xRatio = 1.0f, float yRatio = 1.0f, D3DCOLOR color = D3DCOLOR_XRGB (255,255,255) ) const;
	void drawFlipX(int x, int y, Camera* cam, float xRatio = 1.0f, float yRatio = 1.0f, D3DCOLOR color = D3DCOLOR_XRGB (255,255,255) ) const;
	void update();
	void setAnchorPoint(float xRatio, float yRatio);
	int getWidth();
	int getHeight();
private:
	const unsigned int nTextures;
	const unsigned int nFrames;
	unsigned int iCurrentTexture;
	unsigned int count;
	Texture** ppTextures;
};
