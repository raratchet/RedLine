#pragma once
#include "GameObject.h"
#include "Image.h"
#include "Bullet.h"
#include "Platform.h"
#include "Bullet.h"
#include "Sprites.h"
#include <list>
#include "EnemyBullet.h"
#include "Vector2.h"

class Enemy :
	public GameObject
{
protected:
	Sprite* image;
	Platform* platform;
	std::list<Bullet*>* activeEnemyBullets;
	std::list<Bullet*>* activePlayerBullets;
	bool active;
	bool ableToShoot;
	float timeBetweenShoots = 2;
	unsigned int lastTime;
public:
	virtual void Init() = 0;
	virtual void Draw() = 0;
	virtual void Update() = 0;
	virtual void MoveEnemy() = 0;
	virtual void UpdatePlayerPos(Vector2) = 0;
	virtual void Shoot() = 0;
	virtual void LoadImage(std::string name, int x, int y) = 0;
	void SetPlayerActiveBullets(std::list<Bullet*>* activeBullets);
	void SetEnemyActiveBullets(std::list<Bullet*>* activeBullets);
	void SetTimeBetweenShoots(int);
	bool isActive();
	void SetActive(bool);
	int GetH();
	int GetW();
};

