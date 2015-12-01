#pragma once

#include "TextureArray.h"
#include <sstream>
#include <iomanip>


TextureArray :: TextureArray(std::string fileName, std::string name, std :: string state, const unsigned int nTextures, const unsigned int 
    nFrames, D3DCOLOR colorKey)
							:
							nTextures(nTextures),
							nFrames(nFrames),
							iCurrentTexture(0),
							count(0)
{
	ppTextures = new Texture*[nTextures];
	for (int i = 0; i < nTextures; i++)
	{
		std::stringstream s;
		s << std::setw(2) << std::setfill('0') << i;
		ppTextures[i] = new Texture(fileName + "\\" + name +"\\" + name + state + s.str() + std::string(".png"), name + state + s.str(), colorKey);
	}
}

TextureArray::~TextureArray()
{
	for (int i = 0; i < nTextures; i++)
	{
		delete ppTextures[i];
	}
	delete [] ppTextures;
}

void TextureArray :: draw(int x, int y, Camera* cam, float xRatio,float yRatio , D3DCOLOR color) const
{
	ppTextures[iCurrentTexture] -> draw(x , y , cam, xRatio, yRatio, color);
}

void TextureArray ::drawFlipX( int x, int y, Camera* cam, float xRatio, float yRatio, D3DCOLOR color) const
{
	ppTextures[iCurrentTexture] -> drawFlipX(x, y ,  cam, xRatio, yRatio, color);
}

void TextureArray :: update()
{
	count ++;
	count %= nFrames;
	if ( count >= nFrames -1 )
	{
		iCurrentTexture++;
		iCurrentTexture %= nTextures;
	}		
}

void TextureArray :: setAnchorPoint(float xRatio, float yRatio )
{
	for (int i = 0; i < nTextures; i++)
	{
		ppTextures[ i ] ->setAnchorPoint(xRatio, yRatio);
	}
}

bool TextureArray::isLastTexture()
{
    return (iCurrentTexture == nTextures - 1) && (count == nFrames - 1);
}

void TextureArray::resetIndex()
{
    iCurrentTexture = 0;
    count = 0;
}

int TextureArray :: getWidth()
{
	return ppTextures [iCurrentTexture] ->getWidth();
}
int TextureArray :: getHeight()
{
	return ppTextures [iCurrentTexture] ->getHeight();
}