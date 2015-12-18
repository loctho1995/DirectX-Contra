#include "OptionScene.h"


OptionScene::OptionScene(void)
{
	BitMapFont* font = new BitMapFont("Resources\\Fonts\\fontByLinh.png", 
									"ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,\"\"|?!_-:;&(%'/ ",
									"fontByLinh",
									6,
									9,
									8,
									RectI(0, 0, 8, 8));

	Graphics::getInstance() ->setFont(font);
	label = new Label*[COUNT];
	editText = new Label*[VOLUME + 1];
	for (int i = 0; i < COUNT; i++)
	{
		label[i] = new Label();
	}
	for (int i = 0; i < VOLUME + 1; i++)
	{
		editText[i] = new Label();
	}
	tittle.text = "OPTION";
	tittle.size = 12;
	tittle.color = D3DCOLOR_XRGB(255, 0, 0);
	tittle.xPos = 256 / 2 - tittle.text.length() * tittle.size / 2;
	tittle.yPos = 10;

	
	label[LEFT] -> text = "LEFT";
	label[RIGHT]->text = "RIGHT";
	label[UP]->text = "UP";
	label[DOWN]->text = "DOWN";
	label[FIRE]->text = "FIRE";
	label[JUMP]->text = "JUMP";
	label[DEFAULT]->text = "DEFAULT";
	label[VOLUME]->text = "VOLUME";
	label[BACK]->text = "BACK";

	startPosY  = 40;
	startPosX  = 40;
	offsetY = 20;
	offsetX = 90;
	for (int i = 0; i < COUNT; i++)
	{
		label[i]->size = 8;
		label[i]->yPos = startPosY + i * offsetY;
		label[i]->xPos = startPosX;
		if(i <= VOLUME)
		{
			editText[i]->size = 8;
			editText[i]->space = true;
			editText[i]->yPos = startPosY + i * offsetY;
			editText[i]->xPos = startPosX + offsetX;
		}
	}
	cursorIndex = 0;
	isChoosing = false;
	isBack = false;
	volumeStep = 0;
	volume = Sound::getInstance() -> getVolume();

	pBackGround = new Texture("Resources\\BackGround\\OSBackGround.png","OSBackGround");
	pCursor = new Texture("Resources\\BackGround\\OScursor.png","OScursor");
	

	
}


OptionScene::~OptionScene()
{
	
}

void OptionScene:: onUpdate()
{
	handleInput();
	update();
}
void OptionScene :: update()
{
	if( isBack )
	{
		SceneManager::getInstance() ->createSceneWithTransition(new StartingScene(), new TransitionCircleOpen());
		return;
	}
	for (int i = 0; i <= VOLUME; i++)
	{
		editText[i]->text = std::string(1,UIComponents::getInstance() -> getKey(i));
	}

	for (int i = 0; i < COUNT; i++)
	{

		if(i != cursorIndex )
		{
			label[i]->color = D3DCOLOR_XRGB(255 , 255 , 255 );
		}
		else
		{
			label[i]->color = D3DCOLOR_XRGB(255 , 255 , 0 );
		}

		if( isChoosing )
		{
			if(i != cursorIndex && i <= VOLUME )
			{
				editText[i]->color = D3DCOLOR_XRGB(255 , 255 , 255 );
			}
			else if(i == cursorIndex && i <= VOLUME)
			{
				editText[i]->color = D3DCOLOR_XRGB(255 , 255 , 0 );
			}
		}
		else
		{
			if(i <= VOLUME )
			{
				editText[i]->color = D3DCOLOR_XRGB(255 , 255 , 255 );
			}
		}
	}


	volume += volumeStep;
	volume = min ( volume , 100.0f );
	volume = max(volume , 0.0f);
	editText[VOLUME] -> text = std::to_string((int)volume) + "%";
	Sound::getInstance() -> setVolume(volume * 2);


}
void OptionScene:: render()
{
	Graphics::getInstance()->beginRender();
	Graphics::getInstance() ->getSpriteHandler() -> Begin(D3DXSPRITE_ALPHABLEND	);
	pBackGround -> draw(0, 0);
	Graphics::getInstance() ->drawText(tittle);
	for (int i = 0; i < COUNT; i++)
	{
		Graphics::getInstance() ->drawText(*label[i]);
		if( i <= VOLUME)
		Graphics::getInstance() ->drawText(*editText[i]);
	}

	pCursor -> draw(10, startPosY + offsetY * cursorIndex - 5);
	Graphics::getInstance() ->getSpriteHandler() -> End();
	Graphics::getInstance()->endRender();
}
void OptionScene:: handleInput()
{
	while (!KeyBoard::getInstace()->isEmpty())
	{
		KeyEvent e = KeyBoard::getInstace()->readKey();
		unsigned char const selectKey = UIComponents::getInstance() -> getKey(UIComponents::SELECT);
		if(e.getCode() == selectKey)
		{
			if (e.isRelease())
			{
				Sound::getInstance() -> play("select", false, 1);

				if(cursorIndex != DEFAULT && cursorIndex != BACK)
					isChoosing = !isChoosing;
				else if( cursorIndex == DEFAULT)
				{
					UIComponents::getInstance() -> setDefaultKeyBoard();
					volume = 100.0f;
					Sound :: getInstance() -> setVolume(100.0f);
				}
				else if( cursorIndex == BACK)
				{
					isBack = true;
					return;
				}
				
			}
		}
		if(!isChoosing)
		{
			switch (e.getCode())
			{
			case VK_UP:
				if (e.isRelease() )
				{
					Sound::getInstance() -> play("cursor", false, 1);
					if(!isChoosing)
					cursorIndex--;
					if(cursorIndex < 0)
						cursorIndex	 = COUNT - 1;
				}
				break;
			case VK_DOWN:
				if (e.isRelease() )
				{
					Sound::getInstance() -> play("cursor", false, 1);
					cursorIndex++;
					if(cursorIndex > COUNT - 1)
						cursorIndex	 = 0;
				}
				break;
			}
		}
		else
		{
			
				if(
					cursorIndex <= JUMP && e.isRelease() &&
				( ( e.getCode() >= 65 && e.getCode() <= 90 ) 
				|| e.getCode() == UIComponents::getInstance() ->getDefaultKey(UIComponents::UP)
				|| e.getCode() == UIComponents::getInstance() ->getDefaultKey(UIComponents::DOWN)
				|| e.getCode() == UIComponents::getInstance() ->getDefaultKey(UIComponents::LEFT)
				|| e.getCode() == UIComponents::getInstance() ->getDefaultKey(UIComponents::RIGHT)
				|| e.getCode() == UIComponents::getInstance() ->getDefaultKey(UIComponents::JUMP) )

				)
				{
						Sound::getInstance() -> play("cursor", false, 1);
						UIComponents::getInstance() -> setKey( cursorIndex, e.getCode());
				}
				else if( cursorIndex == VOLUME )
				{
					switch (e.getCode())
					{
					case VK_UP:
						if (e.isRelease() )
						{
							Sound::getInstance() -> play("cursor", false, 1);
							volumeStep = 0;	
						}
						else
						{
							volumeStep = 0.25f;
						}
						break;
					case VK_DOWN:
						if (e.isRelease() )
						{
							Sound::getInstance() -> play("cursor", false, 1);
							volumeStep = 0;
						}
						else
						{
							volumeStep = -0.25f;
						}
						break;
					}
				}
			}
			
		
	}
}