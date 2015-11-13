#pragma once
#include <string>
#include "Rect.h"
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

