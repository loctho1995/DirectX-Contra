#include "LoadingScene.h"
#include "Sound.h"
LoadingScene::LoadingScene()
{
	BitMapFont* font = new BitMapFont("Resources\\Fonts\\font.png", 
									"ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,\"\"|?!_-:;&(%'/ `abcdefghi",
									"fontByLinh",
									6,
									11,
									8,
									RectI(0, 0, 8, 8));
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

	std::string sourceFileBackGround  = "Resources\\BackGround\\LSBackGroundStage" + std::to_string(UIComponents::getInstance() -> getCurrentStage()) + ".png";
	std:: string bgname = "LSBackGroundStage1"  + std::to_string(UIComponents::getInstance() -> getCurrentStage());
	pBackGround = new Texture(sourceFileBackGround, bgname);

	Sound::getInstance()->loadSound("Resources\\Sounds\\stage1.wav", "stage1");
	Sound::getInstance()->loadSound("Resources\\Sounds\\stage2.wav", "stage2");
	Sound::getInstance()->loadSound("Resources\\Sounds\\stage3.wav", "stage3");
	Sound::getInstance()->loadSound("Resources\\Sounds\\beep.wav", "beep.wav");
    Sound::getInstance()->loadSound("Resources\\Sounds\\boss2bulletsound.wav", "boss2bulletsound.wav");
    Sound::getInstance()->loadSound("Resources\\Sounds\\boss2finaldestroy.wav", "boss2finaldestroy.wav");
    Sound::getInstance()->loadSound("Resources\\Sounds\\boss2finalhanddisappear.wav", "boss2finalhanddisappear.wav");
    Sound::getInstance()->loadSound("Resources\\Sounds\\bridgeexplosion.wav", "bridgeexplosion.wav");
    Sound::getInstance()->loadSound("Resources\\Sounds\\enemydead.wav", "enemydead.wav");
	Sound::getInstance()->loadSound("Resources\\Sounds\\warning.wav", "warning");
	Sound::getInstance()->loadSound("Resources\\Sounds\\explode.wav", "explode.wav");
	Sound::getInstance()->loadSound("Resources\\Sounds\\beShooted.wav", "beShooted");
	Sound::getInstance()->loadSound("Resources\\Sounds\\qexplode.wav", "qexplode");
	Sound::getInstance()->loadSound("Resources\\Sounds\\stonefailing.wav", "stonefailing");

	Sound::getInstance()->loadSound("Resources\\Sounds\\clearStage.wav", "clearStage");

	Sound::getInstance()->loadSound("Resources\\Sounds\\fallingmine.wav", "fallingmine");


	Sound::getInstance()->loadSound("Resources\\Sounds\\playerdie.wav", "playerdie");
	Sound::getInstance()->loadSound("Resources\\Sounds\\addlife.wav", "addlife");
	Sound::getInstance()->loadSound("Resources\\Sounds\\gameOver.wav", "gameOver");

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

	label = new Label*[COUNT];
	for (int i = 0; i < COUNT; i++)
	{
		label[i] = new Label();
	}

	label[TITLE] -> text = "LOADING";
	label[TITLE] -> color = D3DCOLOR_XRGB(255 , 0 , 0 );
	label[TITLE] -> size = 12;
	label[TITLE] -> xPos = SCWIDTH / 2 - label[TITLE] -> text.length() * label[TITLE] -> size / 2;
	label[TITLE] -> yPos = 20;

	label[SCORE] -> text = "SCORE  " + std::to_string(UIComponents::getInstance() -> getScore(0));
	label[SCORE] -> color = D3DCOLOR_XRGB(255 , 255 , 255 );
	label[SCORE] -> size = 8;
	label[SCORE] -> xPos = 10;
	label[SCORE] -> yPos = label[TITLE] -> yPos + 40;

	
	label[LIFES] -> text = "LIFES  " + std::to_string(UIComponents::getInstance() -> getLifes(0));
	label[LIFES] -> color = D3DCOLOR_XRGB(255 , 255 , 255 );
	label[LIFES] -> size = 8;
	label[LIFES] -> xPos = 10;
	label[LIFES] -> yPos = label[SCORE] -> yPos + 20;

	if(UIComponents::getInstance() -> getNumberPlayer() == 2)
	{
		label[SCORE2] -> text = "SCORE  " + std::to_string(UIComponents::getInstance() -> getScore(1));
		label[SCORE2] -> color = D3DCOLOR_XRGB(255 , 255 , 255 );
		label[SCORE2] -> size = 8;
		label[SCORE2] -> xPos = SCWIDTH - label[SCORE] -> xPos - label[SCORE2] -> text.length() * label[SCORE2] -> size;
		label[SCORE2] -> yPos = label[SCORE] -> yPos;

		label[LIFES2] -> text = "LIFES  " + std::to_string(UIComponents::getInstance() -> getLifes(1));
		label[LIFES2] -> color = D3DCOLOR_XRGB(255 , 255 , 255 );
		label[LIFES2] -> size = 8;
		label[LIFES2] -> xPos = SCWIDTH - label[LIFES] -> xPos - label[LIFES2] -> text.length() * label[LIFES2] -> size;
		label[LIFES2] -> yPos = label[LIFES] -> yPos;
	}

	label[STAGE] -> text = "STAGE " + std::to_string(UIComponents::getInstance() -> getCurrentStage());
	label[STAGE] -> color = D3DCOLOR_XRGB(255 , 255 , 255 );
	label[STAGE] -> size = 10;
	label[STAGE] -> xPos = SCWIDTH / 2 - label[STAGE] -> text.length() * label[STAGE] -> size / 2;
	label[STAGE] -> yPos = SCHEIGHT / 2- label[STAGE] -> size / 2;

	

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
		UIComponents::getInstance() -> newStage();
		KeyBoard::getInstace() -> flush();
        SceneManager::getInstance()->createSceneWithTransition(new PlayScene(), new TransitionScan());
	}
}
void LoadingScene:: render()
{
		Graphics::getInstance()->beginRender();
		Graphics::getInstance() ->getSpriteHandler() -> Begin(D3DXSPRITE_ALPHABLEND	);
		pBackGround -> draw(0.0f, 0.0f);
		
		for (int i = 0; i < COUNT; i++)
		{
			Graphics::getInstance() -> drawText(*label[i]);
		}

		Graphics::getInstance() ->getSpriteHandler() -> End();
		Graphics::getInstance()->endRender();
}