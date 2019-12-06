#pragma once
#include <string>
#include "SDL.h"
#include "Image.h"
#include "GameState.h"
#include "Font.h"
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "Sound.h"
#include "Music.h"

namespace GameEngine
{
	class Font;

	class Platform
	{
	private:
		int width;
		int height;
		SDL_Window* window;
	public:
		static SDL_Renderer* renderer;
		unsigned int GetTime();
		const Uint8* GetKeyboardState();
		Platform(std::string name);
		~Platform();
		void RenderClear();
		void RenderImage(Image* image, int x, int y, float angle);
		void RenderImage(Image* image, int x, int y,
						int clipX, int clipY, int clipW, 
						int clipH,float angle);
		void RenderPresent();
		void CheckEvent(GameState* obj, bool (GameState::* f)(int),
		bool (GameState::* mouse)(int x, int y, int button, int state));
		void DrawRect(int x, int y, int w, int h);
		void PlaySound(Sound* sound);
		void PlayMusic(Music* music);
		void RenderFont(Font* font, int x, int y, float angle);
	private:
		void RenderTexture(Image* image, int x, int y, double a);
		void RenderTexture(Image* image, int x, int y,
						   int clipX,int clipY,int clipW, int clipH,
			               double a);
		void RenderTexture(Font* font, int x, int y, double angle);
		void ReproduceSound(Mix_Chunk* chunk);
		void ReproduceMusic(Mix_Music* chunk);

	};
}