#pragma once
#include "GameObject.h"
#include "Image.h"
#include "Bullet.h"
#include "Platform.h"
#include <list>
#include "Sprites.h"
#include "Vector2.h"

using namespace GameEngine;

class Player : 	public GameObject
{
private:
	Sprite* image;
	Vector2 pos;
	Platform* platform;
	std::list<Bullet*> *activeBullets;
public:
	Vector2 GetPos();
	void SetPos(float x, float y);
	Player(Platform* platform);
	void LoadImage(std::string name, int x, int y);
	void SetActiveBullets(std::list<Bullet*>* activeBullets);
	void Init() override;
	void Draw() override;
	void Update() override;
	void KeyboardInput(int key);
};

