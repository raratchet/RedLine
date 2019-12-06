#include "Enemy.h"

void Enemy::SetPlayerActiveBullets(std::list<Bullet*>* activeBullets)
{
	this->activePlayerBullets = activeBullets;
}

void Enemy::SetEnemyActiveBullets(std::list<Bullet*>* activeBullets)
{
	this->activeEnemyBullets = activeBullets;
}

bool Enemy::isActive()
{
	return active;
}

void Enemy::SetActive(bool active)
{
	this->active = active;
}

void Enemy::SetTimeBetweenShoots(int time)
{
	timeBetweenShoots = time;
}

int Enemy::GetH()
{
	return image->getH();
}
int Enemy::GetW()
{
	return image->getW();
}
