#include "Player.h"

Vector2 Player::GetPos()
{
	return pos;
}

void Player::SetPos(float x, float y)
{
	pos.SetX(x);
	pos.SetY(y);
}

Player::Player(Platform* platform)
{
	this->platform = platform;
}

void Player::LoadImage(std::string name, int x, int y)
{
	pos.SetX(x);
	pos.SetY(y);
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
	image->setX(pos.GetX());
	image->setY(pos.GetY());
}

void Player::KeyboardInput(int key)
{
	if (key == SDLK_SPACE)
	{
		auto bullet = new Bullet(platform);
		bullet->LoadImage("Assets/bullet.png", pos.GetX()+10, pos.GetY()-5);
		bullet->SetActive(true);
		activeBullets->push_back(bullet);
		
	}
	if (key == SDLK_LEFT)
	{
		pos.SetX(pos.GetX()-5);
	}
	if (key == SDLK_RIGHT)
	{
		pos.SetX(pos.GetX() +5);
	}
	if (key == SDLK_UP)
	{
		pos.SetY(pos.GetY() - 5);
	}
	if (key == SDLK_DOWN)
	{
		pos.SetY(pos.GetY() + 5);
	}
}
