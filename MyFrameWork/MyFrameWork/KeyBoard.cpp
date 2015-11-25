#include "KeyBoard.h"



KeyEvent :: KeyEvent(KeyEvent::EventType type , unsigned char keycode)
	:
	type(type),
	keyCode(keycode)
{
}


unsigned char KeyEvent:: getCode()
{
	return keyCode;
}

bool KeyEvent :: isPress()
{
	return type == Press;
}

bool KeyEvent :: isRelease()
{
	return type == Release;
}



KeyBoard* KeyBoard::sInstance = nullptr;

KeyBoard :: KeyBoard()
{
	for (int i = 0; i < 256; i++)
	{
		keyState[i] = false;
	}
}

KeyBoard* KeyBoard :: getInstace()
{
	if(sInstance == nullptr)
		sInstance = new KeyBoard();
	return sInstance;
}
void KeyBoard:: onKeyPressed(unsigned char keycode)
{
	if( !keyState[keycode] )
	{
		keyState[keycode] = true;
		keyBuffer.push(KeyEvent(KeyEvent::Press, keycode));
	}
	
}

void KeyBoard :: onKeyReleased( unsigned char keycode)
{
	if( keyState[keycode] )
	{
		keyState[keycode] = false;
		keyBuffer.push(KeyEvent(KeyEvent::Release, keycode));
	}
	
}

KeyEvent KeyBoard :: peekKey()
{
	if(keyBuffer.size() > 0)
	{
		return keyBuffer.front();
	}
	else
	{
		return KeyEvent(KeyEvent::NULLKey, 0);
	}
}

KeyEvent KeyBoard :: readKey()
{
    if(keyBuffer.size() > 0)
	{
		KeyEvent e = keyBuffer.front();
		keyBuffer.pop();
		return e;
	}
	else
	{
		return KeyEvent(KeyEvent::NULLKey, 0);
	}
}


bool KeyBoard :: isPress(unsigned char keyCode)
{
	return keyState[keyCode] == true;
}

void KeyBoard :: flush()
{
	while(!keyBuffer.empty())
	{
		keyBuffer.pop();
	}
}

bool KeyBoard :: isEmpty()
{
	return keyBuffer.empty();
}

