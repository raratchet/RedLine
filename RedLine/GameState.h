#pragma once

namespace GameEngine
{


	class Platform;
	class GameStateManager;


	class GameState
	{
	public:
		virtual void Init(Platform*, GameStateManager*) = 0;
		virtual void Draw() = 0;
		virtual void Update() = 0;
		virtual void Close() = 0;
		virtual bool Input(int) = 0;
		virtual bool InputMouse(int x, int y, int button, int state) = 0;
	};
}
