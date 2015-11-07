#pragma once
#include "ViewPort.h"
#include "iostream"
class Camera
{
public:
	//void draw(Texture* pTexture,
	Camera( ViewPort* viewPort, RectF rect)
	{
		this ->viewPort = viewPort;
		mapRect = rect;
		setPosition(0.0f, 0.0f);
	}
	void setPosition(float x, float y)
	{ 
		if( this -> x < x - (float)viewPort ->getWidth() / 2.0f)
		{
			this -> x =   x - (float)viewPort ->getWidth() / 2.0f;
			this -> y  = y - (float)viewPort -> getHeight() / 2.0f;

			this -> x = max ( this -> x, mapRect.x );
			this -> y = max ( this -> y, mapRect.y );

			this -> x = min ( this -> x, mapRect.width + mapRect.x - viewPort -> getWidth());
			this -> y = min ( this -> y, mapRect.height + mapRect.y - viewPort -> getHeight());

		}
		
	}
	void drawTexture(LPDIRECT3DTEXTURE9 pTexture, int width, int height, D3DXVECTOR2 anchorPoint, float x, float y, float xRatio = 1.0f, float yRatio = 1.0f, D3DCOLOR color = D3DCOLOR_XRGB (255,255,255) ) const
	{
		viewPort -> drawTexture( pTexture,width, height, anchorPoint, (int)(x - this -> x), (int)(y - this -> y), xRatio, yRatio, color);
	}
	void drawTextureFlipX( LPDIRECT3DTEXTURE9 pTexture, int width, int height, D3DXVECTOR2 anchorPoint, float x, float y, float xRatio = 1.0f, float yRatio = 1.0f, D3DCOLOR color = D3DCOLOR_XRGB (255,255,255 )) const
	{
		viewPort -> drawTextureFlipX(pTexture,width, height, anchorPoint, (int)(x - this -> x), (int)(y - this -> y), xRatio, yRatio, color);
	}

	void drawTileTmx(std::string tiletSetName, int width, int height, int dx, int dy, float x, float y , D3DCOLOR color = D3DCOLOR_XRGB (255,255,255)) const
	{
		viewPort -> drawTileTmx(tiletSetName, width, height, dx, dy, (int)(x - this ->x ),(int) (y - this -> y), color);
	}
	void drawTileTmx(LPDIRECT3DTEXTURE9 pTexture, int width, int height, int dx, int dy, float x, float y , D3DCOLOR color = D3DCOLOR_XRGB (255,255,255)) const
	{
		viewPort -> drawTileTmx(pTexture, width, height, dx, dy, (int)(x - this ->x ),(int) (y - this -> y), color);
	}
	int getWidth()
	{
		return viewPort -> getWidth();
	}
	int getHeight()
	{
		return viewPort -> getHeight();
	}
	float getX()
	{
		return x;
	}
	float getY()
	{
		return y;
	}
	RectF getRect()
	{
		return RectF (x, y,  getWidth(), getHeight());
	}
	void update(float x, float y)
	{
		setPosition(x, y);

	}
private:
	ViewPort* viewPort;
	RectF mapRect;
	float x;
	float y;
	float translatePointX;
	float translatePointY;
};