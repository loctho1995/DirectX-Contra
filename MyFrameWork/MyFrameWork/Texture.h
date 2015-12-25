#pragma once


#include "string"
#include "Camera.h"
#include "ViewPort.h"
class Graphics;
class Texture
{
private:
	//LPD3DXSPRITE pSpriteHandler;
	TextureHolder * pTextureHolder;
	D3DXVECTOR2 anchorPoint;
public:
	Texture(std::string sourceFile, std::string name, D3DCOLOR colorKey = 0);
	Texture(std::string name, D3DCOLOR colorKey = 0);
	~Texture();
	void draw(int x, int y, Camera* cam, float xRatio = 1.0f, float yRatio = 1.0f, D3DCOLOR color = D3DCOLOR_ARGB (255,255,255,255) ) const;
	void drawFlipX(int x, int y, Camera* cam, float xRatio = 1.0f, float yRatio = 1.0f, D3DCOLOR color = D3DCOLOR_ARGB (255,255,255,255) ) const;
	void draw(int x, int y, float xRatio = 1.0f, float yRatio = 1.0f, D3DCOLOR color = D3DCOLOR_XRGB (255,255,255) ) const;
	void setAnchorPoint(float xRatio, float yRatio ); // setAnchorPoint of Texture
	D3DXVECTOR2 getAnchorPoint();
	int getWidth();
	int getHeight();
	
	LPDIRECT3DTEXTURE9 getTexture();


	
};

