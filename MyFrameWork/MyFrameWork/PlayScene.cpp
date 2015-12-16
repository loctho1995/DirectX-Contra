#include "PlayScene.h"


PlayScene ::PlayScene()
{
    std:: string mapName = "stage" + std::to_string(UIComponents::getInstance() ->getCurrentStage());
    pMap = new Map(mapName);
	
	lifeTexture = new Texture("Resources\\Sprites\\player\\life00.png", "life00.png");
    int viewPortSize = pMap->getMapRect().width < pMap->getMapRect().height ? pMap->getMapRect().width : pMap->getMapRect().height;
    viewPort = new ViewPort(RectI(SCWIDTH / 2 - viewPortSize / 2, SCHEIGHT / 2 - viewPortSize / 2, viewPortSize, viewPortSize));
	cam = new Camera(viewPort,pMap ->getResX(), pMap ->getResY(), pMap->getMapRect(), pMap ->getCameraTranslatePoint());
	pPlayer = new PlayerSprite(pMap ->getResX(), pMap ->getResY(), cam ->getMoveDir());
	isPause = false;
	isFinish = false;
	isGameOver = false;
	nTransitionFrames = 5 * 60;
	count = 0;
	if(UIComponents:: getInstance() -> getCurrentStage() == 5)
	{
		isEffectOn = true;
	}
	else
	{
		isEffectOn = false;
	}
	if(isEffectOn)
	{
		shader = new Shader("Resources\\Shader\\lightShader.fx");

		light = new Lighting(D3DXVECTOR4(0, 0, -0.25f , 0), D3DXVECTOR4(0, 0, 1, 0), 0.9f, 1.0f, D3DXVECTOR4(0.0, 0.0, 0, 0));
	}
	else
	{
		shader = NULL;
		light = NULL;
	}

	Sound::getInstance()->play("stage" + std::to_string(UIComponents::getInstance() -> getCurrentStage()), true , 1);
	
}

PlayScene ::~PlayScene()
{
	delete pPlayer;
	pPlayer = NULL;
	delete viewPort;
	viewPort = NULL;

	delete cam;
	cam = NULL;
	delete pMap;
	pMap = NULL;
	delete lifeTexture;
	lifeTexture = NULL;
	if( shader)
	{
		delete shader;
	}
	if( light )
	{
		delete light;
	}
}

void PlayScene::onCollision()
{
    pMap->onCollision(pPlayer, cam);
}

void PlayScene::handleInput()
{
    while (!KeyBoard::getInstace()->isEmpty())
    {
        KeyEvent e = KeyBoard::getInstace()->readKey();
		if( e.getCode() == UIComponents::getInstance() ->getKey(UIComponents::SELECT) )
		{
			if (e.isRelease())
			{
				isPause = !isPause;
			}
			break;
		}
		else if ( e.getCode() == 0x53 ) 
		{
			if (e.isRelease())
			{
				Sound::getInstance() ->stop();
			}
		}
		else if ( e.getCode() == 0x50)
		{
			if (e.isRelease())
			{
				Sound::getInstance() ->play("background2.wav", true, 1);
			}
		}
		else if( !isPause)
		{
			char keyCode = e.getCode();
			if( keyCode == UIComponents::getInstance() ->getKey(UIComponents::RIGHT) )
			{
				if (e.isPress())
				{
					pPlayer->getState()->onMovePressed(Direction::createRight());
				}
				else
				{
					pPlayer->getState()->onMoveReleased(Direction::createRight());
				}
			}
			else if ( keyCode == UIComponents::getInstance() -> getKey(UIComponents::LEFT))
			{
				if (e.isPress())
				{
					pPlayer->getState()->onMovePressed(Direction::createLeft());
				}
				else
				{
					pPlayer->getState()->onMoveReleased(Direction::createLeft());
				}
			}
			else if ( keyCode == UIComponents::getInstance() -> getKey(UIComponents::UP ))
			{
				if (e.isPress())
				{
					pPlayer->getState()->onVeticalDirectionPressed(Direction::createUp());
				}
				else
				{
					pPlayer->getState()->onVeticalDirectionReleased();
				}
			}
			else if( keyCode == UIComponents::getInstance() -> getKey(UIComponents::DOWN ))
			{
				if (e.isPress())
				{
					pPlayer->getState()->onVeticalDirectionPressed(Direction::createDown());
				}
				else
				{
					pPlayer->getState()->onVeticalDirectionReleased();
				}
			}
			else if( keyCode == UIComponents::getInstance() -> getKey(UIComponents::JUMP ))
			{
				if (e.isPress())
				{
					pPlayer->getState()->onJumpPressed();
				}
				else
				{
					pPlayer->getState()->onJumpRelease();
				}
			}
			else if( keyCode == UIComponents::getInstance() -> getKey(UIComponents::FIRE ))
			{
				if (e.isPress())
				{
					pPlayer->getState()->onFirePressed();
				}
			}		
        }
    }

	KeyBoard::getInstace() ->flush();

}
void PlayScene::onUpdate()
{
	if( isGameOver )
	{
		count++;
		if( count == nTransitionFrames)
		{
			SceneManager::getInstance()->createScene(new GameOverScene());
			return;
		}
	}
	else if( isFinish )
	{
		count++;
		if( count == nTransitionFrames)
		{
			if( UIComponents::getInstance() ->getCurrentStage() < 5 )
			{
				UIComponents::getInstance() ->setStage( UIComponents::getInstance() ->getCurrentStage() + 2 );
				SceneManager::getInstance()->createScene(new LoadingScene());
			}
			else
			{
				SceneManager::getInstance()->createScene(new EndingScene());
			}
			return;
		}
	}

	handleInput();

	if( !isPause )
	{
		update();
		onCollision();
		isFinish = pMap -> isFinish();
		if(UIComponents::getInstance() ->getLifes() <= 0)
		{
			isGameOver = true;
		}
	}

	
}
void PlayScene::render()
{
	if(isEffectOn)
	{
		 Graphics::getInstance()->beginRender();
    
		 D3DXHANDLE m_hWorldViewProj  = shader -> getEffect() ->GetParameterByName(NULL, "WVPMatrix"); 
		 D3DXHANDLE lightingPosition = shader -> getEffect() ->GetParameterByName(NULL, "lightingPosition"); 
		 D3DXHANDLE lightingColor = shader -> getEffect() ->GetParameterByName(NULL, "lightingColor"); 
		 D3DXHANDLE lightingCutoff = shader -> getEffect() ->GetParameterByName(NULL, "lightingCutoff");  
		 D3DXHANDLE lightingDirection = shader -> getEffect() ->GetParameterByName(NULL, "lightingDirection");
		 D3DXHANDLE AmbientlightIntensity = shader -> getEffect() ->GetParameterByName(NULL, "AmbientlightIntensity");

		 D3DXHANDLE technique;

		 unsigned int Passes  = 0;

		 technique = shader -> getEffect() -> GetTechniqueByName("technique0");
		 shader -> getEffect() -> SetTechnique(technique);
		 shader -> getEffect() -> Begin(&Passes, 0 );

		 for(int i=0; i < Passes; ++i)
		 {
			 Graphics::getInstance() ->getSpriteHandler() -> Begin(D3DXSPRITE_ALPHABLEND	);
			 shader -> getEffect() -> BeginPass(i);
			 D3DXMATRIX mtxViewProj;
			 D3DXMatrixOrthoOffCenterLH(&mtxViewProj, 0.5f, 256 + 0.5f,
				 256 + 0.5f, 0.5f, 0.0f, 1.0f);
			 shader -> getEffect() -> SetMatrix(m_hWorldViewProj, &(mtxViewProj));
			 shader -> getEffect() -> SetVector(lightingPosition, &light->getPosition());
			 shader -> getEffect() -> SetVector(lightingColor,&light -> getColor());
			 shader -> getEffect() -> SetFloat(lightingCutoff, light->getCutOff());
			 shader -> getEffect() -> SetFloat(AmbientlightIntensity, light -> getAmbientLightIntensity());
			 shader -> getEffect() -> SetVector(lightingDirection,&light -> getDirection());
			 shader -> getEffect() -> CommitChanges();


			 pMap->draw(cam);
			 pPlayer->draw(cam);

			 Graphics::getInstance() ->getSpriteHandler() -> End();
			 shader -> getEffect() -> EndPass();
		 }

		 shader -> getEffect() -> End();

		 Graphics::getInstance() ->getSpriteHandler() -> End();

		 Graphics::getInstance() ->getSpriteHandler() -> Begin(D3DXSPRITE_ALPHABLEND	);
		 int lifes = min (UIComponents::getInstance() ->getLifes() , 5);
		 int x = 0;
		 int y = 0;
		 int offset = 16;
		 for (int i = 0; i < lifes - 1 ; i++)
		 {
			 lifeTexture ->draw(x, y);
			 x += offset;
		 }
		 Graphics::getInstance() ->getSpriteHandler() -> End();

		 Graphics::getInstance()->endRender();
	}
	else
	{
		Graphics::getInstance()->beginRender();
		Graphics::getInstance() ->getSpriteHandler() -> Begin(D3DXSPRITE_ALPHABLEND	);

		pMap->draw(cam);
		pPlayer->draw(cam);
		int lifes = min (UIComponents::getInstance() ->getLifes() , 5);
			int x = 0;
			int y = 0;
			int offset = 16;
			for (int i = 0; i < lifes - 1 ; i++)
			{
				lifeTexture ->draw(x, y);
				x += offset;
			}

		Graphics::getInstance() ->getSpriteHandler() -> End();
		Graphics::getInstance()->endRender();
	}
   
}

void PlayScene::  update()
{
	pMap->onUpdate(pPlayer, cam);
    pMap->onSupportSprite(pPlayer);
    pPlayer->update();
	cam ->update( pPlayer->getX(), pPlayer->getY() );
	pPlayer -> setCameraRect (cam ->getRect());
	if(isEffectOn)
	{
		light -> update();
		// Lighting update

		float resultX = pPlayer -> getCenterX() - cam -> getX() + cam -> getViewport() -> getPort().x;
		float resultY = pPlayer -> getCenterY() - cam -> getY() + cam -> getViewport() -> getPort().y;
		resultX = ( resultX - 128 ) / 128;
		resultY = ( 128 - resultY ) / 128;
		light -> setPosition(resultX, resultY);
	}
	
}