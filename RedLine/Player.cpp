#include "Player.h"

int Player::GetX()
{
	return x;
}

int Player::GetY()
{
	return y;
}

void Player::SetX(int x)
{
	this->x = x;
}

void Player::SetY(int y)
{
	this->y = y;
}

Player::Player(Platform* platform)
{
	this->platform = platform;
}

void Player::LoadImage(std::string name, int x, int y)
{
	this->x = x;
	this->y = y;
	image = new Sprite(platform, name,x,y,44,39,1,3);
	
}

void Player::SetActiveBullets(std::list<Bullet*>* activeBullets)
{
	this->activeBullets = activeBullets;
}

void Player::Init() 
{
}
void Player::Draw() 
{
	image->Draw();
	
}
void Player::Update() 
{
	image->setX(x);
	image->setY(y);
}

void Player::KeyboardInput(int key)
{
	if (key == SDLK_SPACE)
	{
		auto bullet = new Bullet(platform);
		bullet->LoadImage("Assets/bullet.png", x+10, y-5);
		bullet->SetActive(true);
		activeBullets->push_back(bullet);
		
	}
	if (key == SDLK_LEFT)
	{
		x -= 5;
	}
	if (key == SDLK_RIGHT)
	{
		x += 5;
	}
	if (key == SDLK_UP)
	{
		y -= 5;
	}
	if (key == SDLK_DOWN)
	{
		y += 5;
	}
}
