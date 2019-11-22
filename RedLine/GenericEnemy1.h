#pragma once
#include "GameObject.h"
#include "Image.h"
#include "Bullet.h"
#include "Platform.h"
#include "Bullet.h"
#include "Sprites.h"
#include <list>

	using namespace GameEngine;

	class GenericEnemy1 : public GameObject
	{
	private:
		Sprite* image;
		int x{ 0 };
		int y{ 0 };
		Platform* platform;
		std::list<Bullet*>* activeBullets;
		bool active;
	public:
		int GetX();
		int GetY();
		void SetX(int x);
		void SetY(int y);
		GenericEnemy1(Platform* platform);
		void LoadImage(std::string name, int x, int y);
		void SetActiveBullets(std::list<Bullet*>* activeBullets);
		void Init() override;
		void Draw() override;
		void Update() override;
		void MoveEnemy();
	private:	
		bool BoxCollision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);
		bool CircleCollision(float r1, float r2, int x1, int y1, int x2, int y2);

	};


