#include "EnemyBullet.h"

EnemyBullet::EnemyBullet(Platform* platform) :Bullet(platform) 
{
	active = true;
	initialPos =  Vector2();
	playerPos =  Vector2();
	dir = Vector2();
	time = 0;
}

EnemyBullet::EnemyBullet(Platform* platform, Vector2 initialPos, Vector2 playerPos) : Bullet(platform)
{
	active = true;
	this->initialPos = initialPos;
	this->playerPos = playerPos;
	dir = Vector2();
	time = 0;
}

void EnemyBullet::Init()
{

}

void EnemyBullet::Update()
{
	if (dir.GetX() == 0 && dir.GetY()== 0)
	{
		Vector2 v(playerPos.GetX() - initialPos.GetX(), playerPos.GetY() - initialPos.GetY());
		v = v.UnitVector(v);
		dir = Vector2(v.GetX(), v.GetY());
	}
	time++;
	pos.SetX(initialPos.GetX() + time * dir.GetX()*3 );
	pos.SetY(initialPos.GetY() + time * dir.GetY()*5 );
}
