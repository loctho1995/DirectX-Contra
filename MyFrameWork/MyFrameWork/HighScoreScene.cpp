#include "HighScoreScene.h"


HighScoreScene::HighScoreScene(void)
{
	tittle.text = "HISCORE";
	tittle.size = 12;
	tittle.color = D3DCOLOR_XRGB(255, 0, 0);
	tittle.xPos = 256 / 2 - tittle.text.length() * tittle.size / 2;
	tittle.yPos = 10;

	float startPosY = 40;
	float startPosX = 40;
	float offsetY = 20;
	float offsetX = 60;

	Score* score = UIComponents::getInstance()->getHighScoreObject();
	Score* temp = score;
	label = new Label*[5];
	for (int i = 0; i < 5; i++)
	{
		label[i] = new Label();
	}
	for (int i = 0; i < 5; i++)
	{
		label[i]->color = D3DCOLOR_XRGB(255, 255, 255);
		label[i]->size = 8;
		label[i]->xPos = startPosX;
		label[i]->yPos = startPosY + i * offsetY;


		if (temp && temp->getScore())
		{
			label[i]->text = std::to_string(i + 1) + ".	" + std::to_string(temp->getScore()) + "	" + temp->getDate();
			temp = temp->getNextScore();
		}
		else
		{
			break;
		}

	}
}


HighScoreScene::~HighScoreScene(void)
{

}

void HighScoreScene::render()
{
	Graphics::getInstance()->beginRender();
	Graphics::getInstance()->getSpriteHandler()->Begin(D3DXSPRITE_ALPHABLEND);

	Graphics::getInstance()->drawText(tittle);
	for (int i = 0; i < 5; i++)
	{
		Graphics::getInstance()->drawText(*label[i]);
	}

	Graphics::getInstance()->getSpriteHandler()->End();
	Graphics::getInstance()->endRender();
}
void HighScoreScene::onUpdate()
{
	handleInput();
}

void HighScoreScene::handleInput()
{
	while (!KeyBoard::getInstace()->isEmpty())
	{
		KeyEvent e = KeyBoard::getInstace()->readKey();
		switch (e.getCode())
		{
		case VK_ESCAPE:
			if (e.isRelease())
			{
				Sound::getInstance()->stop();
				SceneManager::getInstance()->createSceneWithRandomTransition(new StartingScene());
			}
			break;
		default:
			break;
		}
	}
}