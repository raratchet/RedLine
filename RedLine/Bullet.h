#pragma once
#include "GameObject.h"
#include "Image.h"
#include "Platform.h"

using namespace GameEngine;

class Bullet : public GameObject
{
private:
	Image* image;
	int x{ 0 };
	int y{ 0 };
	int velocity = 15;
	Platform* platform;
public:
	int GetX();
	int GetY();
	void SetX(int x);
	void SetY(int y);
	void SetVelocity(int vel);
	Bullet(Platform* platform);
	void LoadImage(std::string name, int x, int y);
	void Init() override;
	void Draw() override;
	void Update() override;
};