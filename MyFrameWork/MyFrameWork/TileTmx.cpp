#include "TileTmx.h"

TileTmx ::TileTmx(float x, float y, int id)
		:
	x(x),
	y(y),
	id(id)
	{}

void TileTmx :: draw(std::string tileSetName, int width, int height, int dx, int dy, Camera* cam)
{
	cam -> drawTileTmx( tileSetName, width, height, dx, dy, x, y, 0xFFFFFFFF);
}
void TileTmx :: draw(LPDIRECT3DTEXTURE9 pTexture,int width, int height, int dx, int dy, Camera* cam)
{
	cam -> drawTileTmx( pTexture, width, height, dx, dy, x, y, 0xFFFFFFFF);
}
int TileTmx :: getID()
{
	return id;
}