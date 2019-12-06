#pragma once
#include "SDL.h"
#include <iostream>
#include "SDL_ttf.h"
#include "Platform.h"

namespace GameEngine {

	class Font
	{
	private:
		SDL_Texture* image;
		TTF_Font* font;
		SDL_Surface* surf;
		SDL_Color color{ 255,255,255 };
		std::string text;
		const int w = 70;
		const int h = 35;
	public:
		void SetUp(const std::string& text, const std::string& fontFile, int fontSize);
		SDL_Texture* GetTexture();
		int GetWidth();
		int GetHeight();
		void UpdateText(std::string text);
	};
}

