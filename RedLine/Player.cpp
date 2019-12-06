#include "Player.h"


Player::Player(Platform* platform)
{
	this->platform = platform;
	isDead = false;
	hp = 4;
	activeEnemyBullets = 0;
	activePlayerBullets = 0;
	activeEnemies = 0;
	image = 0;
}

void Player::LoadImage(std::string name, int x, int y)
{
	pos.SetX(x);
	pos.SetY(y);
	image = new Sprite(platform, name,x,y,44,39,1,3);
	
}

void Player::SetActivePlayerBullets(std::list<Bullet*>* activeBullets)
{
	this->activePlayerBullets = activeBullets;
}

void Player::SetActiveEnemyBullets(std::list<Bullet*>* activeBullets)
{
	this->activeEnemyBullets = activeBullets;
}

void Player::SetActiveEnemies(std::list<Enemy*>* activeEnemies)
{
	this->activeEnemies = activeEnemies;
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
	KeyboardInput();
	image->setX(pos.GetX());
	image->setY(pos.GetY());
	CheckForCollision();
}

bool Player::IsDead()
{
	return isDead;
}

void Player::KeyboardInput()
{
	const Uint8* key = platform->GetKeyboardState();
	if (key[SDL_SCANCODE_UP] && pos.GetY()-5 > 0 ) {
		pos.SetY(pos.GetY() - 5);
	}
	if (key[SDL_SCANCODE_DOWN] && pos.GetY() + 5 < 640 - image->getH()) {
		pos.SetY(pos.GetY() + 5);
	}
	if (key[SDL_SCANCODE_RIGHT] && pos.GetX() + 5 < 480 - image->getW()) {
		pos.SetX(pos.GetX() + 5);
	}
	if (key[SDL_SCANCODE_LEFT] && pos.GetX()-5 > 0) {
		pos.SetX(pos.GetX() - 5);
	}
}

void Player::KeyboardInput(int key)
{
	if (key == SDLK_SPACE)
	{
		auto bullet = new PlayerBullet(platform);
		bullet->LoadImage("Assets/bulletP.png", pos.GetX()+10, pos.GetY()-5);
		bullet->SetActive(true);
		activePlayerBullets->push_back(bullet);
		
	}
}

void Player::CheckForCollision() {
	Vector2 pos = this->GetPos();
	for (auto bullet : *activeEnemyBullets)
	{
		Vector2 p = bullet->GetPos();
		if (BoxCollision(pos.GetX(), pos.GetY(), this->image->getW(), this->image->getH(), p.GetX(), p.GetY(), bullet->GetH(), bullet->GetW())) {
			bullet->SetActive(false);
			hp--;
			if (hp <= 0) isDead = true;
		}
	}

	for (auto enemy : *activeEnemies)
	{
		Vector2 p = enemy->GetPos();
		if (BoxCollision(pos.GetX(), pos.GetY(), this->image->getW(), this->image->getH(), p.GetX(), p.GetY(), enemy->GetH(), enemy->GetW())) {
			enemy->SetActive(false);
			hp--;
			if (hp <= 0) isDead = true;
		}
	}
}

bool Player::BoxCollision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
{
	if ((x2 > x1&& x2 < x1 + w1) || (x2 + w2 > x1&& x2 + w2 < x1 + w1))
	{
		if ((y2 > y1&& y2 < y1 + h1) || (y2 + h2 > y1&& y2 + h2 < y1 + h1))
		{
			return true;
		}
	}
	return false;

}
