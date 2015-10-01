#pragma once
#include "TileTmx.h"
#include "TileSet.h"
#include "TileSet.h"
#include <vector>
#include "string"
#include "Sprite.h"
class Layer
{
public:
	virtual void draw(Camera* cam) = 0;
	virtual ~Layer() {}
	virtual void createTileTmx()  = 0;

	std:: string getName()
	{
		return name;
	}
protected:
	Layer(int tileSize, int nColumns, int nRows, std ::string name, std::vector < TileSet* > & tileSets) 
		:
		tileSize(tileSize),
		tileSets(tileSets),
		name(name),
		nColumns( nColumns),
		nRows(nRows)
	{}
	TileTmx **ppTileTmx;
	
	int nColumns; // number tile columns in world map
	int nRows; // number tile rows in world map
	int tileSize; // in pixels
	std:: string name;
	std::vector< std::vector< int> > tileIDs;
	std:: vector< TileSet* > &tileSets;
	
};