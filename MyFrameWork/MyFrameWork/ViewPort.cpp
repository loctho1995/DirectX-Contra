#include "ViewPort.h"

ViewPort :: ViewPort(RectI port)
	:
	port(port)
{}

void ViewPort :: drawTexture(LPDIRECT3DTEXTURE9 pTexture, int width, int height, D3DXVECTOR2 anchorPoint, int x, int y, float xRatio , float yRatio , D3DCOLOR color ) const
{
	Graphics::getInstance() ->drawTexture(pTexture, width, height, anchorPoint, port, x + port.x, y + port.y, xRatio, yRatio, color);
}

void ViewPort :: drawTextureFlipX( LPDIRECT3DTEXTURE9 pTexture, int width, int height, D3DXVECTOR2 anchorPoint,int x, int y, float xRatio , float yRatio , D3DCOLOR color ) const
{
	Graphics::getInstance() ->drawTextureFlipX(pTexture, width, height, anchorPoint, port, x + port.x, y + port.y, xRatio, yRatio, color);
}

void ViewPort :: drawTileTmx( std::string name, int width, int height, int dx, int dy, int x, int y, D3DCOLOR color ) const
{
	Graphics::getInstance() ->drawTileTmx(name, width, height, dx, dy, port, x + port.x , y + port.y ,color);
}


void ViewPort :: drawTileTmx( LPDIRECT3DTEXTURE9 pTexture, int width, int height,int dx, int dy,  int x, int y, D3DCOLOR color ) const
{
	Graphics::getInstance() ->drawTileTmx(pTexture, width, height, dx, dy, port, x + port.x , y + port.y ,color);
}


int ViewPort :: getWidth()
{
	return port.width;
}
int ViewPort ::getHeight() 
{
	return port.height;
}
