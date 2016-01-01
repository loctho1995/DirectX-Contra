#include "OptionScene.h"


OptionScene::OptionScene(void)
{
	BitMapFont* font = new BitMapFont("Resources\\Fonts\\font.png", 
									"ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,\"\"|?!_-:;&(%'/ `abcdefghi",
									"fontByLinh",
									6,
									11,
									8,
									RectI(0, 0, 8, 8));
	Graphics::getInstance() ->setFont(font);

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

	
	label[LEFT] -> text = label[LEFT2] -> text = "LEFT";
	label[RIGHT]->text = label[RIGHT2] -> text = "RIGHT";
	label[UP]->text = label[UP2] -> text = "UP";
	label[DOWN]->text = label[DOWN2] -> text = "DOWN";
	label[FIRE]->text = label[FIRE2] -> text = "FIRE";
	label[JUMP]->text = label[JUMP2] -> text = "JUMP";
	label[DEFAULT]->text = "DEFAULT";
	label[VOLUME]->text = "VOLUME";
	label[BACK]->text = "BACK";

	startPosY  = 40;
	startPosX  = 40;
	offsetY = 20;
	offsetX = 60;
	for (int i = 0; i < COUNT; i++)
	{
		label[i]->size = 8;
		
		if(i < LEFT2)
		{
			label[i]->yPos = startPosY + i * offsetY;
			label[i]->xPos = startPosX;
		}
		else if( i >= LEFT2 && i <= JUMP2)
		{
			label[i]->yPos = startPosY + (i - LEFT2) * offsetY;
			label[i]->xPos = SCWIDTH / 2 + startPosX;
		}
		else if( i > JUMP2 )
		{
			label[i]->yPos = startPosY + (i - LEFT2) * offsetY;
			label[i]->xPos = SCWIDTH / 2 - label[i] -> text.length() * label[i] -> size / 2;
		}
		
		if(i <= VOLUME)
		{
			editText[i]->size = 8;
			editText[i]->space = true;
			if(i < LEFT2)
			{
				
				editText[i]->yPos = startPosY + i * offsetY;
				editText[i]->xPos = startPosX + offsetX;
			}
			else if ( i >= LEFT2 && i < VOLUME)
			{
				editText[i]->yPos = startPosY + (i - LEFT2) * offsetY;
				editText[i]->xPos = SCWIDTH / 2 + startPosX + offsetX;
			}
			else 
			{
				editText[i]->yPos = startPosY + (i - LEFT2) * offsetY;
				editText[i]->xPos = label[i] -> xPos + offsetX;
			}
			
		}
	}
	cursorIndex = LEFT;
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
		if(i < LEFT2)
		{
			editText[i]->text = std::string(1,UIComponents::getInstance() -> getKey(i, 0));
		}
		else
		{
			editText[i]->text = std::string(1,UIComponents::getInstance() -> getKey(i - LEFT2, 1));
		}
		
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

	pCursor -> draw(label[cursorIndex] -> xPos - 20, label[cursorIndex] -> yPos - 5);
	Graphics::getInstance() ->getSpriteHandler() -> End();
	Graphics::getInstance()->endRender();
}
void OptionScene:: handleInput()
{
	while (!KeyBoard::getInstace()->isEmpty())
	{
		KeyEvent e = KeyBoard::getInstace()->readKey();
		unsigned char const selectKey = UIComponents::getInstance() -> getKey(UIComponents::SELECT, 0);
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
			continue;
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
					 UIComponents::getInstance() -> isAllowedKey( e.getCode()) && ( cursorIndex <= JUMP || (cursorIndex > JUMP &&  cursorIndex <= JUMP2))
				   )
				{
						if(e.isRelease() )
						{
							Sound::getInstance() -> play("cursor", false, 1);
							if(cursorIndex <= JUMP )
							{
								UIComponents::getInstance() -> setKey( cursorIndex, e.getCode(), 0);
							}
							else if ( cursorIndex > JUMP &&  cursorIndex <= JUMP2)
							{
								UIComponents::getInstance() -> setKey( cursorIndex - LEFT2, e.getCode(), 1);
							}
						}
						
						
						
				}
				 else
				if( cursorIndex == VOLUME )
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