
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
}


StartingScene::~StartingScene(void)
{
}

void StartingScene:: onUpdate()
{
	handleInput();
}

void StartingScene:: render()
{
	Graphics::getInstance()->beginRender();

	Graphics::getInstance() ->getSpriteHandler() -> Begin(D3DXSPRITE_ALPHABLEND	);

	Graphics::getInstance() ->drawText("STARTING SCENE", 10 , 0 , 100);

	Graphics::getInstance() ->drawText("PRESS ENTER GUYS", 10 , 10 , 160, false, D3DCOLOR_ARGB(255, 255, 0, 0));

	Graphics::getInstance() ->getSpriteHandler() -> End();

	Graphics::getInstance()->endRender();
}

void StartingScene:: handleInput()
{
	while (!KeyBoard::getInstace()->isEmpty())
	{
		KeyEvent e = KeyBoard::getInstace()->readKey();
		switch (e.getCode())
		{
		case VK_RETURN:
			if (e.isRelease())
			{
				SceneManager::getInstance() ->createScene( new LoadingScene());
			}
			break;
		}
	}
		
}