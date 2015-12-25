#pragma once

#include "tinyxml.h"
#include "TileLayer.h"
#include <string>
#include <vector>
#include <atlconv.h>
#include "zlib.h"
#include "zconf.h"
#include "base64.h"
#include "QuadTree.h"
#include "PlayerSprite.h"
#include "EnermyCreator.h"
#include "ObjectSprite.h"
#include "UIComponents.h"

class Map
{

public:
	Map(std::string mapName);
	~Map();
	void draw(Camera* cam);
	std:: vector< TileSet* >* getTileSets() // return the address of this vector
	{
		return &tileSets;
	}
	std :: vector < Layer* >* getLayers()
	{
		return &layers;
	}
	RectF getMapRect() 
	{
		return RectF(0.0f,0.0f, width * tileSize, height * tileSize);
	}
	void onCollision(Camera* cam);
	void onCollisionvsPlayer(PlayerSprite* sprite, Camera* cam);
	void onSupportPlayer( PlayerSprite* sprite);
	void onSupportSprite();
	void onUpdatePlayerProperties(PlayerSprite* sprite, PlayerSprite* sprite2,Camera* cam);
	void onUpdatePlayerProperties(PlayerSprite* sprite,Camera* cam);
	void onUpdate(Camera* cam);
	float getResX();
	float getResY();
	RectF getCameraTranslatePoint();
	std::vector < std::string>& getSpriteNames();
	bool isFinish();
private:
	std:: vector< TileSet* > tileSets; // vector of TileSet Pointer
	std:: vector< Layer* > layers; // vector of Layer pointer
	std :: vector < CollisionRectF > collisionRectFs;
	std :: vector < BulletSprite* > bulletSprites;
	std::vector < Object*> Objects;
	std::vector < std::string> spriteNames;
	std :: map < int , EnermySprite* > enermyMap;
	std :: map < int , ObjectSprite* > objectMap;
	int tileSize;
    int width; // number of tile in row
    int height; // number of tile in col
	QuadTree* mapCollisionTree;
private:
	void loadTileSet(TiXmlElement* e);
	void loadLayer(TiXmlElement* pTileElement);
	void loadCollisionRect(TiXmlElement* pElement);
	void createMapCollsionTree();
	void loadObject(TiXmlElement* pElement);
	void cleanPlayerBullet(Camera* cam, PlayerSprite* sprite);
	void cleanMap(Camera* cam);
	void addEToMap( Camera* cam );
	std:: string mapName;
	float respawnX;
	float respawnY;
	RectF cameraTranslatePosition;
	bool bIsFinish;
};