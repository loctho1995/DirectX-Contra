#pragma once

//#define char dir

class Direction
{
public:
	bool isRight()
	{
		return dir & Right;
	}
	bool isLeft()
	{
		return dir & Left;
	}
	bool isUp()
	{
		return dir & Up;
	}
	bool isDown()
	{
		return dir & Down;
	}
	bool isNone()
	{
		return dir & None;
	}

	void reverse()
	{
		if(dir == Right)
			dir = Left;
		else dir = Right;
	}
	
	Direction& operator = (const Direction& d2)
	{
			this -> dir = d2.dir;
					return *this;
	}

	static Direction createLeft()
	{
		Direction d;
		d.dir = Left;
		return d;
	
	}
	static Direction createRight()
	{
		Direction d;
		d.dir = Right;
		return d;
	}
	static Direction createUp()
	{
		Direction d;
		d.dir = Up;
		return d;
	}
	static Direction  createDown()
	{
		Direction d;
		d.dir = Down;
		return d;
	}
	static Direction  createNone()
	{
		Direction d;
		d.dir = None;
		return d;
	}

private:
	enum DIR
	{
		Left = 0x001,
		Right  = 0x002,
		Up = 0x004,
		Down = 0x008,
		None = 0x0010
	};
	DIR dir;
};