#pragma once
#define _USE_MATH_DEFINES
#include "Texture.h"
Texture:: Texture(std::string sourceFile, std::string name, D3DCOLOR colorKey)
{
	/*pTextureHolder = Graphics::getInstance() ->getTexture(name);

	if( pTextureHolder == nullptr)
	{
		Graphics::getInstance() ->loadTexture(sourceFile, name, colorKey);
		pTextureHolder = Graphics::getInstance() ->getTexture(name);
	}*/

	Graphics::getInstance() ->loadTexture(sourceFile, name, colorKey);
	pTextureHolder = Graphics::getInstance() ->getTexture(name);
	anchorPoint = D3DXVECTOR2( 0.0f, 0.0f);
}

Texture:: Texture(std::string name, D3DCOLOR colorKey )
{
	pTextureHolder = Graphics::getInstance() ->getTexture(name);
	anchorPoint = D3DXVECTOR2( 0.0f, 0.0f);
}


void Texture::draw(int x, int y, Camera* cam, float xRatio, float yRatio , D3DCOLOR color) const
{
	//cam-> drawTexture( pTextureHolder ->pTexture, pTextureHolder ->width, pTextureHolder ->height, anchorPoint, x, y, xRatio,yRatio,color);
	Graphics::getInstance() -> drawTexture(pTextureHolder ->pTexture, pTextureHolder ->width, pTextureHolder ->height, anchorPoint, (cam -> getViewport()) ->getPort(), x - cam -> getX() + cam -> getViewport() -> getPort().x , y - cam -> getY() + cam -> getViewport() -> getPort().y ,xRatio, yRatio, color);
}

void Texture:: drawFlipX(int x, int y, Camera* cam, float xRatio, float yRatio, D3DCOLOR color) const
{
	//cam-> drawTextureFlipX( pTextureHolder ->pTexture, pTextureHolder ->width,pTextureHolder -> height, anchorPoint, x, y, xRatio,yRatio,color);
	Graphics::getInstance() -> drawTextureFlipX(pTextureHolder ->pTexture, pTextureHolder ->width, pTextureHolder ->height, anchorPoint, (cam -> getViewport()) ->getPort(), x - cam -> getX() + cam -> getViewport() -> getPort().x , y - cam -> getY() + cam -> getViewport() -> getPort().y ,xRatio, yRatio, color);
}


Texture::~Texture()
{
	/*if(!pTextureHolder ->pTexture )
	{
		pTextureHolder ->pTexture->Release();
		pTextureHolder ->pTexture = NULL;
	}
	if(!pTextureHolder)
	{
		delete pTextureHolder;
		pTextureHolder = NULL;
	}*/
}

void Texture:: setAnchorPoint(float xRatio, float yRatio)
{
	anchorPoint = D3DXVECTOR2(xRatio, yRatio);
}

int Texture :: getWidth()
{
	return pTextureHolder ->width;
}

int Texture:: getHeight()
{
	return pTextureHolder ->height;
}
LPDIRECT3DTEXTURE9 Texture:: getTexture()
{
	return pTextureHolder ->pTexture;
}
D3DXVECTOR2 Texture :: getAnchorPoint()
{
	return anchorPoint;
}
void Texture :: draw(int x, int y, float xRatio, float yRatio, D3DCOLOR color ) const
{
	Graphics::getInstance() -> drawTexture(pTextureHolder ->pTexture, pTextureHolder -> width,
		pTextureHolder -> height, RectF(0,0,pTextureHolder -> width, pTextureHolder -> height),x , y,  xRatio, yRatio,
		 color);
	
}