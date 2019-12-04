#include "GameObject.h"

Vector2 GameObject::GetPos()
{
	return pos;
}
void GameObject::SetPos(float x, float y)
{
	pos = Vector2(x,y);
}

bool GameObject::IsOutOfBounds() {

	if (pos.GetX() > 1000 || pos.GetY() > 1000 )
	{
		return true;
	}

	if (pos.GetX() < -100 || pos.GetY() < -100)
	{
		return true;
	}

	return false;
}