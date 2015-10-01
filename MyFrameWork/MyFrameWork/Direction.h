#pragma once

//#define char dir

class Direction
{
public:
	bool isRight()
	{
		return dir == Right;
	}
	bool isLeft()
	{
		return dir == Left;
	}
	bool isUp()
	{
		return dir == Up;
	}
	bool isDown()
	{
		return dir == Down;
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
		Left ,
		Right  ,
		Up ,
		Down,
		None
	};
	DIR dir;
};