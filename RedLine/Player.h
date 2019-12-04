#pragma once
#include "GameObject.h"
#include "Image.h"
#include "Bullet.h"
#include "Platform.h"
#include <list>
#include "Sprites.h"
#include "Vector2.h"
#include "EnemyBullet.h"
#include "PlayerBullet.h"

using namespace GameEngine;

class Player : 	public GameObject
{
private:
	Sprite* image;
	Platform* platform;
	std::list<Bullet*> *activePlayerBullets;
	std::list<Bullet*> *activeEnemyBullets;
	bool isDead;
public:
	Player(Platform* platform);
	void LoadImage(std::string name, int x, int y);
	void SetActivePlayerBullets(std::list<Bullet*>* activeBullets);
	void SetActiveEnemyBullets(std::list<Bullet*>* activeBullets);
	void Init() override;
	void Draw() override;
	void Update() override;
	void KeyboardInput(int key);
	void KeyboardInput();
private:
	void CheckForCollision();
	bool BoxCollision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);
};

