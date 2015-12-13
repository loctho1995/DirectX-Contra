#include "LoadingScene.h"
#include "Sound.h"
LoadingScene::LoadingScene()
{
	BitMapFont* font = new BitMapFont("Resources\\Fonts\\fontAA.png", 
									"ABCDEFGHIKLMNOPQRSTUVXWZY",
									"fontAA",
									10,
									3,
									13,
									RectI(0, 0, 28, 30));
	Graphics::getInstance() ->setFont(font);

	int stageIndex = UIComponents::getInstance()->getCurrentStage();
	std:: string mapName = "stage" + std::to_string(stageIndex);;
    Map* map = new Map(mapName);
	std :: vector< std:: string> spriteNames = map ->getSpriteNames();
	delete map;
	if(stageIndex == 1)
	{
		spriteNames.push_back("player");
	}
	nSprites = spriteNames.size();
	loadedSprite = 0;
	std::thread LoadingThread ((Loader()),spriteNames,  std::ref(loadedSprite));
	LoadingThread.detach();

	nTransitionTime = 5 * 60;
	count = 0;

	Sound::getInstance()->loadSound("Resources\\Sounds\\background2.wav", "background2.wav");
	Sound::getInstance()->play("background2.wav", true , 1);
	Sound::getInstance()->loadSound("Resources\\Sounds\\beep.wav", "beep.wav");
    Sound::getInstance()->loadSound("Resources\\Sounds\\boss2bulletsound.wav", "boss2bulletsound.wav");
    Sound::getInstance()->loadSound("Resources\\Sounds\\boss2finaldestroy.wav", "boss2finaldestroy.wav");
    Sound::getInstance()->loadSound("Resources\\Sounds\\boss2finalhanddisappear.wav", "boss2finalhanddisappear.wav");
    Sound::getInstance()->loadSound("Resources\\Sounds\\bridgeexplosion.wav", "bridgeexplosion.wav");
    Sound::getInstance()->loadSound("Resources\\Sounds\\enemydead.wav", "enemydead.wav");
}


LoadingScene::~LoadingScene(void)
{
}

void LoadingScene::onUpdate()
{
	count ++;
	std :: cout << loadedSprite << "/" << nSprites << "\n";
	if( loadedSprite == nSprites && count == nTransitionTime)
	{
		//SceneManager::getInstance() -> createScene( new PlayScene());
        SceneManager::getInstance()->createSceneWithTransition(this, new PlayScene(), new TransitionScanDown(0.005f));
	}
}
void LoadingScene:: render()
{
		Graphics::getInstance()->beginRender();
		Graphics::getInstance() ->getSpriteHandler() -> Begin(D3DXSPRITE_ALPHABLEND	);
		if(UIComponents::getInstance() -> getCurrentStage() == 1)
		{
			Graphics::getInstance() ->drawText("STAGE ONE", 8 , 10 , 160, false,  D3DCOLOR_ARGB(255, 255, 0, 0));
		}
		else if(UIComponents::getInstance() -> getCurrentStage() == 3)
		{
			Graphics::getInstance() ->drawText("STAGE THREE", 8 , 10 , 160, false, D3DCOLOR_ARGB(255, 255, 0, 0));
		}

		Graphics::getInstance() ->drawText("READY TO GO ", 8 , 10 , 240, false, D3DCOLOR_ARGB(255, 255, 0, 0));
		Graphics::getInstance() ->getSpriteHandler() -> End();
		Graphics::getInstance()->endRender();
}