
#include "Graphics.h"



Graphics*  Graphics :: instance = nullptr;
const unsigned int SCWIDTH = 256;
const unsigned int SCHEIGHT = 256;
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

    this->isAllowPresent = true;
}
void Graphics :: create (HWND hWnd)
{
    if (instance == nullptr)
    {
        instance = new Graphics(hWnd);
    }
}

Graphics* Graphics :: getInstance()
{
	return instance;
}


LPDIRECT3DDEVICE9 Graphics :: getDevice()
{
	return pDevice;
}
LPD3DXSPRITE Graphics :: getSpriteHandler()
{
	return pSpriteHandler;
}

Graphics :: ~Graphics()
{


	for (auto it = textureMap.begin(); it != textureMap.begin(); it++)
	{
		if(it -> second)
		{
			delete it -> second;
		}
	}


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
	pDevice -> Clear (0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0 ,0 , 0), 0.0f, 0 );
	pDevice->BeginScene();
	//pSpriteHandler -> Begin(D3DXSPRITE_ALPHABLEND);
	//pSpriteHandler -> Begin(D3DXSPRITE_SORT_TEXTURE);
}

void Graphics :: endRender()
{
	//pSpriteHandler -> End();
	pDevice->EndScene();
    if (isAllowPresent)
        pDevice->Present(NULL, NULL, NULL, NULL);
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
	if(rect.width <= 0 || rect.height <= 0)
		return;
	RECT r;

	r.left = rect.x - (x - (float)anchorPoint.x * width );
	r.top = rect. y - (y - (float)anchorPoint .y * height);
	r.bottom = r.top + rect.height;
	r.right = r.left + rect.width;

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

void Graphics :: drawTexture ( LPDIRECT3DTEXTURE9 pTexture, int width, int height, RectF sourceRect, int x, int y, float xRatio , float yRatio , D3DCOLOR color  ) const
{
	RECT r;

	r.left = sourceRect.x;
	r.top = sourceRect. y;
	r.bottom = r.top + sourceRect.height;
	r.right = r.left + sourceRect.width;

	D3DXVECTOR3 position(x , y , 1.0f);
	D3DXMATRIX matrix;
	D3DXVECTOR2 centerPoint(x + width / 2, y + height / 2 );

	D3DXMatrixTransformation2D(
								&matrix,
								NULL,
								0.0f,
								&D3DXVECTOR2(xRatio,yRatio),
								&D3DXVECTOR2(x + height / 2, y + height / 2),
								0.0f,
								NULL);

	pSpriteHandler->SetTransform( &matrix);
	pSpriteHandler ->Draw(pTexture, &r, NULL, &position, color);

}
void Graphics :: drawTextureFlipX ( LPDIRECT3DTEXTURE9 pTexture, int width, int height, D3DXVECTOR2 anchorPoint, RectI port, int x, int y, float xRatio , float yRatio , D3DCOLOR color)  const
{
	RectF rect((float)x - (float)anchorPoint.x * width, (float)y - (float)anchorPoint .y * height, (float)width, (float)height);
	rect.clip(port);
	if(rect.width <= 0 || rect.height <= 0)
		return;
	RECT r;
	RECT temp;
	/*if( rect.height == 0|| rect.width == 0 )
	{
		r.left = 0;
		r.bottom = 0;
		r.right = 0;
		r.top = 0;
	}
	else*/
	{
		r.left =  (rect.x - (x - (float)anchorPoint.x * width ) );
		r.top =  (rect. y - (y - (float)anchorPoint .y * height) );
		
		temp = r;
		if( r. left != 0 )
		{
			r.left = 0;
		}
		else
		{
			r.left = width - rect.width;
		}
		r.bottom = r.top + rect.height;
		r.right = r.left + rect.width;
	}

	D3DXVECTOR3 position(x - anchorPoint.x * width + r.left, y  - anchorPoint.y * height  + r.top, 1.0f);
	D3DXMATRIX matrix;
	D3DXVECTOR2 centerPoint(x + width / 2, y + height / 2 );

	D3DXMatrixTransformation2D(
								&matrix,
								&D3DXVECTOR2(x + rect.width * (0.5f - anchorPoint.x ), y),
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
	
	r.left = rect.x - x  + dx;
	r.top = rect. y - y  + dy;
	r.bottom = r.top + rect.height;
	r.right = r.left + rect.width;
	
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

TextureHolder* Graphics :: getTexture(std::string name)
{
	std::map<std::string , TextureHolder* > :: iterator it = textureMap.find(name);
	if(it != textureMap.end())
	{
		return it ->second;
	}
	else
	{
		return nullptr;
	}
}

void Graphics :: setFont(BitMapFont* bitmapFont)
{
		
		font = bitmapFont;
		loadTexture(font -> sourceFile, font -> name );
		TextureHolder* textureHolder = getTexture(font -> name);
		font -> rectWidth = textureHolder ->width / font ->nCharCol;
		font -> rectHeight = textureHolder ->height / font ->nCharRow;
		//setSingleColor(textureHolder ->pTexture, textureHolder ->width, textureHolder ->height);
}

BitMapFont* Graphics :: getFont()
{
	return font;
}

void Graphics :: drawChar(LPDIRECT3DTEXTURE9 pTexture, int width, int height, char c, int size, int x, int y, bool space, D3DCOLOR color)
{
	if( c == ' ' && space == false )
	{
		return;
	}
	RECT sourceRect;
	std::size_t charPos = font -> characterSet.find(c);
	if(charPos == std::string::npos)
	{
		return;
	}
	
	int col = charPos % font ->nCharCol;
	int row = charPos / font ->nCharCol;

	int dx = col * font -> rectWidth + font ->arrangeRect.x;
	int dy = row * font -> rectHeight + font -> arrangeRect.y;
	sourceRect.top = dy;
	sourceRect.left = dx;
	sourceRect.right = dx + font -> rectWidth;
	sourceRect.bottom = dy + font -> rectHeight;

	

	D3DXVECTOR3 position(x , y , 1.0f);
	D3DXMATRIX matrix;

	D3DXMatrixTransformation2D(
								&matrix,
								&D3DXVECTOR2(x, y),
								0.0f,
								&D3DXVECTOR2((float)size / font ->size, (float)size / font ->size),
								&D3DXVECTOR2(x + height / 2, y + height / 2),
								0.0f,
								NULL);

	pSpriteHandler->SetTransform( &matrix);
	pSpriteHandler ->Draw(pTexture, &sourceRect, NULL, &position, color);
}

void Graphics :: drawText(std::string text, int size, int x, int y, bool space, D3DCOLOR color )
{
	TextureHolder* textureHolder = getTexture(font -> name);
	LPDIRECT3DTEXTURE9 pTexture = textureHolder ->pTexture;
	int width = textureHolder -> width;
	int height = textureHolder -> height;
	
	for (int i = 0; i < text.length(); i++)
	{
		int xPos = i * ( (float)font ->arrangeRect.width * ( (float)size / font -> size)) + x;
		int yPos = y;
		drawChar(textureHolder ->pTexture,width, height, text[i], size, xPos, yPos, space, color);
	}
}


void Graphics :: drawText(Label label)
{
	drawText(label.text, label.size, label.xPos, label.yPos, label.space, label.color);
}

void Graphics :: cleanUp()
{
	delete this;
}