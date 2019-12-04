#pragma once
#include "GameObject.h"
#include "Image.h"
#include "Bullet.h"
#include "Platform.h"
#include "Bullet.h"
#include "Sprites.h"
#include <list>
#include "Enemy.h"

	using namespace GameEngine;

	class GenericEnemy2 : public Enemy
	{
	private:
		Sprite* image;
		Platform* platform;
		std::list<Bullet*>* activeBullets;
		bool active;
		int direction;
	public:
		GenericEnemy2(Platform* platform);
		void LoadImage(std::string name, int x, int y);
		void SetActiveBullets(std::list<Bullet*>* activeBullets);
		void Init() override;
		void Draw() override;
		void Update() override;
		void MoveEnemy();
		void UpdatePlayerPos(Vector2 pos) override;
		void Shoot() override;
	private:	
		bool BoxCollision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);
		bool CircleCollision(float r1, float r2, int x1, int y1, int x2, int y2);

	};


