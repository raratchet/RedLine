#include "GenericEnemy2.h"
#include "Game.h"

GenericEnemy2::GenericEnemy2(Platform* platform)
{
	active = true;
	this->platform = platform;
	if (rand() % 100 > 50)	direction = -1;
	else direction = 1;
	ableToShoot = true;
	timeBetweenShoots = 1;
}

void GenericEnemy2::LoadImage(std::string name, int x, int y)
{
	this->pos.SetX(x);
	this->pos.SetY(y);
	image = new Sprite(platform, name, x, y, 44, 39, 1, 3);
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

	if (pos.GetY() >= 250) ableToShoot = false;
}

void GenericEnemy2::UpdatePlayerPos(Vector2 pos) 
{

}

void GenericEnemy2::Shoot()
{
	if (lastTime + timeBetweenShoots * 1000 < platform->GetTime() && ableToShoot)
	{
		EnemyBullet* bullet = new EnemyBullet(platform, pos, Vector2(0,0));
		bullet->LoadImage("Assets/bulletE.png", pos.GetX(), pos.GetY());
		bullet->SetActive(true);
		bullet->SetVelocity(5);
		activeEnemyBullets->push_back(bullet);
		lastTime = platform->GetTime();
	}
}

void GenericEnemy2::MoveEnemy()
{
	image->setY(pos.GetY()+0.8);
	if (image->getY() > 250) 
	{
		image->setY(pos.GetY() + 2.5);
		image->setX(pos.GetX() + 1.5 *direction);
	}
	pos.SetX(image->getX());
	pos.SetY(image->getY());
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