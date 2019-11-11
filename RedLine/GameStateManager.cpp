#include "GameStateManager.h"
#include <iostream>
namespace GameEngine
{
	GameStateManager::GameStateManager()
	{
		platform = new Platform("BlackCable");
	}

	GameStateManager::~GameStateManager()
	{
	}

	void GameStateManager::GameLoop()
	{
		while (true)
		{
			try
			{
				if (states.size() == 0)
					throw std::exception("Error");
				auto state = states.top();
				platform->CheckEvent(state, &GameState::Input, &GameState::InputMouse);
				state->Update();
				state->Draw();
			}
			catch (...)
			{
				std::cout << "Critical error Pong is closing";
				break;
			}
		}
	}

	void GameStateManager::SetState(GameState* state)
	{
		state->Init(platform, this);
		states.push(state);
	}

	void GameStateManager::RealaseState()
	{
		auto state = states.top();
		state->Close();
		states.pop();
	}
}