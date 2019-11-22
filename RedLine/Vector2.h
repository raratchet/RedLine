#pragma once
class Vector2
{
	private:
		float x;
		float y;
	public:
		Vector2();
		Vector2(float x, float y);
		float GetX();
		float GetY();
		void SetY(float y);
		void SetX(float x);
		Vector2 operator+(Vector2 v2);
		Vector2 operator-(Vector2 v2);
		float operator*(Vector2 v2);
		Vector2 operator*(float esc);
};

