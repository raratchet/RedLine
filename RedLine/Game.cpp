#include "Game.h"
#include<iostream>

namespace RedLine
{
	void Game::Init(Platform* platform, GameStateManager* gameStateManager) {
		this->platform = platform;
		player = new Player(platform);
		player->LoadImage("Assets/player.png",205,400);
		player->SetActiveBullets(&activeBullets);
	}

	void Game::Draw() {
		platform->RenderClear();
		player->Draw();
		for (auto bullet : activeBullets)
		{
			bullet->Draw();
		}
		for (auto ship : ships)
		{
			ship->Draw();
		}
		platform->RenderPresent();
	}

	void Game::Update() {
		for (auto bullet : activeBullets)
		{
			bullet->Update();
		}
		for (auto ship : ships)
		{
			ship->Update();
		}
		player->Update();
		if (rand() % 100 < 1)
		{
			auto *ship = new GenericEnemy1(platform);
			ship->SetActiveBullets(&activeBullets);
			ship->LoadImage("Assets/player.png", 205, 100);
			ships.push_back(ship);
		}
	}

	void Game::Close() {
	}

	bool Game::Input(int key) {
		player->KeyboardInput(key);
		return false;
	}

	bool Game::InputMouse(int x, int y, int button, int state)
	{
		return false;
	}
}