#pragma once
#include "GameObject.h"
#include "Image.h"
#include "Bullet.h"
#include "Platform.h"
#include <list>

using namespace GameEngine;

class Player : 	public GameObject
{
private:
	Image* image;
	int x{ 0 };
	int y{ 0 };
	Platform* platform;
	std::list<Bullet*> *activeBullets;
public:
	int GetX();
	int GetY();
	void SetX(int x);
	void SetY(int y);
	Player(Platform* platform);
	void LoadImage(std::string name, int x, int y);
	void SetActiveBullets(std::list<Bullet*>* activeBullets);
	void Init() override;
	void Draw() override;
	void Update() override;
	void KeyboardInput(int key);
};

