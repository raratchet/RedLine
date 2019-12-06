#include "Game.h"
#include<iostream>

namespace RedLine
{
	int Game::score = 0;

	void Game::Init(Platform* platform, GameStateManager* gameStateManager) {
		this->platform = platform;
		lastTime = platform->GetTime();
		player = new Player(platform);
		player->LoadImage("Assets/player3.png",205,400);
		player->SetActivePlayerBullets(&activePlayerBullets);
		player->SetActiveEnemyBullets(&activeEnemyBullets);
		player->SetActiveEnemies(&ships);
		InitBackGround();
	}

	void Game::InitBackGround()
	{
		background = new Image();
		background->LoadImage("./Assets/Back.png");
		gameOver = new Image();
		gameOver->LoadImage("./Assets/GM.png");
		backMusic = new Music();
		backMusic->LoadSound("./Assets/8_Bit_Universe_CHOPSUEY.mp3");
		platform->PlayMusic(backMusic);
		fscore = new Font();
		fscore->SetUp(""+ to_string(score),"./Assets/Team.ttf",13);
	}

	void Game::DrawBackGround()
	{
		platform->RenderImage(background,0,0,0);
		fscore->UpdateText("" + to_string(score));
		platform->RenderFont(fscore,10,10,0);
	}

	void Game::Draw() {
		platform->RenderClear();
		DrawBackGround();
		player->Draw();
		BulletDraw();
		ShipDraw();
		if(player->IsDead()) platform->RenderImage(gameOver, 140, 240, 0);
		platform->RenderPresent();
	}

	void Game::Update() 
	{
		if (player->IsDead()) return;
		BulletUpdate();
		player->Update();
		ShipUpdate();
		SpawnEnemy();
		RemoveInActiveElements();
	}

	void Game::AddScore(int scoreA)
	{
		score += scoreA;
	}

	void Game::Close() 
	{
	}

	bool Game::Input(int key) 
	{
		player->KeyboardInput(key);
		return false;
	}

	bool Game::InputMouse(int x, int y, int button, int state)
	{
		return false;
	}

	void Game::SpawnEnemy()
	{
		if (lastTime + 1500 < platform->GetTime())
		{
			int a = rand();
			int x = 0;
			if (a % 3 == 0) x = 205;
			else if (a % 3 == 1) x = 350;
			else if (a % 3 == 2) x = 100;
			if(a % 2 == 0)
			{
				auto* ship = new GenericEnemy1(platform);
				ship->SetPlayerActiveBullets(&activePlayerBullets);
				ship->SetEnemyActiveBullets(&activeEnemyBullets);
				ship->LoadImage("Assets/enemy.png", 205, 5);
				ship->UpdatePlayerPos(player->GetPos());
				ships.push_back(ship);
				lastTime = platform->GetTime();
			}else if (a % 10 == 1)
			{
				auto* ship = new GenericEnemy2(platform);
				ship->SetPlayerActiveBullets(&activePlayerBullets);
				ship->SetEnemyActiveBullets(&activeEnemyBullets);
				ship->LoadImage("Assets/enemy.png", x, 5);
				ship->UpdatePlayerPos(player->GetPos());
				ships.push_back(ship);
				lastTime = platform->GetTime();
			}
		}
	}

	void Game::BulletUpdate() 
	{

		for (auto bullet : activePlayerBullets)
		{
			bullet->Update();
		}
		for (auto bullet : activeEnemyBullets)
		{
			bullet->Update();
		}
	}

	void Game::BulletDraw()
	{
		for (auto bullet : activePlayerBullets)
		{
			if (bullet->IsOutOfBounds() || !(bullet->isActive())) {
				inActiveElements.push_back(bullet);
				continue;
			}
			bullet->Draw();
		}
		for (auto bullet : activeEnemyBullets)
		{
			if (bullet->IsOutOfBounds() || !(bullet->isActive())) {
				inActiveElements.push_back(bullet);
				continue;
			}
			bullet->Draw();
		}
	}

	void Game::ShipDraw()
	{
		for (auto ship : ships)
		{
			ship->Draw();
		}
	}

	void Game::ShipUpdate()
	{
		for (auto ship : ships)
		{
			if (ship->IsOutOfBounds() || !(ship->isActive())) {
				inActiveElements.push_back(ship);
				continue;
			}
			ship->UpdatePlayerPos(player->GetPos());
			ship->Update();
			ship->Shoot();
		}
		RemoveFromList(&ships);
	}

	void Game::RemoveInActiveElements()
	{
		RemoveFromList(&ships);
		RemoveFromList(&activeEnemyBullets);
		RemoveFromList(&activePlayerBullets);
		inActiveElements.clear();
	}

	void Game::RemoveFromList(std::list<GameObject*>* listToMod)
	{
		for (auto element : inActiveElements)
		{
			listToMod->remove(element);
		}
	}

	void Game::RemoveFromList(std::list<Bullet*>* listToMod)
	{
		for (auto element : inActiveElements)
		{
			listToMod->remove((Bullet*)element);
		}
	}

	void Game::RemoveFromList(std::list<Enemy*>* listToMod)
	{
		for (auto element : inActiveElements)
		{
			listToMod->remove((Enemy*)element);
		}
	}


}