#include "BitMapFont.h"


BitMapFont :: BitMapFont(std::string sourceFile, std::string characterSet, std::string name, int nCharCol, int nCharRow, int size ,RectI arrangeRect)
	:
	sourceFile(sourceFile),
	name(name),
	characterSet(characterSet),
	nCharCol(nCharCol),
	nCharRow(nCharRow),
	size(size),
	arrangeRect(arrangeRect)
{
}


BitMapFont::~BitMapFont(void)
{
}
