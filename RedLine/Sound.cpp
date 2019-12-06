#include "Sound.h"
#include <iostream>

namespace GameEngine {

	void Sound::LoadSound(std::string path) {
		char* writable = new char[path.size() + 1];
		std::copy(path.begin(), path.end(), writable);
		writable[path.size()] = '\0';
		sound = Mix_LoadWAV(writable);
		if (sound == 0)
		{
			std::cout << "Couldn´t load sound";
		}
		delete[] writable;
	}

	Mix_Chunk* Sound::GetSound() {
		return sound;
	}
}