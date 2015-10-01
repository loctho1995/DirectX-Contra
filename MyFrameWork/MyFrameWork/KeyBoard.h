#pragma once

#include <queue>

class KeyEvent
{
public:
	enum EventType
	{
		Press,
		Release,
		NULLKey
	};
	KeyEvent(EventType type, unsigned char keycode);
	unsigned char getCode();
	bool isPress();
	bool isRelease();
private:
	EventType type;
	unsigned char keyCode;
};
class KeyBoard
{
public:
	static KeyBoard* getInstace();

	void onKeyPressed( unsigned char keycode );
	void onKeyReleased( unsigned char keycode );
	KeyEvent peekKey();
	KeyEvent readKey();
	bool isPress(unsigned char keyCode);
	void flush();
	bool isEmpty();
private:
	KeyBoard();
	bool keyState[256];
	std::queue < KeyEvent > keyBuffer;
	static KeyBoard* sInstance;
	
};
