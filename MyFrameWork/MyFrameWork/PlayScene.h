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
#include "SceneManager.h"
#include "Sound.h"

class PlayScene : public Scene
{
public:
	PlayScene(int mapID);
	PlayScene() {}
	virtual ~PlayScene() {}

	virtual void onCollision();
	virtual void handleInput();
	virtual void render();
	virtual void onUpdate();
	virtual void update();

private:
	PlayerSprite* pPlayer;
	ViewPort* viewPort;
	Camera* cam;
	Map* pMap;
	int nTransitionFrames;
	int count;
	int stageIndex;
	bool isGameOver;
	bool isFinish;
	bool isPause;
};

