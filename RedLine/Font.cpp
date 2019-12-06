#include "Font.h"

namespace GameEngine {

	void Font::SetUp(const std::string& text, const std::string& fontFile,
		int fontSize)
	{
		//Open the font
		font = TTF_OpenFont(fontFile.c_str(), fontSize);
		if (font == nullptr) {
			std::cout << "error en font" << std::endl;
			return;
		}
		//We need to first render to a surface as that's what TTF_RenderText
		//returns, then load that surface into a texture
		surf = TTF_RenderText_Blended(font, text.c_str(), color);
		if (surf == nullptr) {
			TTF_CloseFont(font);
			std::cout << "error en font2" << std::endl;
			return;
		}
		image = SDL_CreateTextureFromSurface(Platform::renderer, surf);
		if (image == nullptr) {
			std::cout << "error en font3" << std::endl;
			return;
		}
		//Clean up the surface and font
		SDL_FreeSurface(surf);

	}

	void Font::UpdateText(std::string text) {
		surf = TTF_RenderText_Blended(font, text.c_str(), color);
		image = SDL_CreateTextureFromSurface(Platform::renderer, surf);
		SDL_FreeSurface(surf);
	}

	SDL_Texture* Font::GetTexture() {
		return image;
	}
	int Font::GetWidth()
	{
		return w;
	}

	int Font::GetHeight()
	{
		return h;
	}
}
