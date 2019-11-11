#include "Bullet.h"

Bullet::Bullet(Platform* platform)
{
	this->platform = platform;
}
int Bullet::GetX() 
{
	return x;
}
int Bullet::GetY() 
{
	return y;
}
void Bullet::SetX(int x) 
{
	this->x = x;
}
void Bullet::SetY(int y) 
{
	this->y = y;
}
void Bullet::SetVelocity(int vel)
{
	this->velocity = vel;
}
void Bullet::LoadImage(std::string name, int x, int y)
{
	this->x = x;
	this->y = y;
	image = new Image();
	image->LoadImage(name);
}
void Bullet::Init()
{
	y = y - 3;
}
void Bullet::Draw()
{
	platform->RenderImage(image, x, y, 0);

}
void Bullet::Update()
{
	y -= velocity;
}
