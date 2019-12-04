#pragma once
#include "GameState.h"
#include "Platform.h"
#include "GameStateManager.h"
#include "Player.h"
#include <list>
#include "Bullet.h"
#include "GenericEnemy1.h"
#include "GenericEnemy2.h"

namespace RedLine
{
	using namespace GameEngine;
	class Game : public GameState
	{
	private:
		Player* player;
		Platform* platform;
		EnemyBullet* bomb;
		std::list<Bullet*> activePlayerBullets;
		std::list<Bullet*> activeEnemyBullets;
		std::list<Enemy*> ships;
		unsigned int lastTime;

		GenericEnemy1* temp;
	public:
		virtual void Init(Platform*, GameStateManager*) override;
		virtual void Draw() override;
		virtual void Update() override;
		virtual void Close() override;
		virtual bool Input(int) override;
		virtual bool InputMouse(int x, int y, int button, int state) override;
	private:
		void SpawnEnemy();
		void BulletDraw();
		void BulletUpdate();
		void ShipDraw();
		void ShipUpdate();
	};

}