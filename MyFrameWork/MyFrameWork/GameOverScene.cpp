#include "GameOverScene.h"
#include "TransitionCircleOpen.h"
#include "TransitionScan.h"
GameOverScene::GameOverScene()
{
	pBackGround = new Texture("Resources\\BackGround\\GOSBackGround.png","GOSBackGround");
	pCursor = new Texture("Resources\\BackGround\\OScursor.png", "OScursor");
	Sound::getInstance() -> play("gameOver", false , 1);
	label = new Label*[COUNT];
	for (int i = 0; i < COUNT; i++)
	{
		label[i] = new Label();
	}
	label[TITLE] -> text = "GAME OVER";
	label[TITLE] -> color = D3DCOLOR_XRGB(255 , 0 , 0 );
	label[TITLE] -> size = 12;
	label[TITLE] -> xPos = 256 / 2 - label[TITLE] -> text.length() * label[TITLE] -> size / 2;
	label[TITLE] -> yPos = 10;
	

	label[SCORE] -> text = "SCORE " + std::to_string(UIComponents::getInstance() -> getScore(0));
	label[SCORE] -> color = D3DCOLOR_XRGB(255 , 255 , 255 );
	label[SCORE] -> size = 8;
	label[SCORE] -> xPos = 10;
	label[SCORE] -> yPos = label[TITLE] -> yPos + 40;

	if(UIComponents::getInstance() -> getNumberPlayer() == 2)
	{
		label[SCORE2] -> text = "SCORE " + std::to_string(UIComponents::getInstance() -> getScore(1));
		label[SCORE2] -> color = D3DCOLOR_XRGB(255 , 255 , 255 );
		label[SCORE2] -> size = 8;
		label[SCORE2] -> xPos = SCWIDTH - label[SCORE] -> xPos - label[SCORE2] -> text.length() * label[SCORE2] -> size;;
		label[SCORE2] -> yPos = label[SCORE] -> yPos;
	}
	
	label[HISCORE] -> text = "HISCORE " + std::to_string(UIComponents::getInstance() -> getHighScore());
	label[HISCORE] -> color = D3DCOLOR_XRGB(255 , 255 , 255 );
	label[HISCORE] -> size = 8;
	label[HISCORE] -> xPos = SCWIDTH / 2 - label[HISCORE] -> text.length() * label[HISCORE] -> size / 2;
	label[HISCORE] -> yPos = label[SCORE] -> yPos + 20;
	
	label[CONTINUE] -> text = "CONTINUE";
	label[CONTINUE] -> color = D3DCOLOR_XRGB(255 , 255 , 255 );
	label[CONTINUE] -> size = 10;
	label[CONTINUE] -> xPos = SCWIDTH / 2 - label[CONTINUE] -> text.length() * label[CONTINUE] -> size / 2;
	label[CONTINUE] -> yPos = SCHEIGHT / 2 -  label[CONTINUE] -> size / 2;
	

	label[END] -> text = "END";
	label[END] -> color = D3DCOLOR_XRGB(255 , 255 , 255 );
	label[END] -> size = 10;
	label[END] -> xPos = label[CONTINUE] -> xPos;
	label[END] -> yPos = label[CONTINUE] -> yPos + 30;
	
	cursorIndex = CONTINUE;
}


GameOverScene::~GameOverScene(void)
{
	if(pBackGround)
		delete pBackGround;
	if(pCursor)
		delete pCursor;
}

void GameOverScene:: onUpdate()
{
	handleInput();
}
void GameOverScene:: render()
{
	Graphics::getInstance()->beginRender();

	Graphics::getInstance() ->getSpriteHandler() -> Begin(D3DXSPRITE_ALPHABLEND	);

	pBackGround -> draw(0.0f, 0.0f);
	

	for (int i = 0; i < COUNT; i++)
	{
		Graphics::getInstance() -> drawText (*label[i]);
	}

	pCursor -> draw(label[cursorIndex] -> xPos - 20, label[cursorIndex] -> yPos - 5);

	Graphics::getInstance() ->getSpriteHandler() -> End();

	Graphics::getInstance()->endRender();
}

void GameOverScene:: handleInput()
{
	while (!KeyBoard::getInstace()->isEmpty())
	{
		KeyEvent e = KeyBoard::getInstace()->readKey();
		switch (e.getCode())
		{
		case VK_UP:

			if (e.isRelease())
			{
				Sound::getInstance() -> play("cursor", false, 1);
				if(cursorIndex == CONTINUE)
				{
					cursorIndex = END;
				}
				else
				{
					cursorIndex = CONTINUE;
				}
			}
			break;
		case VK_DOWN:
			if (e.isRelease())
			{
				Sound::getInstance() -> play("cursor", false, 1);
				if(cursorIndex == CONTINUE)
				{
					cursorIndex = END;
				}
				else
				{
					cursorIndex = CONTINUE;
				}
				
			}
			break;
		case VK_RETURN:
			{
				if (e.isRelease())
				{
					Sound::getInstance() -> stop();
					Sound::getInstance() -> play("select", false, 1);
					UIComponents::getInstance() -> gameOverReset();
					if(cursorIndex == CONTINUE)
					{
						SceneManager::getInstance() ->createSceneWithTransition( new PlayScene(), new TransitionCircleOpen());
						return;
					}
					else
					{
						Sound::getInstance() -> stop();
						Sound::getInstance() -> play("select", false, 1);
						SceneManager::getInstance() ->createSceneWithTransition( new StartingScene(), new TransitionScan());
						return;
					}
				}
			}
			break;
		}
	}
}
