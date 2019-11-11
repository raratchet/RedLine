#include "GenericEnemy1.h"

int GenericEnemy1::GetX()
{
	return x;
}

int GenericEnemy1::GetY()
{
	return y;
}

void GenericEnemy1::SetX(int x)
{
	this->x = x;
}

void GenericEnemy1::SetY(int y)
{
	this->y = y;
}

GenericEnemy1::GenericEnemy1(Platform* platform)
{
	this->platform = platform;
}

void GenericEnemy1::LoadImage(std::string name, int x, int y)
{
	this->x = x;
	this->y = y;
	image = new Image();
	image->LoadImage(name);
}

void GenericEnemy1::SetActiveBullets(std::list<Bullet*>* activeBullets)
{
	this->activeBullets = activeBullets;
}

void GenericEnemy1::Init()
{
}
void GenericEnemy1::Draw()
{
	platform->RenderImage(image, x, y, 0);

}
void GenericEnemy1::Update()
{

}
