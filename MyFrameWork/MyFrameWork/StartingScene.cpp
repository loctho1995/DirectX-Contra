
#include "StartingScene.h"
#include "Graphics.h"
#include "KeyBoard.h"
#include "SceneManager.h"
StartingScene::StartingScene(void)
{
	BitMapFont* font = new BitMapFont("Resources\\Fonts\\fontByLinh.png", 
									"ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,\"\"|?!_-:;&(%'/ ",
									"fontByLinh",
									6,
									9,
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

	label[PLAY] -> text = "PLAY";
	label[HELP] -> text = "HELP";
	label[OPTION] -> text = "OPTION";
	label[QUIT] -> text = "QUIT";
	cursorIndex = PLAY;

	

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
					if( cursorIndex == PLAY )
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
						cursorIndex = PLAY;
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
					if(cursorIndex == PLAY)
					{
						Sound::getInstance() -> stop();
						Sound::getInstance() -> play("select", false, 1);
						SceneManager::getInstance() ->createSceneWithTransition( new LoadingScene(), new TransitionScan());
					}
					else if ( cursorIndex == HELP)
					{
						Sound::getInstance() -> stop();
						Sound::getInstance() -> play("select", false, 1);
						SceneManager::getInstance() ->createSceneWithTransition( new HelpScene(), new TransitionScan());
					}
					else if ( cursorIndex == OPTION)	
					{
						Sound::getInstance() -> play("select", false, 1);
						SceneManager::getInstance() ->createSceneWithTransition( new OptionScene(), new TransitionScan());
					}
					
					else if ( cursorIndex == QUIT)
						PostQuitMessage(0);
				}
				
			}
			break;
		}
	}
		
}