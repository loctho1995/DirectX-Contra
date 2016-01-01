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
#include "Shader.h"
#include "Lighting.h"
#include "AmbientLight.h"
#include "GameSaveLoad.h"

class PlayScene : public Scene
{
public:

	PlayScene();
	virtual ~PlayScene();

	virtual void onCollision();
	virtual void handleInput();
	virtual void render();
	virtual void onUpdate();
	virtual void update();

private:
	PlayerSprite** pPlayer;
	ViewPort* viewPort;
	Camera* cam;
	Map* pMap;
	Texture** lifeTexture;
	int nTransitionFrames;
	int count;
	int stageIndex;
	bool isGameOver;
	bool isFinish;
	bool isPause;
	int nPlayers;
private:
	Shader* shader;
	Lighting** light;
	AmbientLight* ambientLight;
	bool isEffectOn;
};

