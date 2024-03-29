#pragma once
#include "GameObject.h"
#include "Image.h"
#include "Platform.h"
#include "Vector2.h"

using namespace GameEngine;

class Bullet : public GameObject
{
protected:
	Image* image;
	int velocity = 15;
	Platform* platform;
	int active;
	Vector2 pos;
public:
	void SetActive(bool);
	bool GetActive();
	void SetPos(float x, float y);
	Vector2 GetPos();
	int GetW();
	int GetH();
	void SetVelocity(int vel);
	Bullet(Platform* platform);
	void LoadImage(std::string name, int x, int y);
	void Init() override;
	void Draw() override;
	void Update() override;
	bool isActive();

protected:
	void CheckForOutOfBounds();
};