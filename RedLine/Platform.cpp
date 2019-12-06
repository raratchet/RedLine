#include "Platform.h"
#include "SDL.h"
#include<iostream>
#include "GameState.h"
namespace GameEngine
{
	SDL_Renderer* Platform::renderer;

	Platform::Platform(std::string name)
	{
		width = 480;
		height = 640;
		window = 0;

		if (SDL_Init(SDL_INIT_VIDEO) != 0) {
			std::cout << "SDL_Init";
			return;
		}
		window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
		if (window == nullptr) {
			std::cout << "CreateWindow";
			SDL_Quit();
			return;
		}

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (renderer == nullptr) {
			std::cout << "CreateRenderer";
			SDL_Quit();
			return;
		}

		if (TTF_Init() != 0)
		{
			std::cout << "TTF_Init error";
			return;
		}

		if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
		{
			std::cout << "Audio error";
			return;
		}
	}

	void Platform::RenderClear()
	{
		SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
		SDL_RenderClear(renderer);
	}

	void Platform::RenderPresent()
	{
		SDL_RenderPresent(renderer);
	}


	void Platform::DrawRect(int x, int y, int w, int h)
	{
		SDL_Rect rect;
		rect.x = x;
		rect.y = y;
		rect.w = w;
		rect.h = h;
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		SDL_RenderFillRect(renderer, &rect);
		SDL_RenderDrawRect(renderer, &rect);

	}

	void Platform::RenderImage(Image* image, int x, int y,
		int clipX, int clipY, int clipW, int clipH,
		float angle)
	{
		RenderTexture(image, x, y, clipX, clipY, clipW, clipH, angle);
	}

	void Platform::RenderImage(Image* image, int x, int y, float angle)
	{
		RenderTexture(image, x, y, angle);

	}
	void Platform::RenderTexture(Image* image, int x, int y,
		int clipX, int clipY, int clipW, int clipH,
		double a)
	{
		SDL_Rect drawRect;
		drawRect.x = clipX;
		drawRect.y = clipY;
		drawRect.w = clipW;
		drawRect.h = clipH;
		SDL_Rect srcrect;
		srcrect.x = x; 
		srcrect.y = y;
		srcrect.w = clipW;
		srcrect.h = clipH;
		SDL_RenderCopyEx(renderer, image->GetTexture()
			, &drawRect, &srcrect, a, NULL, SDL_FLIP_NONE);
	}

	void Platform::RenderTexture(Font* font, int x, int y, double angle)
	{
		SDL_Rect srcrect;
		srcrect.x = x;
		srcrect.y = y;
		srcrect.w = font->GetWidth();
		srcrect.h = font->GetHeight();
		SDL_RenderCopyEx(renderer, font->GetTexture()
			, NULL, &srcrect, angle, NULL, SDL_FLIP_NONE);
	}

	unsigned int Platform::GetTime()
	{
		return SDL_GetTicks();
	}

	const Uint8* Platform::GetKeyboardState() 
	{
		 const Uint8* temp = SDL_GetKeyboardState(NULL);
		 return temp;
	}

	void Platform::RenderTexture(Image* image, int x, int y, double a)
	{
		SDL_Rect srcrect;
		srcrect.x = x;
		srcrect.y = y;
		srcrect.w = image->GetWidth();
		srcrect.h = image->GetHeight();
		SDL_RenderCopyEx(renderer, image->GetTexture()
			, NULL, &srcrect, a, NULL, SDL_FLIP_NONE);
	}

	void Platform::PlaySound(Sound* sound) {
		ReproduceSound(sound->GetSound());
	}

	void Platform::PlayMusic(Music* sound) {
		ReproduceMusic(sound->GetMusic());
	}

	void Platform::ReproduceSound(Mix_Chunk* chunk) {
		Mix_PlayChannel(-1, chunk, 0);
	}

	void Platform::ReproduceMusic(Mix_Music* chunk) {
		Mix_PlayMusic(chunk, 10);
	}

	void Platform::RenderFont(Font* font, int x, int y, float angle)
	{
		RenderTexture(font, x, y, angle);

	}

	Platform::~Platform()
	{
	}

	void Platform::CheckEvent(GameState* gamestate,
		bool (GameState::* input)(int),
		bool (GameState::* mouse)(int x, int y, int button, int state))
	{
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_KEYDOWN) {
				(gamestate->*input)(e.key.keysym.sym);
			}
			if (e.type == SDL_MOUSEMOTION) {
				(gamestate->*mouse)(e.motion.x, e.motion.y, e.button.button, 0);
			}
			else if (e.type == SDL_MOUSEBUTTONDOWN) {
				(gamestate->*mouse)(e.motion.x, e.motion.y, e.button.button, 1);
			}
			else if (e.type == SDL_MOUSEBUTTONUP) {
				(gamestate->*mouse)(e.motion.x, e.motion.y, e.button.button, 2);
			}
		}
	}
}