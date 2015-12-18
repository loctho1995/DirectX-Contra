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

	Sound::getInstance()->loadSound("Resources\\Sounds\\stage1.wav", "stage1");
	Sound::getInstance()->loadSound("Resources\\Sounds\\stage3.wav", "stage3");
	Sound::getInstance()->loadSound("Resources\\Sounds\\stage5.wav", "stage5");
	Sound::getInstance()->loadSound("Resources\\Sounds\\beep.wav", "beep.wav");
    Sound::getInstance()->loadSound("Resources\\Sounds\\boss2bulletsound.wav", "boss2bulletsound.wav");
    Sound::getInstance()->loadSound("Resources\\Sounds\\boss2finaldestroy.wav", "boss2finaldestroy.wav");
    Sound::getInstance()->loadSound("Resources\\Sounds\\boss2finalhanddisappear.wav", "boss2finalhanddisappear.wav");
    Sound::getInstance()->loadSound("Resources\\Sounds\\bridgeexplosion.wav", "bridgeexplosion.wav");
    Sound::getInstance()->loadSound("Resources\\Sounds\\enemydead.wav", "enemydead.wav");
	Sound::getInstance()->loadSound("Resources\\Sounds\\warning.wav", "warning");
	Sound::getInstance()->loadSound("Resources\\Sounds\\explode.wav", "explode.wav");
	Sound::getInstance()->loadSound("Resources\\Sounds\\beShooted.wav", "beShooted");

	Sound::getInstance()->loadSound("Resources\\Sounds\\clearStage.wav", "clearStage");

	Sound::getInstance()->loadSound("Resources\\Sounds\\fallingmine.wav", "fallingmine");


	Sound::getInstance()->loadSound("Resources\\Sounds\\playerdie.wav", "playerdie");
	Sound::getInstance()->loadSound("Resources\\Sounds\\addlife.wav", "addlife");
	Sound::getInstance()->loadSound("Resources\\Sounds\\gameOver.wav", "gameOver");
	Sound::getInstance()->loadSound("Resources\\Sounds\\endingscene.wav", "endingscene");

	Sound::getInstance()->loadSound("Resources\\Sounds\\shootL.wav", "shootL");
	Sound::getInstance()->loadSound("Resources\\Sounds\\shootM.wav", "shootM");
	Sound::getInstance()->loadSound("Resources\\Sounds\\shootS.wav", "shootS");
	Sound::getInstance()->loadSound("Resources\\Sounds\\shootF.wav", "shootF");

	Sound::getInstance()->loadSound("Resources\\Sounds\\weaponL.wav", "weaponL");
	Sound::getInstance()->loadSound("Resources\\Sounds\\weaponM.wav", "weaponM");
	Sound::getInstance()->loadSound("Resources\\Sounds\\weaponS.wav", "weaponS");
	Sound::getInstance()->loadSound("Resources\\Sounds\\weaponF.wav", "weaponF");
	Sound::getInstance()->loadSound("Resources\\Sounds\\weaponB.wav", "weaponB");
	Sound::getInstance()->loadSound("Resources\\Sounds\\weaponR.wav", "weaponR");
	Sound::getInstance()->loadSound("Resources\\Sounds\\weaponD.wav", "weaponD");
	Sound::getInstance()->loadSound("Resources\\Sounds\\landing.wav", "landing");

	Sound::getInstance()->loadSound("Resources\\Sounds\\tank.wav", "tank");
	Sound::getInstance()->loadSound("Resources\\Sounds\\exbullet.wav", "exbullet");


	Sound::getInstance() -> play("clearStage", false , 1);
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
        SceneManager::getInstance()->createSceneWithTransition(new PlayScene(), new TransitionCircleScan());
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