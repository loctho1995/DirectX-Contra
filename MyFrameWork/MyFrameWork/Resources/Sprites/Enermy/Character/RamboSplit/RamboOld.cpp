#include "Rambo.h"

Rambo::Rambo()
{

}

Rambo::Rambo(D3DXVECTOR3 _position, eDirection _direction, eObjectID _objectID)
	: DynamicObject(_position, _direction, _objectID)
{
	//m_Physic = new Physic();
	//m_Physic->setPosition(_position);
	m_Position = _position;
	m_ObjectState = eObjectState::STATE_RAMBO_JUMP;
	m_Sprite = new CSpriteDx9(*SpriteManager::getInstance()->getSprite(eSpriteID::SPRITE_RAMBO_IDLE));
	//m_Physic->setPosition(D3DXVECTOR3(m_Position.x, m_Position.y, 1.0f));
	m_Position.z = 1.0f;
	//this->m_Physic->setAccelerate(D3DXVECTOR2(0.0f, -0.1f));
}

void Rambo::Initialize()
{

}

void Rambo::HandleInput()
{

	switch (m_ObjectState)
	{
		case STATE_ALIVE_IDLE:
			break;
		case STATE_DEATH:
			break;
		case eObjectState::STATE_RAMBO_RUN:
			{
				if(!CInputDx9::getInstance()->IsKeyDown(DIK_RIGHT) && !CInputDx9::getInstance()->IsKeyDown(DIK_LEFT))
				{
					m_ObjectState = eObjectState::STATE_RAMBO_IDLE;
					TURN_ON_UPDATE_SPRITE(m_UpdateFlag);
					m_Physic->setVelocity(D3DXVECTOR2(0, 0));
					break;
				}
				if(CInputDx9::getInstance()->IsKeyDown(DIK_RIGHT))
				{
					m_Direction = eDirection::RIGHT;
					break;
				}
				if(CInputDx9::getInstance()->IsKeyDown(DIK_LEFT))
				{
					m_Direction = eDirection::LEFT;
					break;
				}
				if(CInputDx9::getInstance()->IsKeyDown(DIK_Z))
				{
					m_ObjectState = eObjectState::STATE_RAMBO_SHOOT;
					TURN_ON_UPDATE_SPRITE(m_UpdateFlag);
				}
				/*if(CInputDx9::getInstance()->IsKeyPress(DIK_X))
				{
					m_ObjectState = eObjectState::STATE_RAMBO_JUMP;
					m_Physic->setVelocity(D3DXVECTOR2(m_Physic->getVelocity().x, 0.5f));
					TURN_ON_UPDATE_SPRITE(m_UpdateFlag);
				}*/
				if(CInputDx9::getInstance()->IsKeyPress(DIK_X))
				{
					m_ObjectState = eObjectState::STATE_RAMBO_JUMP;
					//m_Physic->setVelocity(D3DXVECTOR2(m_Physic->getVelocity().x, 5.0f));
					m_Physic->setAccelerate(D3DXVECTOR2(m_Physic->getAccelerate().x, 1.3f));
					TURN_ON_UPDATE_SPRITE(m_UpdateFlag);
					break;
				}
			}
			break;
		case STATE_RAMBO_SHOOT_RUN:
			{
				if(!CInputDx9::getInstance()->IsKeyDown(DIK_RIGHT) && !CInputDx9::getInstance()->IsKeyDown(DIK_LEFT))
				{
					m_ObjectState = eObjectState::STATE_RAMBO_IDLE;
					TURN_ON_UPDATE_SPRITE(m_UpdateFlag);
					m_Physic->setVelocity(D3DXVECTOR2(0, 0));
				}
				if(CInputDx9::getInstance()->IsKeyDown(DIK_LEFT))
				{
					m_Direction = eDirection::LEFT;
				}
				if(CInputDx9::getInstance()->IsKeyDown(DIK_RIGHT))
				{
					m_Direction = eDirection::RIGHT;
				}
				if(!CInputDx9::getInstance()->IsKeyDown(DIK_Z))
				{
					m_ObjectState = eObjectState::STATE_RAMBO_RUN;
					TURN_ON_UPDATE_SPRITE(m_UpdateFlag);
				}
			}
			break;
		case STATE_RAMBO_SHOOT_UP:
			{
				if(!CInputDx9::getInstance()->IsKeyDown(DIK_UP))
				{
					m_ObjectState = eObjectState::STATE_RAMBO_IDLE;
					TURN_ON_UPDATE_SPRITE(m_UpdateFlag);
				}
			}
			break;
		case STATE_RAMBO_SHOOT_TOP_RIGHT:
			break;
		case STATE_RAMBO_SHOOT_BOTTOM_RIGHT:
			break;
		case STATE_RAMBO_IDLE:
			{
				if(CInputDx9::getInstance()->IsKeyDown(DIK_RIGHT))
				{
					m_ObjectState = eObjectState::STATE_RAMBO_RUN;
					m_Direction = eDirection::RIGHT;
					TURN_ON_UPDATE_SPRITE(m_UpdateFlag);
					break;
				}
				if(CInputDx9::getInstance()->IsKeyDown(DIK_LEFT))
				{
					m_ObjectState = eObjectState::STATE_RAMBO_RUN;
					m_Direction = eDirection::LEFT;
					TURN_ON_UPDATE_SPRITE(m_UpdateFlag);
					break;
				}
				if(CInputDx9::getInstance()->IsKeyDown(DIK_Z))
				{
					m_ObjectState = eObjectState::STATE_RAMBO_SHOOT;
					break;
				}
				if(CInputDx9::getInstance()->IsKeyPress(DIK_X))
				{
					m_ObjectState = eObjectState::STATE_RAMBO_JUMP;
					//m_Physic->setVelocity(D3DXVECTOR2(m_Physic->getVelocity().x, 5.0f));
					m_Physic->setAccelerate(D3DXVECTOR2(m_Physic->getAccelerate().x, 1.3f));
					TURN_ON_UPDATE_SPRITE(m_UpdateFlag);
					break;
				}
				if(CInputDx9::getInstance()->IsKeyDown(DIK_UP))
				{
					m_ObjectState = eObjectState::STATE_RAMBO_SHOOT_UP;
					TURN_ON_UPDATE_SPRITE(m_UpdateFlag);
					break;
				}
				if(CInputDx9::getInstance()->IsKeyDown(DIK_DOWN))
				{
					m_ObjectState = eObjectState::STATE_RAMBO_LIE;
					TURN_ON_UPDATE_SPRITE(m_UpdateFlag);
					break;
				}
			}
			break;
		case STATE_RAMBO_JUMP:
			{
				if(CInputDx9::getInstance()->IsKeyDown(DIK_LEFT))
				{
					m_Direction = eDirection::LEFT;
				}
				if(CInputDx9::getInstance()->IsKeyDown(DIK_RIGHT))
				{
					m_Direction = eDirection::RIGHT;
				}
			}
			break;
		case STATE_RAMBO_LIE:
			{
				if(!CInputDx9::getInstance()->IsKeyDown(DIK_DOWN))
				{
					m_ObjectState = eObjectState::STATE_RAMBO_IDLE;
					TURN_ON_UPDATE_SPRITE(m_UpdateFlag);
				}
			}
			break;
		case STATE_RAMBO_SHOOT:
			{
				if(!CInputDx9::getInstance()->IsKeyDown(DIK_Z))
				{
					m_ObjectState = eObjectState::STATE_RAMBO_IDLE;
				}
				if(CInputDx9::getInstance()->IsKeyDown(DIK_LEFT))
				{
					m_Direction = eDirection::LEFT;
					m_ObjectState = eObjectState::STATE_RAMBO_SHOOT_RUN;
					TURN_ON_UPDATE_SPRITE(m_UpdateFlag);
				}
				if(CInputDx9::getInstance()->IsKeyDown(DIK_RIGHT))
				{
					m_Direction = eDirection::RIGHT;
					m_ObjectState = eObjectState::STATE_RAMBO_SHOOT_RUN;
					TURN_ON_UPDATE_SPRITE(m_UpdateFlag);
				}
			}
			break;
		default:
			break;
	}
}

void Rambo::UpdateAnimation()
{
	switch (m_ObjectState)
	{
		case STATE_ALIVE_IDLE:
			break;
		case STATE_DEATH:
			break;
		case STATE_RAMBO_RUN:
		{
			if (IS_UPDATE_SPRITE(m_UpdateFlag))
			{
				delete m_Sprite;
				m_Sprite = new CSpriteDx9(*SpriteManager::getInstance()->getSprite(eSpriteID::SPRITE_RAMBO_RUN));
				TURN_OFF_UPDATE_SPRITE(m_UpdateFlag);
				break;
			}
			m_Sprite->UpdateAnimation(200);
		}
			break;
		case STATE_RAMBO_SHOOT_RUN:
			{
				if (IS_UPDATE_SPRITE(m_UpdateFlag))
				{
					delete m_Sprite;
					m_Sprite = new CSpriteDx9(*SpriteManager::getInstance()->getSprite(eSpriteID::SPRITE_RAMBO_SHOOT_RUN));
					TURN_OFF_UPDATE_SPRITE(m_UpdateFlag);
				}
				m_Sprite->UpdateAnimation(200);
			}
			break;
		case STATE_RAMBO_SHOOT_TOP_RIGHT:
			break;
		case STATE_RAMBO_SHOOT_BOTTOM_RIGHT:
			break;
		case STATE_RAMBO_IDLE:
			{
				if (IS_UPDATE_SPRITE(m_UpdateFlag))
				{
					delete m_Sprite;
					m_Sprite = new CSpriteDx9(*SpriteManager::getInstance()->getSprite(eSpriteID::SPRITE_RAMBO_IDLE));
					TURN_OFF_UPDATE_SPRITE(m_UpdateFlag);
				}
			}
			break;
		case STATE_RAMBO_JUMP:
			{
				if (IS_UPDATE_SPRITE(m_UpdateFlag))
				{
					delete m_Sprite;
					m_Sprite = new CSpriteDx9(*SpriteManager::getInstance()->getSprite(eSpriteID::SPRITE_RAMBO_JUMP));
					TURN_OFF_UPDATE_SPRITE(m_UpdateFlag);
				}
				m_Sprite->UpdateAnimation(100);
			}
			break;
		case STATE_RAMBO_LIE:
			{
				if (IS_UPDATE_SPRITE(m_UpdateFlag))
				{
					delete m_Sprite;
					m_Sprite = new CSpriteDx9(*SpriteManager::getInstance()->getSprite(eSpriteID::SPRITE_RAMBO_LIE));
					TURN_OFF_UPDATE_SPRITE(m_UpdateFlag);
				}
			}
			break;
		case STATE_RAMBO_SHOOT:
			{
				if (IS_UPDATE_SPRITE(m_UpdateFlag))
				{
					delete m_Sprite;
					m_Sprite = new CSpriteDx9(*SpriteManager::getInstance()->getSprite(eSpriteID::SPRITE_RAMBO_IDLE));
					TURN_OFF_UPDATE_SPRITE(m_UpdateFlag);
				}
				m_Sprite->UpdateAnimation(100);
			}
			break;
		case STATE_RAMBO_SHOOT_UP:
			{
				if(IS_UPDATE_SPRITE(m_UpdateFlag))
				{
					delete m_Sprite;
					m_Sprite = new CSpriteDx9(*SpriteManager::getInstance()->getSprite(eSpriteID::SPRITE_RAMBO_SHOOT_UP));
					TURN_OFF_UPDATE_SPRITE(m_UpdateFlag);
				}
				if(CInputDx9::getInstance()->IsKeyDown(DIK_Z))
				{
					m_Sprite->UpdateAnimation(100);
				}
			}
			break;
		default:
			break;
	}
}

void Rambo::UpdateCollision(Object* checkingObject)
{
	IDDirection collideDirection = this->m_Collision->CheckCollision(this, checkingObject);

	if(collideDirection != IDDirection::DIR_NONE)
	{
		switch(checkingObject->getTypeObject())
		{
		case ETypeObject::VIRTUAL_OBJECT:
			if(collideDirection == IDDirection::DIR_TOP)
			{
				collideDirection = IDDirection::DIR_TOP;
				//this->m_Position.x += this->m_Collision->m_MoveX;
				this->m_Position.y += this->m_Collision->m_MoveY;
				this->m_Physic->setVelocity(D3DXVECTOR2(this->m_Physic->getVelocity().x, 0));
				if(this->m_ObjectState == eObjectState::STATE_RAMBO_JUMP)
				{
					//this->m_Position.y += this->m_Collision->m_MoveY;
					this->m_ObjectState = eObjectState::STATE_RAMBO_IDLE;
					this->m_Physic->setVelocity(D3DXVECTOR2(this->m_Physic->getVelocity().x, 0));
					TURN_ON_UPDATE_SPRITE(m_UpdateFlag);
					OutputDebugString("AAA");
				}
				break;
			}
			else if(collideDirection == IDDirection::DIR_BOTTOM)
			{
				//collideDirection = IDDirection::DIR_BOTTOM;
				break;
			}

			else if(collideDirection == IDDirection::DIR_LEFT)
			{
				//collideDirection = IDDirection::DIR_LEFT;
				break;
			}

			else if(collideDirection == IDDirection::DIR_RIGHT)
			{
				//collideDirection = IDDirection::DIR_RIGHT;
				break;
			}

			break;
		}
	}
}

void Rambo::UpdateMovement()
{
	//this->m_Physic->setAccelerate(D3DXVECTOR2(0.0f, -0.1f));
	if(this->m_Physic->getAccelerate().y > -9.8f)
	{
		D3DXVECTOR2 tempAccel = m_Physic->getAccelerate();
		this->m_Physic->setAccelerate(D3DXVECTOR2(tempAccel.x, tempAccel.y - 9.8f));
	}
	else
	{
		D3DXVECTOR2 tempAccel = m_Physic->getAccelerate();
		this->m_Physic->setAccelerate(D3DXVECTOR2(tempAccel.x, -9.8f));
	}
	
	switch (m_ObjectState)
	{
		case STATE_ALIVE_IDLE:
			break;
		case STATE_DEATH:
			break;
		case STATE_RAMBO_RUN:
			{
				if(CInputDx9::getInstance()->IsKeyDown(DIK_RIGHT))
				{
					m_Physic->setVelocity(D3DXVECTOR2(10.0f, m_Physic->getVelocity().y));
					break;
				}
				if(CInputDx9::getInstance()->IsKeyDown(DIK_LEFT))
				{
					m_Physic->setVelocity(D3DXVECTOR2(10.0f, m_Physic->getVelocity().y));
					break;
				}
			}
			break;
		case STATE_RAMBO_SHOOT_RUN:
			{
				if(CInputDx9::getInstance()->IsKeyDown(DIK_RIGHT))
				{
					m_Physic->setVelocity(D3DXVECTOR2(1.5f, m_Physic->getVelocity().y));
					break;
				}
				if(CInputDx9::getInstance()->IsKeyDown(DIK_LEFT))
				{
					m_Physic->setVelocity(D3DXVECTOR2(-1.5f, m_Physic->getVelocity().y));
					break;
				}
			}
			break;
		case STATE_RAMBO_SHOOT_TOP_RIGHT:
			break;
		case STATE_RAMBO_SHOOT_BOTTOM_RIGHT:
			break;
		case STATE_RAMBO_IDLE:
			break;
		case STATE_RAMBO_JUMP:
			{
				//if(m_Position.y < 100)
				//{
				//	//m_Physic->setPosition(D3DXVECTOR3(m_Physic->getPositionVec3().x, 100, m_Physic->getPositionVec3().z));
				//	m_Position.y = 100;
				//	m_Physic->setVelocity(D3DXVECTOR2(m_Physic->getVelocity().x, 0.0f));
				//	TURN_ON_UPDATE_SPRITE(m_UpdateFlag);
				//	m_ObjectState = eObjectState::STATE_RAMBO_IDLE;
				//	m_Physic->setVelocity(D3DXVECTOR2(0, 0));
				//	return;
				//}
				if(CInputDx9::getInstance()->IsKeyDown(DIK_RIGHT))
				{
					m_Physic->setVelocity(D3DXVECTOR2(1.5f, m_Physic->getVelocity().y));
				}
				if(CInputDx9::getInstance()->IsKeyDown(DIK_LEFT))
				{
					m_Physic->setVelocity(D3DXVECTOR2(-1.5f, m_Physic->getVelocity().y));
				}
				//m_Physic->setVelocity(D3DXVECTOR2(m_Physic->getVelocity().x, m_Physic->getVelocity().y - 0.1f));
			}
			break;
		case STATE_RAMBO_LIE:
			break;
		case STATE_RAMBO_SHOOT:
			{

			}
			break;
		default:
			break;
	}
	this->m_Physic->UpdateMovement(&m_Position);
	CGlobal::Rambo_X = (int)(getPositionVec2().x);
	CGlobal::Rambo_Y = (int)(getPositionVec2().y);
	char fps[100];
	sprintf(fps, "%f %f\n", getPositionVec2().x, getPositionVec2().y);
	OutputDebugString(fps);
}
void Rambo::Update()
{

}

void Rambo::Render(SPRITEHANDLE spriteHandle)
{
	if (m_Direction == eDirection::RIGHT)
	{
		m_Sprite->Render(spriteHandle,
			getPositionVec2(),
			ESpriteEffect::None, m_Sprite->getRotate(),
			m_Sprite->getScale(),
			m_Position.z);
		return;
	}
	if (m_Direction == eDirection::LEFT)
	{
		m_Sprite->Render(spriteHandle,
			getPositionVec2(),
			ESpriteEffect::Horizontally,
			m_Sprite->getRotate(), m_Sprite->getScale(),
			m_Position.z);
		return;
	}
}

void Rambo::Release()
{

}

Rambo::~Rambo()
{

}