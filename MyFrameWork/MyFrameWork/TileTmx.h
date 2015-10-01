#pragma once

#include "Graphics.h"
#include "Camera.h"

class TileTmx
{
public:
	TileTmx(float x, float y, int id);
	void draw(std::string tileSetName,int width, int height, int dx, int dy, Camera* cam);
	void draw(LPDIRECT3DTEXTURE9 pTexture,int width, int height, int dx, int dy, Camera* cam);
	int getID();
private:
	int x; // x position in the world map
	int y; // y position in the world map
	int id; // id in the tile set
	static const int width; // pixels
	static const int height; // pixels
};