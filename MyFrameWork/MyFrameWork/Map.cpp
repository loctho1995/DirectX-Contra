#include "Map.h"
#include <algorithm> 
#include <typeinfo>


Map :: Map(std::string mapName)
	:
	mapName(mapName)
{
	std::string convertFileName = std::string("Resources\\Maps\\") + (mapName) + std::string(".tmx");
	TiXmlDocument levelDocument;
	levelDocument.LoadFile(convertFileName);
	TiXmlElement* pRoot = levelDocument.RootElement();
	pRoot -> Attribute("tilewidth", &tileSize);
	pRoot ->Attribute("width", &width);
	pRoot -> Attribute ("height", &height);

	// load tile set
	for (TiXmlElement* e = pRoot ->FirstChildElement(); e != NULL; e = e-> NextSiblingElement())
	{
		if( e -> Value() == std :: string("tileset") )
		{
			loadTileSet(e);
		}
	}


	// load Layer

	for (TiXmlElement* e = pRoot ->FirstChildElement(); e != NULL; e = e-> NextSiblingElement())
	{
		if( e -> Value() == std :: string("layer"))
		{
			loadLayer(e);
		}
	}

	// create tileTmx in BackGroundLayer
	for (int i = 0; i < layers.size(); i++)
	{
		if(layers[i] ->getName() == "BackGroundLayer")
			layers[i] ->createTileTmx();
	}

	// Load Collision Rect
	for (TiXmlElement* e = pRoot ->FirstChildElement(); e != NULL; e = e-> NextSiblingElement())
	{
		if( e -> Value() == std :: string("objectgroup") && e ->Attribute("name") == std :: string("CollisionRect") )
		{
			loadCollisionRect(e);
		}
	}

	for (TiXmlElement* e = pRoot ->FirstChildElement(); e != NULL; e = e-> NextSiblingElement())
	{
		if( e -> Value() == std :: string("objectgroup") && e ->Attribute("name") == std :: string("ObjectLayer") )
		{
			loadObject(e);
		}
	}



	// create quadtree

	createMapCollsionTree();
	bIsFinish = false;

}


Map::~Map()
{
	for (int i = 0; i < tileSets.size(); i++)
	{
		if(tileSets[i])
			delete tileSets[i];
	}
	tileSets.clear();

	for (int i = 0; i < layers.size(); i++)
	{
		if(layers[i])
			delete layers[i];
	}
	layers.clear();

	collisionRectFs.clear();

	for (int i = 0; i < bulletSprites.size(); i++)
	{
		if(bulletSprites[i])
			delete bulletSprites[i];
	}
	bulletSprites.clear();
	for (int i = 0; i < Objects.size(); i++)
	{
		if(Objects[i])
			delete Objects[i];
	}
	Objects.clear();

	for (auto it = enermyMap.begin(); it != enermyMap.end(); it++)
	{
		delete it -> second;
	}

	for (auto it = objectMap.begin(); it != objectMap.end(); it++)
	{
		delete it -> second;
	}

	delete mapCollisionTree;
	

}
#pragma region 


void Map :: loadTileSet(TiXmlElement* e)
	{
		TileSet* tileSet;
		tileSet = new TileSet();
		std::string s = std::string ("Resources\\Maps\\" ) + (e ->FirstChildElement()->Attribute("source"));

		std::wstring tileSetSource(s.begin(), s.end());

		tileSet ->name = e -> Attribute("name");

		Graphics::getInstance() ->loadTexture(s, e -> Attribute("name"));
		tileSet ->pTexture = Graphics::getInstance()->getTexture(tileSet->name) ->pTexture;
			
		e -> FirstChildElement() -> Attribute ("width", &tileSet ->width);
		e -> FirstChildElement() -> Attribute( "height", &tileSet -> height);
		e -> Attribute("firstgid",&tileSet->firstGridID);
		e -> Attribute("tilewidth", &tileSet -> tileWidth);
		e -> Attribute("tileheight", &tileSet -> tileHeight);
		e -> Attribute("spacing", &tileSet -> spacing);
		e -> Attribute("margin", &tileSet ->margin);
		


		int nCol = tileSet -> width / (tileSet -> tileWidth + tileSet ->spacing);
		if ( tileSet -> width % (tileSet -> tileWidth + tileSet ->spacing) > tileSet ->tileWidth )
		{
			nCol ++;
		}
		int nRow = tileSet -> height / (tileSet -> tileHeight + tileSet ->spacing);
		if ( tileSet -> tileHeight % (tileSet -> tileHeight + tileSet ->spacing) > tileSet ->tileHeight )
		{
			nRow ++;
		}
		
		tileSet -> nColumns = nCol;
		tileSet ->nRows = nRow;
		tileSet -> lastGridID = nCol * nRow + tileSet ->firstGridID -1;

		for (TiXmlElement* ele = e ->FirstChildElement(); ele != NULL; ele = ele-> NextSiblingElement())
		{
			if( ele -> Value() == std :: string("tile") )
			{
				tileSet -> loadAnimationTiled(ele);
			}
		}


		tileSets.push_back(tileSet);

		
	}

void Map :: loadLayer(TiXmlElement* pTileElement)
	{

		TileLayer* pTileLayer = new TileLayer(tileSize, width, height, pTileElement ->Attribute("name"),tileSets);

		std::vector<std::vector<int>> data;

		std::string decodedIDs;

		TiXmlElement* pDataNode = NULL;

		for (TiXmlElement* e = pTileElement->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
		{
			if (e->Value() == std::string("data"))
			{
				pDataNode = e;
			}		
		}

		for (TiXmlNode* e = pDataNode->FirstChild(); e != NULL; e = e->NextSibling())
		{
			TiXmlText* text = e->ToText();

			std::string t = text->Value();

			decodedIDs = base64_decode(t);
		}

		// uncompress zlib compression
		uLongf numGids = width * height * sizeof(int);

		std::vector< int > gids(width * height); 

		uncompress((Bytef*)&gids[0], &numGids, (const Bytef*)decodedIDs.c_str(), decodedIDs.size());

		std::vector<int> layerRow(width);

		for (int j = 0; j < height; j++)
		{
			data.push_back(layerRow);
		}
		for (int rows = 0; rows < height; rows++)
		{
			for (int cols = 0; cols < width; cols++)
			{
				data[rows][cols] = gids[rows * width + cols];
			}
		}

		pTileLayer->setTileIDs(data);

		layers.push_back(pTileLayer);
	}

void Map :: loadCollisionRect(TiXmlElement* pElement)
{
	RectI r;
	std::string type;

	for (TiXmlElement* e = pElement -> FirstChildElement(); e != NULL ; e = e -> NextSiblingElement())
	{
		e -> Attribute("x",&r.x);
		e -> Attribute("y",&r.y);
		e -> Attribute("width",&r.width);
		e -> Attribute("height",&r.height);
		type = e->Attribute("type");
		//collisionRects.push_back(r);
		collisionRectFs.push_back(CollisionRectF(r, type));
	}
}

void Map :: loadObject(TiXmlElement* pElement)
{
	//RectI r;

	int id;
	int x;
	int y;
	int rectX;
	int rectY;
	int width;
	int height;
	std:: string name;
	std:: string type;
	for (TiXmlElement* e = pElement -> FirstChildElement(); e != NULL ; e = e -> NextSiblingElement())
	{
		name = e -> Attribute("name");
		type = e -> Attribute("type");
		e -> Attribute("id",&id);
		e -> Attribute("x",&rectX);
		e -> Attribute("y",&rectY);
		e -> Attribute("width",&width);
		e -> Attribute("height",&height);

		if( name == "cameratranslateposition")
		{
			cameraTranslatePosition = RectF(rectX , rectY , width, height);
		}
		else if ( name == "respawnposition" )
		{
			respawnX = rectX + width / 2;
			respawnY = rectY + height;
		}
		else
		{
			if(std::find ( spriteNames.begin(),spriteNames.end(), name) == spriteNames.end())
				spriteNames.push_back(name);
			x = rectX;
			y = rectY;

			if(type != "object")
			{
				x = rectX + width / 2;
				y = rectY + height;
			}
			Object* object = new Object(name, type, x , y , id , width, height, RectF(rectX , rectY , width, height));
			Objects.push_back(object);
		}
		
	}

}

void Map :: createMapCollsionTree()
{
	mapCollisionTree = new QuadTree(0,RectF(0.0f, 0.0f , tileSize * width , tileSize * height));
}

void Map :: cleanMap(Camera* cam)
{
	// clean Enermy
	RectF camRect(cam ->getX(), cam ->getY(), cam -> getWidth(), cam -> getHeight());
	for (std::map < int, EnermySprite* > ::iterator it = enermyMap.begin(); it != enermyMap.end(); )
	{
		EnermySprite* temp = it -> second;
		RectF SpriteRect(temp ->getBody());
		if (temp ->isDesTroyed())
		{
			if(temp -> isDead())
			{
				UIComponents::getInstance() ->addScore(temp ->getScore(), temp -> getKillByIndex());
			}
			if(temp ->getName().find("final") != std::string::npos)
			{
				Sound :: getInstance() -> stop();
				Sound :: getInstance() -> play("explode.wav", false, 1 );

				bIsFinish = true;
			}
			delete temp;
			it = enermyMap.erase(it);
		}
		else
		it++;
	}

	for (int i = 0; i < bulletSprites.size(); i++)
	{
		Sprite* temp = bulletSprites[i];
		if(!camRect.checkCollision(temp  ->getBody()) || temp ->isDesTroyed())
		{
			delete temp;
			bulletSprites.erase(bulletSprites.begin() + i );
		}
	}


	// clean ObjectSprite

	for (std :: map < int , ObjectSprite* > ::iterator it = objectMap.begin(); it != objectMap.end(); )
	{
		ObjectSprite* temp = it -> second;
		RectF SpriteRect(temp ->getBody());

		if (it ->second ->isDesTroyed())
		{
			delete temp;
			it = objectMap.erase(it);
		}
		else
		it++;
	}

	


	if(bIsFinish )
	{
		for (std::map < int, EnermySprite* > ::iterator it = enermyMap.begin(); it != enermyMap.end(); it ++)
		{
			it ->second ->die();
		}

		for (std :: map < int , ObjectSprite* > ::iterator it = objectMap.begin(); it != objectMap.end(); it++)
		{
			it -> second -> die();
		}

		for (int i = 0; i < bulletSprites.size(); i++)
		{
			bulletSprites[i] ->die();
		}
		
	}


}
void Map :: cleanPlayerBullet(Camera* cam, PlayerSprite* sprite)
{
	RectF camRect(cam ->getX(), cam ->getY(), cam -> getWidth(), cam -> getHeight());
	std::vector<BulletSprite* >& playerBullets = sprite ->getBullets();

	for (int i = 0; i < playerBullets.size(); i++)
	{
		Sprite* temp = playerBullets[i];
		if(!camRect.checkCollision(temp  ->getBody()) || temp ->isDesTroyed())
		{
			delete temp;
			playerBullets.erase(playerBullets.begin() + i);
		}
	}
}
void Map ::addEToMap ( Camera* cam )
{
	RectF camRect = cam ->getRect();
	mapCollisionTree -> clear();
	for (int i = 0; i < Objects.size(); i++)
	{

			if( enermyMap.find(Objects[i] ->id) == enermyMap.end()  && objectMap.find(Objects[i] ->id) == objectMap.end())
				mapCollisionTree -> insert( Objects[i] );
		 
  	}
 	std:: vector < Object * > returnList;
	mapCollisionTree -> getObjectlist (returnList, camRect);

	for (int i = 0; i < returnList.size(); i++)
	{
		RectF body = returnList[i] -> body;
		std::string type  = returnList[i] -> type;
		if(camRect.checkCollision( body ))
		{
			Direction appearDir = EnermyCreator :: getInstance() ->getAppearDir( returnList[i] -> name );
			if(appearDir.isNone())
			{
				if(type == "enemy")
				{
					EnermySprite* enermySprite = EnermyCreator::getInstance() ->createEnermySprite(returnList[i] ->name, returnList[i]->x, returnList[i] -> y , bulletSprites);
					if(enermySprite != nullptr )
					enermyMap[returnList[i] ->id] = enermySprite;
				}	
				else
				{
					ObjectSprite* objectSprite = EnermyCreator::getInstance() ->createObjectSprite(returnList[i] ->name, returnList[i]->x, returnList[i] -> y );
					if( objectSprite != nullptr )
					objectMap[returnList[i] ->id] =  objectSprite;
				}
				continue;
			}
			if( appearDir.isRight())
			{
				if( (body.x  <= camRect.x +camRect.width ) && ( body.x  >= camRect.x +camRect.width - 10) )
				{
					if(type == "enemy")
					{
						EnermySprite* enermySprite = EnermyCreator::getInstance() ->createEnermySprite(returnList[i] ->name, returnList[i]->x, returnList[i] -> y , bulletSprites);
						if(enermySprite != nullptr )
						enermyMap[returnList[i] ->id] = enermySprite;
					}	
					else
					{
						ObjectSprite* objectSprite = EnermyCreator::getInstance() ->createObjectSprite(returnList[i] ->name, returnList[i]->x, returnList[i] -> y );
						if( objectSprite != nullptr )
						objectMap[returnList[i] ->id] =  objectSprite;
					}
				}
			}

			if ( appearDir.isLeft() )
			{
				if(
					( ( body.x + body.width >= camRect.x ) && (body.x + body.width <= camRect.x + 10) )
					)
				{
					if(type == "enemy")
					{
						EnermySprite* enermySprite = EnermyCreator::getInstance() ->createEnermySprite(returnList[i] ->name, returnList[i]->x, returnList[i] -> y , bulletSprites);
						if(enermySprite != nullptr )
						enermyMap[returnList[i] ->id] = enermySprite;
					}	
					else
					{
						ObjectSprite* objectSprite = EnermyCreator::getInstance() ->createObjectSprite(returnList[i] ->name, returnList[i]->x, returnList[i] -> y );
						if( objectSprite != nullptr )
						objectMap[returnList[i] ->id] =  objectSprite;
					}
				}
			}
			
			if( appearDir.isUp())
			{
				if( (body.y + body.height  >= camRect.y ) && ( body.y + body.height  <= camRect.y + 20) )
				{
					if(type == "enemy")
					{
						EnermySprite* enermySprite = EnermyCreator::getInstance() ->createEnermySprite(returnList[i] ->name, returnList[i]->x, returnList[i] -> y , bulletSprites);
						if(enermySprite != nullptr )
						enermyMap[returnList[i] ->id] = enermySprite;
					}	
					else
					{
						ObjectSprite* objectSprite = EnermyCreator::getInstance() ->createObjectSprite(returnList[i] ->name, returnList[i]->x, returnList[i] -> y );
						if( objectSprite != nullptr )
						objectMap[returnList[i] ->id] =  objectSprite;
					}
				}
			}

			
			if( appearDir.isDown())
			{
				if( (body.y  <= camRect.y + camRect.height) && ( body.y  >= camRect.y + camRect.height - 20) )
				{
					if(type == "enemy")
					{
						EnermySprite* enermySprite = EnermyCreator::getInstance() ->createEnermySprite(returnList[i] ->name, returnList[i]->x, returnList[i] -> y , bulletSprites);
						if(enermySprite != nullptr )
						enermyMap[returnList[i] ->id] = enermySprite;
					}	
					else
					{
						ObjectSprite* objectSprite = EnermyCreator::getInstance() ->createObjectSprite(returnList[i] ->name, returnList[i]->x, returnList[i] -> y );
						if( objectSprite != nullptr )
						objectMap[returnList[i] ->id] =  objectSprite;
					}
				}
			}	
			
		}
	}
}

#pragma endregion helperFunction

#pragma region


void Map :: draw(Camera* cam)
{
	for (int i = 0; i < layers.size(); i++)
	{
		if(layers[i] ->getName() == "BackGroundLayer")
			layers[i] ->draw(cam);
	}
	
	for (std::map < int, EnermySprite* > ::reverse_iterator it = enermyMap.rbegin(); it != enermyMap.rend(); ++it)
	{
		it ->second ->draw(cam);
	}
	
	for (std::map < int, ObjectSprite* > ::iterator it = objectMap.begin(); it != objectMap.end(); ++it)
	{
		it ->second ->draw(cam);
	}

	for (int i = 0; i < bulletSprites.size(); i++)
	{
		bulletSprites[i] ->draw(cam);
	}


}



void Map :: onCollision(Camera* cam)
{
	// map collision vs Player
	mapCollisionTree -> clear();
	
	for (int i = 0; i < collisionRectFs.size(); i++)
	{
		mapCollisionTree -> insert( collisionRectFs[i] );
  	}

#pragma region

	for (std::map < int, EnermySprite* > ::iterator enermyIt = enermyMap.begin(); enermyIt != enermyMap.end(); enermyIt++)
	{
		std:: vector < CollisionRectF > returnLists;
		mapCollisionTree -> getObjectlist (returnLists, enermyIt -> second ->getBody());

		for (int i = 0; i < returnLists.size(); i++)
		{

			std:: vector < CollisionRectF > throughRectVector = enermyIt ->second ->getThroughRect();
			if(std::find(throughRectVector.begin(), throughRectVector.end(), returnLists[i]) == throughRectVector.end())
			{
				if( enermyIt -> second ->getBody().checkCollision( returnLists[i].rect) )
				{
					enermyIt -> second -> onCollision( returnLists[i] );
				}
			}
			
		}


		for (std:: map < int ,ObjectSprite* > :: iterator objectIt = objectMap.begin() ; objectIt != objectMap.end(); objectIt++)
		{
			if(objectIt ->second ->isEnemyCollisionable())
			{
				CollisionRectF r = objectIt ->second ->getCollisionRect();
				if( enermyIt -> second ->getBody().checkCollision(r.rect)  )
				{
				
					if( objectIt ->second ->isAffectble() )
								enermyIt -> second -> onCollision( r );
				}
			}	
		
		}



	}
#pragma endregion EnermyvsMap

#pragma region

	
	for (int i = 0; i < bulletSprites.size(); i++)
	{
		std:: vector < CollisionRectF > returnLists;
		mapCollisionTree->getObjectlist(returnLists, bulletSprites[i] ->getBody());
		for (int j = 0; j < returnLists.size(); j++)
		{
			std:: vector < CollisionRectF > throughRectVector = bulletSprites[i] -> getThroughRect();
 			if(std::find(throughRectVector.begin(), throughRectVector.end(), returnLists[j]) == throughRectVector.end())
			{
				if( bulletSprites[i] ->getBody().checkCollision( returnLists[j].rect) )
				{
					bulletSprites[i] -> onCollision( returnLists[j] );
				}
			}
		}
	}
#pragma endregion EnermyBulletvsMap

#pragma region
		

		
		for (std:: map < int ,ObjectSprite* > :: iterator objectIt = objectMap.begin() ; objectIt != objectMap.end(); objectIt++)
		{
			std:: vector < CollisionRectF > objectCollisionReturnList;

			mapCollisionTree -> getObjectlist (objectCollisionReturnList, objectIt -> second -> getBody());

			for (int i = 0; i < objectCollisionReturnList.size(); i++)
			{
				CollisionRectF cRect = objectCollisionReturnList[i];
				if( objectIt -> second ->getBody().checkCollision(cRect.rect)  )
				{
						objectIt -> second -> onCollision( cRect );
				}
			}
		
		}





		for (std:: map < int ,ObjectSprite* > :: iterator iobjectIt = objectMap.begin() ; iobjectIt != objectMap.end(); iobjectIt++)
		{
			for (std:: map < int ,ObjectSprite* > :: iterator jobjectIt = objectMap.begin() ; jobjectIt != objectMap.end(); jobjectIt++)
			{

				RectF iBody = iobjectIt ->second ->getBody();
				RectF jBody = jobjectIt ->second ->getBody();

				if(!iobjectIt ->second ->isAffectble())
				{
					if( iBody.checkCollision(jBody) && iobjectIt != jobjectIt)
					{
						iobjectIt -> second -> onCollision ( jobjectIt -> second ->getCollisionRect() );
					}
				}
				else
				{
					break;
				}
			}
		
		}

#pragma endregion ObjectvsMap

		RectF cameraRect = cam ->getRect();

#pragma region
	for (std::map < int, EnermySprite* > ::iterator it = enermyMap.begin(); it != enermyMap.end(); it++)
	{
		it -> second -> onCameraCollision(cameraRect);
	}
	for (std::map < int, ObjectSprite* > ::iterator it = objectMap.begin(); it != objectMap.end(); it++)
	{
		it -> second -> onCameraCollision(cameraRect);
	}

#pragma endregion EnemyObjectvsCamera
	// update through rect list of enermy
	for (std::map < int, EnermySprite* > ::iterator it = enermyMap.begin(); it != enermyMap.end(); it++)
	{
		it -> second -> updateThroughRect();
	}
	// update through rect list of object
	for (std::map < int, ObjectSprite* > ::iterator it = objectMap.begin(); it != objectMap.end(); it++)
	{
		it -> second -> updateThroughRect();
	}
}

void Map :: onCollisionvsPlayer(PlayerSprite* sprite, Camera* cam)
{
	mapCollisionTree -> clear();
	
	for (int i = 0; i < collisionRectFs.size(); i++)
	{
		mapCollisionTree -> insert( collisionRectFs[i] );
  	}
#pragma region
	
	// player vs Collision Rect
	std:: vector < CollisionRectF > returnList;
	mapCollisionTree -> getObjectlist (returnList, sprite -> getBody());


	for (int i = 0; i < returnList.size(); i++)
	{
		std:: vector < CollisionRectF > throughRectVector = sprite ->getThroughRect();
		if(std::find(throughRectVector.begin(), throughRectVector.end(), returnList[i]) == throughRectVector.end())
		{
			if( sprite ->getBody().checkCollision( returnList[i].rect) )
			{
				sprite -> onCollision( returnList[i] );
			}
		}
		
	}



	for (std:: map < int ,ObjectSprite* > :: iterator objectIt = objectMap.begin() ; objectIt != objectMap.end(); objectIt++)
	{
		if(objectIt ->second ->isPlayerCollisionable())
		{
			CollisionRectF* r = objectIt ->second ->getRefCollisionRect();
			std:: vector < CollisionRectF* > throughRectVector = sprite ->getDynamicThroughRect();
			int size = 0;
			size = throughRectVector.size();
			if(std::find(throughRectVector.begin(), throughRectVector.end(), r ) == throughRectVector.end())
			{
				if( sprite ->getBody().checkCollision(r ->rect)  )
				{

					if( objectIt ->second ->isAffectble() )
						sprite -> onDynamicObjectCollision( r );
					else
					{
						if ( objectIt -> second ->getName().find("weapon") != std::string::npos )
						{	
							ObjectStaticWeapon * weapon = dynamic_cast< ObjectStaticWeapon *> (objectIt -> second);
							if(weapon)
							{
								sprite ->setBulletType (weapon ->getBulletType());
								objectIt -> second ->die();
							}
							else
							{
								ObjectCapsuleWeapon * weaponAnother = dynamic_cast< ObjectCapsuleWeapon *> (objectIt -> second);
								if(weaponAnother -> getBulletType() == BulletTypes::D)
								{
									Sound::getInstance() -> play("weaponD", false, 1);
									for (int i = 0; i < bulletSprites.size(); i++)
									{
										bulletSprites[i] -> die();	
									}

									for (auto it = enermyMap.begin(); it != enermyMap.end(); it++)
									{
										it -> second -> die();
									}

									for (auto it = objectMap.begin(); it != objectMap.end(); it++)
									{
										it -> second -> die();
									}
								}
								else
								{
									sprite ->setBulletType (weaponAnother ->getBulletType());
								}
								
								objectIt -> second ->die();
							}
						}
					}
				}
			}
		}	
		
	}



#pragma endregion mapvsPlayer
#pragma region
	for (std::map < int, EnermySprite* > ::iterator it = enermyMap.begin(); it != enermyMap.end(); it++ )
	{
		RectF r = it ->second ->getBody();
		if(sprite ->isHittable() && r.checkCollision(sprite ->getBody()) && !it -> second ->isThroughable())
		{
			if(sprite -> isUndying() )
			{
				if(it -> second -> isHittable())
					it -> second -> die();
			}
			else
			sprite ->die();
		}
			
	}
#pragma endregion EnermyvsPlayer
#pragma region
	for (int i = 0; i < bulletSprites.size(); i++)
	{
		Sprite* bulletE = bulletSprites[i];
		if( sprite -> isHittable() &&  bulletE ->getBody().checkCollision(sprite ->getBody())  )
		{
			bulletE -> die();
			if(!sprite -> isUndying())
					sprite -> die();
				
					break;
		}
	}
#pragma endregion EnermyBulletvsPlayer
#pragma region 

	std :: vector < BulletSprite* >& bullets = sprite ->getBullets();
	for (int bulletIt  = 0; bulletIt < bullets.size();  bulletIt++)
	{
		for (std::map < int, EnermySprite* > ::iterator enermyIt = enermyMap.begin(); enermyIt != enermyMap.end();enermyIt++)
		{
			BulletSprite* tempB = bullets[bulletIt];
			EnermySprite* tempE = enermyIt ->second;
			RectF rB = tempB ->getBody();
			RectF rE = tempE ->getBody();
			if( rE.checkCollision(rB ) && enermyIt ->second ->isHittable() )
			{
				tempE -> beShooted( sprite ->getDamage() , sprite -> getIndex());
				tempB ->die();
				break;
			}
		}
	}

	for (int bulletIt  = 0; bulletIt < bullets.size();  bulletIt++)
	{
		for (int enemyBullet = 0; enemyBullet < bulletSprites.size(); enemyBullet++)
		{
			BulletSprite* tempB = bullets[bulletIt];
			BulletSprite* tempE = bulletSprites[enemyBullet];
			RectF rB = tempB ->getBody();
			RectF rE = tempE ->getBody();
			if( rE.checkCollision(rB ) && bulletSprites[enemyBullet] ->isHittable() )
			{
				tempE -> die();
				tempB -> die();
				break;
			}
		}
		
	}

#pragma endregion playerBulletvsEnermy
#pragma region 

	for (int bulletIt  = 0; bulletIt < bullets.size();  bulletIt++)
	{
		for (std::map < int, ObjectSprite* > ::iterator objectIt = objectMap.begin(); objectIt != objectMap.end();objectIt++)
		{
			BulletSprite* tempB = bullets[bulletIt];
			ObjectSprite* tempE = objectIt ->second;
			RectF rB = tempB ->getBody();
			RectF rE = tempE ->getBody();
			if( rE.checkCollision(rB ) && objectIt ->second ->isHittable() )
			{
				tempE -> beShooted( sprite ->getDamage() );
				tempB -> die();
				break;
			}
		}
	}

#pragma endregion playerBulletvsObjetSprite
	RectF cameraRect = cam ->getRect();
#pragma region
	sprite -> onCameraCollision(cameraRect);
#pragma endregion playervsCamera
	// update through rect list of player
	sprite ->updateThroughRect();
}

void Map :: onSupportPlayer( PlayerSprite* sprite)
{
	mapCollisionTree -> clear();
	for (int i = 0; i < collisionRectFs.size(); i++)
	{
		mapCollisionTree -> insert( collisionRectFs[i] );
  	}

	
#pragma region

	// player vs CollisionRects
	RectF r = sprite ->getBody();
	//r.height += 1;
	r.y += r.height;
	r.height = 1;
	std:: vector < CollisionRectF > returnList;
	mapCollisionTree -> getObjectlist (returnList, r);

	bool isSupported = false;
	for (int i = 0; i < returnList.size(); i++)
	{
		if( r.checkCollision( returnList[i].rect) )
		{
			sprite -> setSupportCollisionRect(returnList[i]);
			isSupported = true;
			break;
		}
	}
	// player vs object Map
	if(!isSupported)
	{
		for (std:: map < int ,ObjectSprite* > :: iterator objectIt = objectMap.begin() ; objectIt != objectMap.end(); objectIt++)
		{
			if(objectIt ->second ->isPlayerCollisionable())
			{
				CollisionRectF* collisionRect = objectIt ->second ->getRefCollisionRect();
				if( r.checkCollision(collisionRect -> rect)  )
				{
				
					if( objectIt ->second ->isAffectble() )
							sprite -> setSupportCollisionRect(collisionRect);
							isSupported = true;
							break;	
				}
			}	
		
		}
	}
	

	if(!isSupported)
	{
		sprite -> onUnsupported();
		sprite -> setSupportCollisionRect(CollisionRectF());
		sprite -> setSupportCollisionRect(NULL);
	}
	
#pragma endregion mapvsPlayer


	
}

void Map :: onSupportSprite()
{
	mapCollisionTree -> clear();
	for (int i = 0; i < collisionRectFs.size(); i++)
	{
		mapCollisionTree -> insert( collisionRectFs[i] );
  	}
#pragma region
	

	for (std::map < int, EnermySprite* > ::iterator enermyIt = enermyMap.begin(); enermyIt != enermyMap.end(); enermyIt++)
	{
		RectF r = enermyIt ->second ->getBody();
		r.y += r.height;
		r.height = 1;
		std:: vector < CollisionRectF > returnLists;
		mapCollisionTree -> getObjectlist (returnLists, enermyIt -> second ->getBody());

		bool isSupported = false;

		for (int i = 0; i < returnLists.size(); i++)
		{

			if( r.checkCollision( returnLists[i].rect) )
			{
				enermyIt -> second -> setSupportCollisionRect(returnLists[i]);
				isSupported = true;
				break;
			}

		}

		if(!isSupported )
		{
			for (std:: map < int ,ObjectSprite* > :: iterator objectIt = objectMap.begin() ; objectIt != objectMap.end(); objectIt++)
			{
				if(objectIt ->second ->isEnemyCollisionable())
				{
					CollisionRectF collisionRect = objectIt ->second ->getCollisionRect();
					if( r.checkCollision(collisionRect.rect)  )
					{

                        if (objectIt->second->isAffectble())
                        {
                            enermyIt->second->setSupportCollisionRect(collisionRect);
                            isSupported = true;
                            break;
                        }
					}
				}	

			}
		}



		if(!isSupported)
		{
			enermyIt -> second -> onUnsupported();
			enermyIt -> second -> setSupportCollisionRect(CollisionRectF());
		}


	}

#pragma endregion EnermyvsMap
}

void Map :: onUpdatePlayerProperties(PlayerSprite* sprite, PlayerSprite* sprite2, Camera* cam)
{
	cleanPlayerBullet( cam , sprite);
	if(sprite2)
	{
		cleanPlayerBullet( cam , sprite2);
	}
	// update enermy
	for (std::map < int, EnermySprite* > ::iterator it = enermyMap.begin(); it != enermyMap.end(); it++)
	{
		if(sprite2)
		{
			it ->second ->setPlayerProperties(sprite -> getCenterX(), sprite ->getCenterY(), sprite -> isDead(), sprite2 -> getCenterX(), sprite2 ->getCenterY(), sprite2 -> isDead());
		}
		else
		{
			it ->second ->setPlayerProperties(sprite -> getCenterX(), sprite ->getCenterY(), sprite -> isDead());
		}
		
	}

	for (std::map < int, ObjectSprite* > ::iterator it = objectMap.begin(); it != objectMap.end(); it++)
	{
		if(sprite2)
		{
			it ->second -> setPlayerProperties(sprite -> getCenterX(), sprite ->getCenterY(), sprite2 -> getCenterX(), sprite2 ->getCenterY());
		}
		else
		{
			it ->second -> setPlayerProperties(sprite -> getCenterX(), sprite ->getCenterY());
		}
		
	}
}
void Map :: onUpdatePlayerProperties(PlayerSprite* sprite, Camera* cam)
{
	cleanPlayerBullet( cam , sprite);

	// update enermy
	for (std::map < int, EnermySprite* > ::iterator it = enermyMap.begin(); it != enermyMap.end(); it++)
	{
		it ->second ->setPlayerProperties(sprite -> getCenterX(), sprite ->getCenterY(), sprite -> isDead());

	}

	for (std::map < int, ObjectSprite* > ::iterator it = objectMap.begin(); it != objectMap.end(); it++)
	{
		it ->second -> setPlayerProperties(sprite -> getCenterX(), sprite ->getCenterY());
	}
}
void Map :: onUpdate(Camera* cam)
{

	for (int i = 0; i < tileSets.size(); i++)
	{
		tileSets[i] -> update();
	}


	cleanMap( cam );
	addEToMap( cam );


	// update enermy
	for (std::map < int, EnermySprite* > ::iterator it = enermyMap.begin(); it != enermyMap.end(); it++)
	{
		//it ->second ->setPlayerProperties(sprite -> getCenterX(), sprite ->getCenterY(), sprite -> isDead());
		it ->second ->update();
	}

	for (std::map < int, ObjectSprite* > ::iterator it = objectMap.begin(); it != objectMap.end(); it++)
	{
		//it ->second ->setPlayerX(sprite -> getCenterX());
		//it ->second ->setPlayerY(sprite -> getCenterY());
		it ->second ->update();
	}

	for (std::vector < BulletSprite* > ::iterator it = bulletSprites.begin(); it != bulletSprites.end(); it++)
	{
		(*it) ->update();
	}
}
float Map :: getResX()
{
	return respawnX;
}
float Map :: getResY()
{
	return respawnY;
}

RectF Map :: getCameraTranslatePoint()
{
	return cameraTranslatePosition;
}

std::vector < std::string>&  Map :: getSpriteNames()
{
	return spriteNames;
}

bool Map :: isFinish()
{
	return bIsFinish;
}
#pragma endregion publicFunction


