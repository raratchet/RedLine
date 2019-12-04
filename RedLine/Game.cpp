#include "Game.h"
#include<iostream>

namespace RedLine
{
	void Game::Init(Platform* platform, GameStateManager* gameStateManager) {
		this->platform = platform;
		lastTime = platform->GetTime();
		player = new Player(platform);
		player->LoadImage("Assets/player.png",205,400);
		player->SetActivePlayerBullets(&activePlayerBullets);
		player->SetActiveEnemyBullets(&activeEnemyBullets);
	}

	void Game::Draw() {
		platform->RenderClear();
		player->Draw();
		BulletDraw();
		ShipDraw();
		platform->RenderPresent();
	}

	void Game::Update() 
	{
		BulletUpdate();
		player->Update();
		ShipUpdate();
		SpawnEnemy();
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
		if (lastTime + 1000 < platform->GetTime())
		{
			int a = rand();
			if(a % 10 == 1)
			{
				auto* ship = new GenericEnemy1(platform);
				ship->SetActiveBullets(&activeEnemyBullets);
				ship->LoadImage("Assets/player.png", 205, 0);
				ship->UpdatePlayerPos(player->GetPos());
				ships.push_back(ship);
				lastTime = platform->GetTime();
			}else if (a % 10 == 2)
			{
				auto* ship = new GenericEnemy2(platform);
				ship->SetActiveBullets(&activeEnemyBullets);
				ship->LoadImage("Assets/player.png", 205, 0);
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
				//eliminar de la lista
				continue;
			}
			bullet->Draw();
		}
		for (auto bullet : activeEnemyBullets)
		{
			if (bullet->IsOutOfBounds() || !(bullet->isActive())) {
				//eliminar de la lista
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
				//eliminar de la lista
				continue;
			}
			ship->UpdatePlayerPos(player->GetPos());
			ship->Update();
			if (rand() % 200 < 1) ship->Shoot();
		}
	}
}