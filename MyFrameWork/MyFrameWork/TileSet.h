#pragma once
#include "Graphics.h"
#include <string>
#include <vector>
#include "tinyxml.h"
#include <map>
class AnimationTiled
{
	
public:
	struct TileFrame
	{
		int id;
		int duration;
	};
	AnimationTiled()
	{
		counter = 0;
		currentID = 0;
		nFrames = 0;
	}
	
	void loadTileFrame( TiXmlElement* e )
	{
		
		for (TiXmlElement* ele = e ->FirstChildElement(); ele != NULL; ele = ele-> NextSiblingElement())
		{
			if( ele -> Value() == std :: string("frame") )
			{
				nFrames++;
				int id = 0;
				int duration = 0;
				ele -> Attribute("tileid", &id);
				ele -> Attribute("duration", &duration);
				addTileFrames(id, duration);
				
			}
		}
	}

	void update()
	{
		counter++;
		counter %= tileFrames[currentID].duration;
		if(counter == 0)
		{
			currentID ++;
			currentID %= nFrames;
		}
	}
	int getCurrentID()
	{
		return tileFrames[currentID].id;
	}
private:

	std::vector<TileFrame> tileFrames;
	int counter;
	int nFrames;
	int currentID;
	
	void addTileFrames(int id, int duration)
	{
		TileFrame tileFrame;
		tileFrame.id = id;
		tileFrame.duration = (duration * 60 / 1000);
		tileFrames.push_back(tileFrame);
	}

};
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
	~TileSet()
	{
	}
	void update()
	{
		for (std::map<int , AnimationTiled>::iterator it = animationTiles.begin(); it != animationTiles.end(); it++)
		{
			it -> second.update();
		}
	}
	int getCurrentID( int id)
	{
		std::map<int , AnimationTiled>::iterator it = animationTiles.find(id);
		if(it == animationTiles.end())
		{
			return -1;
		}
		else
		{
			return it -> second.getCurrentID();
		}
	}
	void loadAnimationTiled( TiXmlElement* e )
	{
		AnimationTiled animationTiled;
		int id = 0;
		e -> Attribute("id", &id);
		for (TiXmlElement* ele = e ->FirstChildElement(); ele != NULL; ele = ele-> NextSiblingElement())
		{
			if( ele -> Value() == std :: string("animation") )
			{
				animationTiled.loadTileFrame(ele);
			}
		}

		animationTiles[ id ] = animationTiled;
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
	std::map<int , AnimationTiled> animationTiles;
	
};