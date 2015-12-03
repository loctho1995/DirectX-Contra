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
#include "BitMapFont.h"

class HelpScene : public Scene
{
public:
    HelpScene();
    ~HelpScene();

    virtual void onUpdate();
    virtual void render();
    virtual void handleInput();
    virtual void update();
    void onCollision();

private:
    std::string getKeyName(int index);
    PlayerSprite* pPlayer;
    ViewPort* viewPort;
    Camera* cam;
    Map* pMap;
    Texture* lifeTexture;
    int count;
    int stageIndex;
    bool isPause;
    bool isHelpRight, isHelpLeft, isHelpDown, isHelpUp, isHelpFire, isHelpJump, isMoreInfo, isBulletHelp, isPlayerRead;
    Label label, labelConversation;
    
    int frameChangeConversation, conversationFrame, conversationNum;
};

