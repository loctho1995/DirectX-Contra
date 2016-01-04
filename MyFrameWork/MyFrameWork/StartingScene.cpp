
#include "StartingScene.h"
#include "Graphics.h"
#include "KeyBoard.h"
#include "SceneManager.h"
StartingScene::StartingScene(void)
{
	BitMapFont* font = new BitMapFont("Resources\\Fonts\\font.png", 
									"ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,\"\"|?!/-:;&(%'+ `abcdefghi",
									"fontByLinh",
									6,
									11,
									8,
									RectI(0, 0, 8, 8));
	Graphics::getInstance() ->setFont(font);
	UIComponents::getInstance() -> resetStage();
	pBackGround = new Texture("Resources\\BackGround\\SSBackGround.png","SSBackGround");
	pCursor = new Texture("Resources\\BackGround\\OScursor.png","OScursor");
	label = new Label*[COUNT];
	
	startPosX = 40;
	startPosY = SCHEIGHT / 2;
	offsetY = 20;
	xPos = SCWIDTH;
	vxPos = -1.0f;
	isTransitioning = true;

	for (int i = 0; i < COUNT; i++)
	{
		label[i] = new Label();
		label[i] -> size = 10;
		label[i] -> color = D3DCOLOR_XRGB(255, 255, 255 );
		label[i] -> xPos = startPosX + xPos;
		label[i] -> yPos = startPosY + offsetY * i;
	}

	label[PLAYER] -> text = "1 PLAYER";
	label[PLAYER2] -> text = "2 PLAYERS";
	label[HELP] -> text = "HELP";
	label[OPTION] -> text = "OPTION";
	label[HISCORE] -> text = "HISCORE";
	label[QUIT] -> text = "QUIT";
	cursorIndex = PLAYER;

	

	Sound::getInstance() -> loadSound("Resources\\Sounds\\cursor.wav", "cursor");
	Sound::getInstance() -> loadSound("Resources\\Sounds\\select.wav", "select");
	Sound::getInstance() -> loadSound("Resources\\Sounds\\startingscene.wav", "startingscene");
	Sound::getInstance() -> play( "startingscene", false , 1);
}


StartingScene::~StartingScene(void)
{
}

void StartingScene:: onUpdate()
{
	update();
	handleInput();
}

void StartingScene:: render()
{
	Graphics::getInstance()->beginRender();

	Graphics::getInstance() ->getSpriteHandler() -> Begin(D3DXSPRITE_ALPHABLEND	);

	pBackGround -> draw(xPos, 0.0f);

	for (int i = 0; i < COUNT; i++)
	{
		Graphics::getInstance() -> drawText(*label[i]);
	}
	if(!isTransitioning)
	pCursor -> draw( startPosX - 20, label[cursorIndex] -> yPos - 5);

	Graphics::getInstance() ->getSpriteHandler() -> End();

	Graphics::getInstance()->endRender();
}

void StartingScene:: update()
{
	xPos += vxPos;
	xPos = max ( 0 , xPos);
	if(xPos == 0 )
	{
		isTransitioning = false;
	}
	for (int i = 0; i < COUNT; i++)
	{
		label[i] -> xPos = xPos + startPosX;
	}
}

void StartingScene:: handleInput()
{
	while (!KeyBoard::getInstace()->isEmpty())
	{
		KeyEvent e = KeyBoard::getInstace()->readKey();
		switch (e.getCode())
		{
		case VK_UP:
			{
				if(e.isRelease() && !isTransitioning)
				{
					Sound::getInstance() -> play("cursor", false ,1);
					if( cursorIndex == PLAYER )
					{
						cursorIndex = QUIT;
					}
					else
					{
						cursorIndex--;
					}
				}
			}
			break;
		case VK_DOWN:
			if(e.isRelease() && !isTransitioning)
				{
					Sound::getInstance() -> play("cursor", false ,1);
					if( cursorIndex == QUIT )
					{
						cursorIndex = PLAYER;
					}
					else
					{
						cursorIndex++;
					}
				}
			break;
		case VK_RETURN:
			if (e.isRelease())
			{
				if(isTransitioning)
				{
					xPos = 0;
				}
				else
				{
					if(cursorIndex == PLAYER)
					{
						Sound::getInstance() -> stop();
						Sound::getInstance() -> play("select", false, 1);
						UIComponents :: getInstance() -> setNumberPlayer(1);
						KeyBoard::getInstace() -> flush();
						SceneManager::getInstance() ->createSceneWithRandomTransition( new LoadingScene());
					}
					else if (cursorIndex == PLAYER2)
					{
						Sound::getInstance() -> stop();
						Sound::getInstance() -> play("select", false, 1);
						UIComponents :: getInstance() -> setNumberPlayer(2);
						KeyBoard::getInstace() -> flush();
						SceneManager::getInstance() ->createSceneWithRandomTransition( new LoadingScene());
					
					}
					else if ( cursorIndex == HELP)
					{
						Sound::getInstance() -> stop();
						Sound::getInstance() -> play("select", false, 1);
						KeyBoard::getInstace() -> flush();
						SceneManager::getInstance() ->createSceneWithRandomTransition( new HelpScene());
					}
					else if ( cursorIndex == OPTION)	
					{
						Sound::getInstance() -> play("select", false, 1);
						KeyBoard::getInstace() -> flush();
						SceneManager::getInstance() ->createSceneWithRandomTransition( new OptionScene());
					}
					
					else if ( cursorIndex == QUIT)
						PostQuitMessage(0);
					else if( cursorIndex == HISCORE)
					{
						Sound::getInstance() -> play("select", false, 1);
						KeyBoard::getInstace() -> flush();
						SceneManager::getInstance() ->createSceneWithRandomTransition( new HighScoreScene());
					}
				}
				
			}
			break;
		}
	}
		
}