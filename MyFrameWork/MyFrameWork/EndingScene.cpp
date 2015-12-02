#include "EndingScene.h"


EndingScene::EndingScene(void)
{
	
	label.color = D3DCOLOR_ARGB(255, 255, 0, 0);
	label.text = "ENDING SCENE";
	label.size = 6;
	label.space = false;
	label.xPos = 10;
	label.yPos = 160;
}


EndingScene::~EndingScene(void)
{

}

void EndingScene:: onUpdate()
{
	handleInput();
}

void EndingScene:: handleInput()
{
	while (!KeyBoard::getInstace()->isEmpty())
	{
		KeyEvent e = KeyBoard::getInstace()->readKey();
		switch (e.getCode())
		{
		case VK_END:
			if (e.isRelease())
			{
				SceneManager::getInstance() ->createScene( new StartingScene());
			}
			break;
		}
	}
}
void EndingScene:: render()
{
	Graphics::getInstance()->beginRender();
	Graphics::getInstance() ->drawText(label);
	Graphics::getInstance()->endRender();
}
