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
		unsigned int lastTime;
		float x;
		float y;
		int w;
		int h;
	public:
		Sprite(Platform* platform, std::string pathImage,int x, int y, int h, int w,
			   int horizontalFrames, int verticalFrames);
		void Draw();
		int getW();
		int getH();
		void setX(float x);
		void setY(float y);
		float getX();
		float getY();
		
	};

}