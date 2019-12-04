#pragma once
#include "Vector2.h"
class GameObject
{
protected:
	Vector2 pos;
public:

	virtual void Init() = 0;
	virtual void Draw() = 0;
	virtual void Update() = 0;
	Vector2 GetPos();
	void SetPos(float x, float y);
	bool IsOutOfBounds();

};

