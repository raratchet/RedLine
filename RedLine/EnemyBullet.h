#pragma once
#include "Bullet.h"
#include "Vector2.h"


class EnemyBullet :
	public Bullet
{
private:
	Vector2 initialPos;
	Vector2 playerPos;
	Vector2 dir;
	int time;
public:
	EnemyBullet(Platform* platform);
	EnemyBullet(Platform* platform, Vector2 initialPos, Vector2 playerPos);
	void Update()override;
	void Init()override;
};

