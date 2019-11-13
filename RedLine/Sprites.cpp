#include "Sprites.h"
namespace GameEngine
{
	Sprite::Sprite(Platform* platform, std::string pathImage, int x, int y, int h, int w,
		int horizontalFrames, int verticalFrames)
	{
		actualFrame = 0;
		this->platform = platform;
		source = new Image();
		source->LoadImage(pathImage);
		totalFrames = horizontalFrames * verticalFrames;
		setX(x);
		setY(y);
		for (int j = 0; j < verticalFrames; j++)
		{

			for (int i = 0; i < horizontalFrames; i++)
			{
				SDL_Rect frame;
				frame.x = i * w;
				frame.y = j * h;
				frame.h = h;
				frame.w = w;
				frames.push_back(frame);
			}
		}
	}

	void Sprite::Draw()
	{
		platform->RenderImage(source, x, y, frames[actualFrame].x, frames[actualFrame].y, frames[actualFrame].h,
			frames[actualFrame].w, 0);
		if(actualFrame < totalFrames-1)
		{
			actualFrame++;
		}
		else
		{
			actualFrame=0;
		}		
	}

	void Sprite::setX(int x)
	{
		this->x = x;
	}

	void Sprite::setY(int y)
	{
		this->y = y;
	}
}