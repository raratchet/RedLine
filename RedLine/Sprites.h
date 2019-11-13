#pragma once
#include <vector>
#include "Image.h"
#include "Platform.h"
namespace GameEngine
{
	using namespace std;
	class Sprite
	{
	private:
		int actualFrame;
		Image* source;
		Platform* platform;
		std::vector<SDL_Rect> frames;
		int totalFrames;
		int x;
		int y;
	public:
		Sprite(Platform* platform, std::string pathImage,int x, int y, int h, int w,
			   int horizontalFrames, int verticalFrames);
		void Draw();
		void setX(int x);
		void setY(int y);
	};

}