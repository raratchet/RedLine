#include "GenericEnemy1.h"
#include "Game.h"

GenericEnemy1::GenericEnemy1(Platform* platform)
{
	active = true;
	this->platform = platform;
	ableToShoot = true;
}

void GenericEnemy1::LoadImage(std::string name, int x, int y)
{
	pos.SetX(x);
	pos.SetY(y);
	image = new Sprite(platform, name, x, y, 44, 39, 1, 3);
	ableToShoot = true;
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
	if (activePlayerBullets != nullptr)
	{
		for (auto bullet : *activePlayerBullets)
		{
			Vector2 p = bullet->GetPos();
			if(BoxCollision(pos.GetX(),pos.GetY(),w,h, p.GetX(), p.GetY(), bullet->GetH(), bullet->GetW()) &&
			   bullet->GetActive())
			{
				active = false;
				bullet->SetActive(false);
				RedLine::Game::AddScore(100);
			}
		}
	}

	if (pos.GetY() >= 550) ableToShoot = false;
}

void GenericEnemy1::MoveEnemy()
{
	image->setY(pos.GetY()+0.8);
	image->setX(sin(pos.GetY() * 0.1) * 180 + 205);
	pos.SetX(image->getX());
	pos.SetY(image->getY());
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

void GenericEnemy1:: UpdatePlayerPos(Vector2 pos)
{
	playerPos = pos;
}


void GenericEnemy1::Shoot()
{
	if (lastTime + timeBetweenShoots * 1000 < platform->GetTime() && ableToShoot)
	{
		EnemyBullet* bullet = new EnemyBullet(platform, pos, playerPos);
		bullet->LoadImage("Assets/bulletE.png", pos.GetX(), pos.GetY());
		bullet->SetActive(true);
		bullet->SetVelocity(5);
		activeEnemyBullets->push_back(bullet);
		lastTime = platform->GetTime();
	}
}