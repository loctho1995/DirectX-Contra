#pragma once
#include "d3d9.h"
#include <D3dx9tex.h>
#include "string"
#include "Rect.h"
#include "D3dx9core.h"
#include <map>
#include "BitMapFont.h"

class TextureHolder;
extern const unsigned int SCWIDTH;
extern const unsigned int SCHEIGHT;
class Graphics
{
private:
	

	Graphics(HWND hWnd);
private:
	std::map<std::string , TextureHolder* > textureMap;
	static Graphics* instance;
	LPDIRECT3D9 pD3D9; // pointer to an interface of DX
	LPDIRECT3DDEVICE9 pDevice; // pointer to an interface of Dx device;
	LPDIRECT3DSURFACE9 pSurface; // pointer to front Surface
	LPDIRECT3DSURFACE9 pBackBuffer; // pointer to back buffer
	LPD3DXSPRITE pSpriteHandler;
	IDirect3DVertexBuffer9* vBuffer;
	BitMapFont* font;

public:
    bool isAllowPresent;
	//void loadSurface(std::basic_string<TCHAR> filePath ); // just test

	//void showSurface(float x , float y  , float width  , float height ); // just test
	

	//LPDIRECT3DTEXTURE9 loadTexture( std::basic_string<TCHAR > filePath);
	~Graphics();
	static Graphics* getInstance();

	static void create(HWND hWnd);
	
	TextureHolder* getTexture(std::string name);

	void loadTexture(std::string sourceFile, std::string  name , D3DCOLOR colorkey = 0);

	void drawTexture ( LPDIRECT3DTEXTURE9 pTexture, int width, int height, D3DXVECTOR2 anchorPoint, RectI port,int x, int y, float xRatio = 1.0f, float yRatio = 1.0f, D3DCOLOR color = D3DCOLOR_XRGB (255,255,255) ) const;

	void drawTexture ( LPDIRECT3DTEXTURE9 pTexture, int width, int height, RectF sourceRect, int x, int y, float xRatio , float yRatio , D3DCOLOR color = D3DCOLOR_XRGB (255,255,255) ) const;

	void drawTextureFlipX (LPDIRECT3DTEXTURE9 pTexture, int width, int height, D3DXVECTOR2 anchorPoint, RectI port, int x, int y, float xRatio = 1.0f, float yRatio = 1.0f, D3DCOLOR color = D3DCOLOR_XRGB (255,255,255) ) const;

	void drawTileTmx(std:: string name, int width, int height, int dx, int dy, RectI port, int x, int y, D3DCOLOR color = D3DCOLOR_XRGB (255,255,255) ) const;

	void drawTileTmx(LPDIRECT3DTEXTURE9 texture, int width, int height, int dx, int dy, RectI port, int x, int y, D3DCOLOR color = D3DCOLOR_XRGB (255,255,255) ) const;

	void drawText(std:: string text, int size, int x, int y, bool space = false ,D3DCOLOR color = 0xFFFFFFFF);

	void drawText(Label label);

	void setFont(BitMapFont* bitmapFont);

	BitMapFont* getFont();

	void beginRender();

	void endRender();

	LPDIRECT3DDEVICE9 getDevice();

	LPD3DXSPRITE getSpriteHandler();

	void cleanUp();
private:
	void drawChar( LPDIRECT3DTEXTURE9 pTexture, int width, int height, char c, int size, int x, int y, bool space ,D3DCOLOR color = 0xFFFFFFFF );
	
};
class TextureHolder
{
public:
	~TextureHolder()
	{
		if(pTexture)
			pTexture -> Release();
		pTexture = NULL;

	}
	LPDIRECT3DTEXTURE9 pTexture;
	int width;
	int height;
};

