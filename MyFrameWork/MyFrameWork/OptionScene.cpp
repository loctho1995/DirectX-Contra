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
	editText = new Label*[JUMP + 1];
	for (int i = 0; i < COUNT; i++)
	{
		label[i] = new Label();
	}
	for (int i = 0; i < JUMP + 1; i++)
	{
		editText[i] = new Label();
	}
	tittle.text = "OPTION";
	tittle.size = 10;
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
	label[VOLUMNE]->text = "VOLUMNE";
	label[BACK]->text = "BACK";

	int startPosY  = 40;
	int startPosX  = 40;
	int offsetY = 20;
	int offsetX = 90;
	for (int i = 0; i < COUNT; i++)
	{
		label[i]->size = 8;
		label[i]->yPos = startPosY + i * offsetY;
		label[i]->xPos = startPosX;
		if(i <= JUMP)
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
		SceneManager::getInstance() ->createScene(new StartingScene());
		return;
	}
	for (int i = 0; i <= JUMP; i++)
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
			if(i != cursorIndex && i <= JUMP )
			{
				editText[i]->color = D3DCOLOR_XRGB(255 , 255 , 255 );
			}
			else if(i == cursorIndex && i <= JUMP)
			{
				editText[i]->color = D3DCOLOR_XRGB(255 , 255 , 0 );
			}
		}
		else
		{
			if(i <= JUMP )
			{
				editText[i]->color = D3DCOLOR_XRGB(255 , 255 , 255 );
			}
		}
	}


}
void OptionScene:: render()
{
	Graphics::getInstance()->beginRender();
	Graphics::getInstance() ->drawText(tittle);
	for (int i = 0; i < COUNT; i++)
	{
		Graphics::getInstance() ->drawText(*label[i]);
		if( i <= JUMP)
		Graphics::getInstance() ->drawText(*editText[i]);
	}
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
				if(cursorIndex != DEFAULT && cursorIndex != BACK)
					isChoosing = !isChoosing;
				else if( cursorIndex == DEFAULT)
				{
					UIComponents::getInstance() -> setDefaultKeyBoard();
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
					if(!isChoosing)
					cursorIndex--;
					if(cursorIndex < 0)
						cursorIndex	 = COUNT - 1;
				}
				break;
			case VK_DOWN:
				if (e.isRelease() )
				{
					cursorIndex++;
					if(cursorIndex > COUNT - 1)
						cursorIndex	 = 0;
				}
				break;
			}
		}
		else
		{
			if( e.isRelease() )
			{				
				if(
				( e.getCode() >= 65 && e.getCode() <= 90 ) 
				|| e.getCode() == UIComponents::getInstance() ->getDefaultKey(UIComponents::UP)
				|| e.getCode() == UIComponents::getInstance() ->getDefaultKey(UIComponents::DOWN)
				|| e.getCode() == UIComponents::getInstance() ->getDefaultKey(UIComponents::LEFT)
				|| e.getCode() == UIComponents::getInstance() ->getDefaultKey(UIComponents::RIGHT)
				|| e.getCode() == UIComponents::getInstance() ->getDefaultKey(UIComponents::JUMP)
				)
				{
					if( cursorIndex < COUNT - 2 )
					{
						UIComponents::getInstance() -> setKey( cursorIndex, e.getCode());
					}
				}
			}
			
		}
		

		
	}
}