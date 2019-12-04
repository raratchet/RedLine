#include "Enemy.h"

void Enemy::SetActiveBullets(std::list<Bullet*>* activeBullets)
{
	this->activeBullets = activeBullets;
}

bool Enemy::isActive()
{
	return active;
}