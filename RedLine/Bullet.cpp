#include "Bullet.h"

Bullet::Bullet(Platform* platform)
{
	this->platform = platform;
}
void Bullet::SetPos(float x, float y)
{
	pos.SetX(x);
	pos.SetY(y);
}
Vector2 Bullet::GetPos() 
{
	return pos;
}

int Bullet::GetH()
{
	return image->GetHeight();
}
int Bullet::GetW()
{
	return image->GetWidth();
}
bool Bullet::GetActive()
{
	return active;
}
void Bullet::SetActive(bool active) 
{
	this->active = active;
}

void Bullet::SetVelocity(int vel)
{
	this->velocity = vel;
}
void Bullet::LoadImage(std::string name, int x, int y)
{
	pos.SetX(x);
	pos.SetY(y);
	image = new Image();
	image->LoadImage(name);
}
void Bullet::Init()
{
	pos.SetY(pos.GetY() - 3);
}
void Bullet::Draw()
{
	if (active) 
	{
		platform->RenderImage(image, pos.GetX(), pos.GetY(), 0);
	}
	
}
void Bullet::Update()
{
	pos.SetY(pos.GetY() - velocity);
}

bool Bullet::isActive()
{
	return active;
}


