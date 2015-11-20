#include "TileLayer.h"

TileLayer::TileLayer (int tileSize, int nColumns, int nRows, std ::string name, std::vector < TileSet* > & tileSets) 
	:
	Layer(tileSize, nColumns, nRows, name, tileSets)
{
}


int TileLayer :: getTileXLeft( float x )
{
		return x / tileSize;
}
int TileLayer ::  getTileXRight( float x )
{
	int ix = x / tileSize;
	if( ix * tileSize == x )
		ix --;
	return ix;
}
int TileLayer :: getTileYTop ( float y )
{
	return y / tileSize;
}
int TileLayer :: getTileYBottom ( float y )
{

	int iy = y / tileSize;
	if( iy * tileSize == y )
		iy--;
	return iy;
}
TileTmx* TileLayer :: getTileTmx(int ix, int iy )
{
	return ppTileTmx[ix + iy* nColumns];
}



void TileLayer:: draw(Camera* cam)
{
	for (int row = getTileYTop( cam->getY() ); row <= getTileYBottom(cam -> getY() + (float)cam ->getHeight()); row++)
	{
		for (int col = getTileXLeft(cam -> getX() ); col <= getTileXRight(cam -> getX() + (float)cam -> getWidth()); col++)
		{
			int index = col + row * nColumns;
			if( ppTileTmx[ index ] ->getID() == 0)
				continue;
			TileSet* tileSet = tileSets[getTileSet(ppTileTmx[ index ] ->getID())];
			int tileID = ppTileTmx[ index ] ->getID () - tileSet ->firstGridID; // ex : 128th represent by 127 in the 1D array
			int tileIDinSet = tileID;

			tileID = tileSet -> getCurrentID(tileID);
			if(tileID != -1 )
			{
				tileIDinSet = tileID;
			}
			int colInSet = tileIDinSet % tileSet -> nColumns;
			int rowInSet = tileIDinSet / tileSet -> nColumns;
			int dx =  tileSet -> margin + (colInSet) * ( tileSet ->spacing + tileSet -> tileWidth ) ;
			int dy =  tileSet -> margin + (rowInSet) * ( tileSet ->spacing + tileSet -> tileHeight );
			ppTileTmx[index ] -> draw( tileSet ->pTexture, tileSize, tileSize,dx, dy, cam);
		}
	}
}
void TileLayer :: setTileIDs(std::vector< std::vector< int> > tileIDs)
{
	this -> tileIDs = tileIDs;
}
void TileLayer:: createTileTmx()
{
	ppTileTmx = new TileTmx*[ nColumns * nRows ];
	for (int row = 0; row < nRows; row++)
	{
		for (int col = 0; col < nColumns; col++)
		{
			int id = tileIDs[row][col];
			ppTileTmx[ col + row * nColumns ] = new TileTmx (col * tileSize, row * tileSize, id);
		}
	}
}
int TileLayer:: getTileSet(int id)
{
	for (int i = 0; i < tileSets.size(); i++)
	{
		if( id >= tileSets[i] ->firstGridID && id <= tileSets[i] ->lastGridID )
		{
			return i;
		}
	}
}