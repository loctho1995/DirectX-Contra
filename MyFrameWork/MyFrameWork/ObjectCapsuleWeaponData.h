#pragma once
#include "ObjectData.h"
#include "Define.h"

class ObjectCapsuleWeaponData : public ObjectData
{
public:
	ObjectCapsuleWeaponData();
	~ObjectCapsuleWeaponData();

	enum ObjectCapsuleWeaponArrayIndex
	{
		FLY,
		DROP,
		COUNT
	};

	BulletTypes bulletType;
};

