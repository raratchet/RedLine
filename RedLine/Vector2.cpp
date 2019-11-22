#include "Vector2.h"

Vector2::Vector2()
{
	x = y = 0;
}
Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}
float Vector2::GetX()
{
	return x;
}
float Vector2::GetY()
{
	return y;
}
void Vector2::SetY(float y)
{
	this->y = y;
}
void Vector2::SetX(float x)
{
	this->x = x;
}
Vector2 Vector2::operator+(Vector2 v2)
{
	Vector2 temp;
	temp.SetX(x + v2.GetX());
	temp.SetY(y + v2.GetY());
	return temp;
}

Vector2 Vector2::operator-(Vector2 v2)
{
	Vector2 temp;
	temp.SetX(x - v2.GetX());
	temp.SetY(y - v2.GetY());
	return temp;
}

float Vector2::operator*(Vector2 v2)
{
	float temp;
	temp = x * v2.GetX() + y * v2.GetY();
	return temp;
}

Vector2 Vector2::operator*(float esc) {
	Vector2 temp;
	temp.SetX(x*esc);
	temp.SetY(y*esc);
	return temp;
}
