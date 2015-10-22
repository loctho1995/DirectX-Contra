#pragma once
#include "Scene.h"
#include "PlayerSprite.h"
#include "Camera.h"
#include "QuadTree.h"
#include "Map.h"
#include "KeyBoard.h"
#include "EnermySoldier.h"
#include "ObjectBridge.h"
#include "ObjectStaticWeapon.h"

class PlayScene : public Scene
{
public:
	PlayScene(int mapID);
	PlayScene() {}
	virtual ~PlayScene() {}

	virtual void go()
	{
		handleInput();
		onUpdate();
		onCollision();
		render();
	}

	virtual void onCollision();
	virtual void handleInput();
	virtual void render();
	virtual void onUpdate();

private:
	PlayerSprite* pPlayer;
	ViewPort* viewPort;
	Camera* cam;
	Map* pMap;
    ObjectStaticWeapon *staticWeapon;
};

