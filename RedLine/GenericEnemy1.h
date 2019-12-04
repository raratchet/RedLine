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
#include "Enemy.h"

	using namespace GameEngine;

	class GenericEnemy1 : public Enemy
	{
	private:
		Vector2 playerPos;
	public:
		GenericEnemy1(Platform* platform);
		void LoadImage(std::string name, int x, int y) override;
		void Init() override;
		void Draw() override;
		void Update() override;
		void MoveEnemy() override;
		void Shoot();
		void UpdatePlayerPos(Vector2 pos);
	private:	
		bool BoxCollision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);
		bool CircleCollision(float r1, float r2, int x1, int y1, int x2, int y2);

	};


