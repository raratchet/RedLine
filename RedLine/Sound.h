#pragma once
#include <SDL_mixer.h>
#include <string> 

namespace GameEngine {

	class Sound
	{
	private:
		Mix_Chunk* sound;
		short int volume;
		std::string path;
	public:
		void LoadSound(std::string path);
		Mix_Chunk* GetSound();
	};
}

