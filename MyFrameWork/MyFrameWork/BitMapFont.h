#pragma once
#include <string>
#include "Rect.h"
#include "d3d9.h"
class BitMapFont
{
public:
	BitMapFont(std::string sourceFile, std::string characterSet, std::string name, int nCharCol, int nCharRow, int size ,RectI arrangeRect);
	~BitMapFont(void);
	std :: string sourceFile;
	std :: string name;
	int nCharCol;
	int nCharRow;
	int size;
	int rectWidth;
	int rectHeight;
	RectI arrangeRect;
	std::string characterSet;

};

class Label
{
public:
	Label()
	{
		text = "";
		color = D3DCOLOR_XRGB(255, 255 ,255 );
		size  = 1;
		xPos = yPos = 0.0f;
	}
	Label(std :: string text,
		int size,
		float xPos,
		float yPos,
		D3DCOLOR color
		)
	{
		this ->  text = text;
		this -> size = size;
		this -> color = color;
		this -> xPos = xPos;
		this -> yPos = yPos;
	}

	std :: string text;
	int size;
	D3DCOLOR color;
	float xPos;
	float yPos;
};

