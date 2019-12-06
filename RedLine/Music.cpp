#include "Music.h"
#include <iostream>

namespace GameEngine {

	void Music::LoadSound(std::string path) {
		char* writable = new char[path.size() + 1];
		std::copy(path.begin(), path.end(), writable);
		writable[path.size()] = '\0';
		music = Mix_LoadMUS(writable);
		if (music == 0)
		{
			std::cout << "Couldn´t load MUSIC FILE";
		}
		delete[] writable;
	}

	Mix_Music* Music::GetMusic() {
		return music;
	}

}
