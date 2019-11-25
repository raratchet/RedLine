#include "GenericEnemy2.h"

float GenericEnemy2::GetX()
{
	return x;
}

float GenericEnemy2::GetY()
{
	return y;
}

void GenericEnemy2::SetX(float x)
{
	this->x = x;
}

void GenericEnemy2::SetY(float y)
{
	this->y = y;
}

GenericEnemy2::GenericEnemy2(Platform* platform)
{
	active = true;
	this->platform = platform;
	if (rand() % 100 > 50)	direction = -1;
	else direction = 1;
}

void GenericEnemy2::LoadImage(std::string name, int x, int y)
{
	this->x = x;
	this->y = y;
	image = new Sprite(platform, name, x, y, 44, 39, 1, 3);
}

void GenericEnemy2::SetActiveBullets(std::list<Bullet*>* activeBullets)
{
	this->activeBullets = activeBullets;
}

void GenericEnemy2::Init()
{
}
void GenericEnemy2::Draw()
{
	if (active)
	{
		image->Draw();
	}
}
void GenericEnemy2::Update()
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

void GenericEnemy2::MoveEnemy()
{
	image->setY(y+0.8);
	if (image->getY() > 250) 
	{
		image->setY(y + 1.5);
		image->setX(x + 1.5 *direction);
	}
	x = image->getX();
	y = image->getY();
}

bool GenericEnemy2::BoxCollision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
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
bool GenericEnemy2::CircleCollision(float r1, float r2, int x1, int y1, int x2, int y2)
{
	float d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	if (d >= r1 + r2)
		return false;
	else
		return true;
}