#pragma once
#include "GameState.h"
#include "Platform.h"
#include "GameStateManager.h"
#include "Player.h"
#include <list>
#include "Bullet.h"
namespace RedLine
{
	using namespace GameEngine;
	class Game : public GameState
	{
	private:
		Player* player;
		Platform* platform;
		std::list<Bullet*> activeBullets;
	public:
		virtual void Init(Platform*, GameStateManager*) override;
		virtual void Draw() override;
		virtual void Update() override;
		virtual void Close() override;
		virtual bool Input(int) override;
		virtual bool InputMouse(int x, int y, int button, int state) override;
	};

}