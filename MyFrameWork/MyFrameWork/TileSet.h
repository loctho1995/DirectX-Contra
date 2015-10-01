#pragma once
#include "Graphics.h"
#include <string>
#include <vector>
#include "tinyxml.h"
class TileSet
{
public:
	TileSet()
	{
		firstGridID = 0;
		lastGridID = 0;
		tileWidth = 0;
		tileHeight = 0;
		spacing = 0;
		margin = 0;
		width = 0;
		height = 0;
		nColumns = 0;
		nRows = 0;
	}
	int firstGridID;
	int lastGridID;
	int tileWidth;
	int tileHeight;
	int spacing;
	int margin;
	int width; // width in pixel
	int height; // height in pixel 
	int nColumns; // number of col in tileset
	int nRows; // number of row in tile set
	std:: string name;
	LPDIRECT3DTEXTURE9 pTexture;
};