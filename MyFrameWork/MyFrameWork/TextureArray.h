#pragma once

#include "Texture.h"
#include "string"
class TextureArray
{
public:
	TextureArray(std::string fileName, std::string name, std :: string state, const unsigned int nTextures, const unsigned int nFrames, D3DCOLOR colorKey = 0);
	//TextureArray(std::string baseArrayName, const unsigned int nTextures, const unsigned int nFrames, D3DCOLOR colorKey = 0);
	~TextureArray();
	void draw(int x, int y, Camera* cam, float xRatio = 1.0f, float yRatio = 1.0f, D3DCOLOR color = D3DCOLOR_ARGB (255,255,255,255) ) const;
	void drawFlipX(int x, int y, Camera* cam, float xRatio = 1.0f, float yRatio = 1.0f, D3DCOLOR color = D3DCOLOR_ARGB (255,255,255,255) ) const;
	void update();
	void setAnchorPoint(float xRatio, float yRatio);
	D3DXVECTOR2 getAnchorPoint()
	{
		return ppTextures[iCurrentTexture] -> getAnchorPoint();
	}
	int getWidth();
	int getHeight();
    bool isLastTexture();
    void resetIndex();

private:
	const unsigned int nTextures;
	const unsigned int nFrames;
	unsigned int iCurrentTexture;
	unsigned int count;
	Texture** ppTextures;
};
