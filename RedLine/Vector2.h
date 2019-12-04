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
		float VectorSize(Vector2 vector);
		Vector2 operator+(Vector2 v2);
		Vector2 operator-(Vector2 v2);
		float operator*(Vector2 v2);
		Vector2 operator*(float esc);
		Vector2 UnitVector(Vector2 vec);
};

