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
	active = true;
	this->platform = platform;
}

void GenericEnemy1::LoadImage(std::string name, int x, int y)
{
	this->x = x;
	this->y = y;
	image = new Sprite(platform, name, x, y, 44, 39, 1, 3);
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
	image->Draw();

}
void GenericEnemy1::Update()
{
	int w = image->getW();
	int h = image->getH();
	MoveEnemy();
	if (activeBullets != nullptr)
	{
		for (auto bullet : *activeBullets)
		{
			//x > bullet->GetX() && x + w < bullet->GetX() &&
			if ( y>bullet->GetY() &&   bullet->GetY()< y + h)
			{
				active = false;
				bullet->SetActive(false);
			}
		}
	}
}

void GenericEnemy1::MoveEnemy()
{
	//image->setY(y);
	//image->setX(sin(y * 0.1) * 140 + x);
	y += 1;
}
