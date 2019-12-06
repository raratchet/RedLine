#pragma once
#include <SDL_mixer.h>
#include <string> 

namespace GameEngine {

	class Music
	{
	private:
		Mix_Music* music;
		short int volume;
		std::string path;
	public:
		void LoadSound(std::string path);
		Mix_Music* GetMusic();
	};
}

