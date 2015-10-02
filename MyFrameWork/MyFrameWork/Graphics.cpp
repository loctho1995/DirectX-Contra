
#include "Graphics.h"



Graphics*  Graphics :: instance = nullptr;
const unsigned int SCWIDTH = 240;
const unsigned int SCHEIGHT = 240;
Graphics :: Graphics(HWND hWnd)
{
	pD3D9 = Direct3DCreate9( D3D_SDK_VERSION );

    D3DPRESENT_PARAMETERS d3dpp;
    ZeroMemory( &d3dpp,sizeof( d3dpp ) );

    d3dpp.Windowed			= TRUE;
	d3dpp.BackBufferCount	= 1;
	d3dpp.BackBufferFormat	= D3DFMT_UNKNOWN;
	d3dpp.BackBufferHeight	= SCHEIGHT;
	d3dpp.BackBufferWidth	= SCWIDTH;
	d3dpp.hDeviceWindow		= hWnd;
	d3dpp.SwapEffect		= D3DSWAPEFFECT_DISCARD;

    pD3D9->CreateDevice( D3DADAPTER_DEFAULT,D3DDEVTYPE_HAL,hWnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_PUREDEVICE,&d3dpp,&pDevice );
	D3DXCreateSprite(pDevice,&pSpriteHandler);

}
void Graphics :: create (HWND hWnd)
{
	if( instance == nullptr )
		instance = new Graphics(hWnd);
}

Graphics* Graphics :: getInstance()
{
	return instance;
}

Graphics :: ~Graphics()
{
	if( !pD3D9 )
	{
		pD3D9 -> Release();
		pD3D9 = NULL;
	}
	if( !pDevice )
	{
		pDevice -> Release();
		pDevice = NULL;
	}
	if( !pSurface )
	{
		pSurface ->Release();
		pSurface = NULL;
	}
	if( !pBackBuffer )
	{
		pBackBuffer ->Release();
		pBackBuffer = NULL;
	}
		if(!pSpriteHandler )
	{
		pSpriteHandler ->Release();
		pSpriteHandler = NULL;
	}
}

void Graphics:: beginRender()
{
	pDevice -> Clear (0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(60,60,60), 0.0f, 0 );
	pDevice->BeginScene();
	pSpriteHandler -> Begin(D3DXSPRITE_ALPHABLEND);
	//pSpriteHandler -> Begin(D3DXSPRITE_SORT_TEXTURE);
}

void Graphics :: endRender()
{
	pSpriteHandler -> End();
	pDevice->EndScene();
	pDevice -> Present(NULL, NULL, NULL, NULL );
}

void Graphics :: loadTexture(std:: string sourceFile, std::string name, D3DCOLOR colorkey)
{

	if(textureMap.find(name) == textureMap.end())
	{
			TextureHolder* textureHolder;
			textureHolder = new TextureHolder();
			std::wstring tempSourceFile(sourceFile.begin(), sourceFile.end());

			D3DXIMAGE_INFO imgInfo;
			D3DXGetImageInfoFromFile (tempSourceFile.c_str(), &imgInfo);
			D3DXCreateTextureFromFileEx(
				pDevice,
				tempSourceFile.c_str(),
				D3DX_DEFAULT_NONPOW2,
				D3DX_DEFAULT_NONPOW2,
				1,
				D3DUSAGE_DYNAMIC,
				D3DFMT_UNKNOWN,
				D3DPOOL_DEFAULT,
				D3DX_DEFAULT,
				D3DX_DEFAULT,
				colorkey,
				&imgInfo,
				NULL,
				&textureHolder->pTexture);
			textureHolder -> width = imgInfo.Width;
			textureHolder -> height = imgInfo.Height;
			textureMap[name] = textureHolder;
	}
}

void Graphics :: drawTexture ( LPDIRECT3DTEXTURE9 pTexture, int width, int height,  D3DXVECTOR2 anchorPoint, RectI port, int x, int y, float xRatio , float yRatio , D3DCOLOR color  ) const
{
	RectF rect((float)x - (float)anchorPoint.x * width, (float)y - (float)anchorPoint .y * height, (float)width, (float)height);
	rect.clip(port);

	RECT r;
	if( rect.height == 0|| rect.width == 0 )
	{
		r.left = 0;
		r.bottom = 0;
		r.right = 0;
		r.top = 0;
	}
	else
	{
		r.left = rect.x - (x - (float)anchorPoint.x * width );
		r.top = rect. y - (y - (float)anchorPoint .y * height);
		r.bottom = r.top + rect.height;
		r.right = r.left + rect.width;
	}
	


	D3DXVECTOR3 position(x - anchorPoint.x * width + r.left, y  - anchorPoint.y * height  + r.top, 1.0f);
	D3DXMATRIX matrix;
	D3DXVECTOR2 centerPoint(x + width / 2, y + height / 2 );

	D3DXMatrixTransformation2D(
								&matrix,
								&D3DXVECTOR2(x,y),
								0.0f,
								&D3DXVECTOR2(xRatio,yRatio),
								&D3DXVECTOR2(x + height / 2, y + height / 2),
								0.0f,
								NULL);

	pSpriteHandler->SetTransform( &matrix);

	//pSpriteHandler -> Begin(D3DXSPRITE_ALPHABLEND);
	pSpriteHandler ->Draw(pTexture, &r, NULL, &position, color);
	//pSpriteHandler -> End();
}

void Graphics :: drawTextureFlipX ( LPDIRECT3DTEXTURE9 pTexture, int width, int height, D3DXVECTOR2 anchorPoint, RectI port, int x, int y, float xRatio , float yRatio , D3DCOLOR color)  const
{
	RectF rect((float)x - (float)anchorPoint.x * width, (float)y - (float)anchorPoint .y * height, (float)width, (float)height);
	rect.clip(port);

	RECT r;
	RECT temp;
	if( rect.height == 0|| rect.width == 0 )
	{
		r.left = 0;
		r.bottom = 0;
		r.right = 0;
		r.top = 0;
	}
	else
	{
		r.left = (rect.x - (x - (float)anchorPoint.x * width ) );
		r.top =  (rect. y - (y - (float)anchorPoint .y * height) );
		
		temp = r;
		if( r. left != 0 )
		{
			r.left = 0;
		}
		r.bottom = r.top + rect.height;
		r.right = r.left + rect.width;
	}

	D3DXVECTOR3 position(x - anchorPoint.x * width + r.left, y  - anchorPoint.y * height  + r.top, 1.0f);
	D3DXMATRIX matrix;
	D3DXVECTOR2 centerPoint(x + width / 2, y + height / 2 );

	D3DXMatrixTransformation2D(
								&matrix,
								&D3DXVECTOR2(x ,y),
								0.0f,
								&D3DXVECTOR2(-xRatio,yRatio),
								&D3DXVECTOR2(x + height / 2, y + height / 2),
								0.0f,
								NULL);

	pSpriteHandler->SetTransform( &matrix);
	
	pSpriteHandler ->Draw(pTexture, &r, NULL, &position, color);

}

void Graphics :: drawTileTmx(std::string name ,int width, int height, int dx, int dy,RectI port, int x, int y, D3DCOLOR color ) const
{
	//LPDIRECT3DTEXTURE9 texture = textureMap.at(name) ->texture;
	RectF rect((float)x , (float)y , (float)width, (float)height);
	rect.clip(port);

	RECT r;
	/*if( rect.height == 0|| rect.width == 0 )
	{
		r.left = 0;
		r.bottom = 0;
		r.right = 0;
		r.top = 0;
	}*/
	//else
	{
		r.left = rect.x - x  + dx;
		r.top = rect. y - y  + dy;
		r.bottom = r.top + rect.height;
		r.right = r.left + rect.width;
	}
	
	D3DXMATRIX matrix;
	D3DXVECTOR2 centerPoint(x + width / 2, y + height / 2 );

	D3DXMatrixTransformation2D(
								&matrix,
								&D3DXVECTOR2(x ,y),
								0.0f,
								&D3DXVECTOR2(1.0f,1.0f),
								&D3DXVECTOR2(x + height / 2, y + height / 2),
								0.0f,
								NULL);

	pSpriteHandler->SetTransform( &matrix);

	D3DXVECTOR3 position(x  + r.left - dx, y  + r.top - dy, 1.0f);

	pSpriteHandler ->Draw(textureMap.find(name) ->second ->pTexture, &r, NULL, &position, color );
	
}

void Graphics :: drawTileTmx(LPDIRECT3DTEXTURE9 texture ,int width, int height, int dx, int dy,RectI port, int x, int y, D3DCOLOR color ) const
{
	//LPDIRECT3DTEXTURE9 texture = textureMap.at(name) ->texture;
	RectF rect((float)x , (float)y , (float)width, (float)height);
	rect.clip(port);

	RECT r;
	/*if( rect.height == 0|| rect.width == 0 )
	{
		r.left = 0;
		r.bottom = 0;
		r.right = 0;
		r.top = 0;
	}*/
	//else
	{
		r.left = rect.x - x  + dx;
		r.top = rect. y - y  + dy;
		r.bottom = r.top + rect.height;
		r.right = r.left + rect.width;
	}
	
	D3DXMATRIX matrix;
	D3DXVECTOR2 centerPoint(x + width / 2, y + height / 2 );

	D3DXMatrixTransformation2D(
								&matrix,
								&D3DXVECTOR2(x ,y),
								0.0f,
								&D3DXVECTOR2(1.0f,1.0f),
								&D3DXVECTOR2(x + height / 2, y + height / 2),
								0.0f,
								NULL);

	pSpriteHandler->SetTransform( &matrix);

	D3DXVECTOR3 position(x  + r.left - dx, y  + r.top - dy, 1.0f);

	pSpriteHandler ->Draw(texture, &r, NULL, &position, color );
	
}

void Graphics :: drawText(std::string text, RectI rect)
{
	ID3DXFont *font;
	std::wstring tempSourceFile(text.begin(), text.end());
	
	// 
	D3DXCreateFont(  
    pDevice,
    20,	// Font size
    0,  // Default width
    FW_NORMAL, // Font weight
    0, // MipMap
     false, // Italic
    DEFAULT_CHARSET, // Charset
    OUT_DEFAULT_PRECIS, // Output precision
    DEFAULT_QUALITY, // Quality
    FF_DONTCARE, // Default pitch & family
    L"Arial", // Font name
    &font );// Font object

	RECT r;
	r.top = rect.y;
	r.left = rect.x;
	r.bottom = rect.y + rect.height;
	r.right = rect.x + rect.width;
	
	font ->DrawText(pSpriteHandler, tempSourceFile.c_str(), text.length(),&r, DT_CENTER,D3DCOLOR_ARGB(255, 0, 0, 255));
	//DrawText(NULL, tempSourceFile.c_str(), text.length(),&r, DT_CENTER);
}

TextureHolder* Graphics :: getTexture(std::string name)
{
	if(textureMap.find(name) != textureMap.end())
	{
		return textureMap.find(name) ->second;
	}
	else
	{
		return nullptr;
	}
}

//void Graphics::loadSurface(std::basic_string<TCHAR> filePath)
//{
//	HRESULT result;
//
//	D3DXIMAGE_INFO imgInfo;
//
//	D3DXGetImageInfoFromFile(filePath.c_str(),&imgInfo);
//
//	result = pDevice -> CreateOffscreenPlainSurface(imgInfo.Width, imgInfo.Height, D3DFMT_X8R8G8B8, D3DPOOL_DEFAULT, &pSurface, NULL);
//
//	if(result != D3D_OK)
//	return;
//
//	result = D3DXLoadSurfaceFromFile(pSurface,NULL,NULL,filePath.c_str(),NULL,D3DX_DEFAULT,0,&imgInfo);
//	pDevice ->GetBackBuffer(0,0,D3DBACKBUFFER_TYPE_MONO,&pBackBuffer);
//	
//}

//void Graphics::showSurface(float x  , float y  , float width  , float height )
//{
//	loadSurface(L"Rectangle.png");
//	RECT des;
//	des.top = y;
//	des.bottom = height + y;
//	des.left = x;
//	des.right = x + width;
//	//pDevice->BeginScene();
//	pDevice->StretchRect( pSurface, NULL, pBackBuffer,&des, D3DTEXF_NONE);
//	//pDevice->EndScene();
//}

//LPDIRECT3DTEXTURE9 Graphics:: loadTexture ( std::basic_string<TCHAR> filePath )
//{
//	LPDIRECT3DTEXTURE9 image = NULL;
//
//	HRESULT result;
//	D3DXIMAGE_INFO imgInfo;
//	result = D3DXGetImageInfoFromFile (filePath.c_str(), & imgInfo);
//	result = D3DXCreateTextureFromFileEx(
//										pDevice,
//										filePath.c_str(),
//										imgInfo.Width,
//										imgInfo.Height,
//										1,
//										D3DUSAGE_DYNAMIC,
//										D3DFMT_UNKNOWN,
//										D3DPOOL_DEFAULT,
//										D3DX_DEFAULT,
//										D3DX_DEFAULT,
//										D3DCOLOR_XRGB(0,0,0),
//										&imgInfo,
//										NULL,
//										&image);
//	return image;
//}

//void Graphics :: DrawTexture(int x, int y)
//{
//	LPD3DXSPRITE pSpriteHandler;
//	LPDIRECT3DTEXTURE9 image = loadTexture(L"Rectangle.png");
//	D3DXCreateSprite(pDevice, &pSpriteHandler);
//	D3DXVECTOR3 position(x, y, 1.0f);
//
//	D3DXMATRIX matrix;
//	D3DXVECTOR2 centerPoint(x + 64, y + 64 );
//	D3DXMatrixAffineTransformation2D(
//								&matrix,
//								1.0f,
//								&centerPoint,
//								1.0f,
//								NULL);
//	pSpriteHandler->SetTransform( &matrix);
//	pSpriteHandler -> Begin(D3DXSPRITE_ALPHABLEND);
//	pSpriteHandler ->Draw(image, NULL, NULL, &position, D3DCOLOR_XRGB(255,255,255));
//	pSpriteHandler -> End();
//}