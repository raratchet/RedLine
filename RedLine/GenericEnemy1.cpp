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
	if (active)
	{
		image->Draw();
	}
}
void GenericEnemy1::Update()
{
	if (!active)
		return;
	int w = image->getW();
	int h = image->getH();
	MoveEnemy();
	if (activeBullets != nullptr)
	{
		for (auto bullet : *activeBullets)
		{
			Vector2 p = bullet->GetPos();
			//if (CircleCollision(5, 5, p.GetX(), p.GetY(), x, y))
			if(BoxCollision(x,y,w,h, p.GetX(), p.GetY(), bullet->GetH(), bullet->GetW()) &&
				bullet->GetActive())
			{
				active = false;
				bullet->SetActive(false);
			}
		}
	}
}

void GenericEnemy1::MoveEnemy()
{
	image->setY(y+1);
	image->setX(sin(y * 0.1) * 10+ x);
	x = image->getX();
	y = image->getY();
}

bool GenericEnemy1::BoxCollision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
{
	if ((x2 > x1&& x2 < x1 + w1) || (x2 + w2 > x1&& x2 + w2 < x1 + w1))
	{
		if ((y2 > y1&& y2 < y1 + h1) || (y2 + h2 > y1&& y2 + h2 < y1 + h1))
		{
			return true;
		}
	}
	return false;

}
bool GenericEnemy1::CircleCollision(float r1, float r2, int x1, int y1, int x2, int y2)
{
	float d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	if (d >= r1 + r2)
		return false;
	else
		return true;
}