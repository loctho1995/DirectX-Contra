#pragma once

#include "Layer.h"
#include  <algorithm>
class TileLayer : public Layer
{
public:
	TileLayer (int tileSize, int nColumns, int nRows, std ::string name, std::vector < TileSet* > & tileSets);
	virtual void draw(Camera* cam);
	void setTileIDs(std::vector< std::vector< int> > tileIDs);
	virtual void createTileTmx();
	int getTileSet(int id);

	int getTileXLeft( float x );
	int getTileXRight( float x );
	int getTileYTop ( float y );
	int getTileYBottom ( float y );
	TileTmx* getTileTmx(int ix, int iy );



};