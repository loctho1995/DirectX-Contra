#pragma once

#include "Rect.h"
#include "Graphics.h"

class ViewPort
{
public:
	ViewPort( RectI port);
	void drawTexture(LPDIRECT3DTEXTURE9 pTexture, int width, int height, D3DXVECTOR2 anchorPoint, int x, int y, float xRatio = 1.0f, float yRatio = 1.0f, D3DCOLOR color = D3DCOLOR_ARGB (255,255,255,255) ) const;
	void drawTextureFlipX(  LPDIRECT3DTEXTURE9 pTexture, int width, int height, D3DXVECTOR2 anchorPoint, int x, int y, float xRatio = 1.0f, float yRatio = 1.0f, D3DCOLOR color = D3DCOLOR_ARGB (255,255,255,255)) const;
	void drawTileTmx( std::string tileSetName, int width, int height,int dx, int dy,  int x, int y, D3DCOLOR color = D3DCOLOR_XRGB (255,255,255 )) const;
	void drawTileTmx( LPDIRECT3DTEXTURE9 pTexture, int width, int height,int dx, int dy,  int x, int y, D3DCOLOR color = D3DCOLOR_XRGB (255,255,255 )) const;
	int getWidth();
	int getHeight();
	RectI getPort()	 {return port;} 
private:
	RectI port;
	Graphics* pGraphics;
};