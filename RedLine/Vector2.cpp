#include "Vector2.h"
#include<math.h>

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

Vector2 Vector2::UnitVector(Vector2 vector) 
{
	float size = VectorSize(vector);
	Vector2 unit = Vector2(vector.x / size, vector.y / size);
	return unit;
}

float Vector2::VectorSize(Vector2 vector) {
	float x = vector.GetX();
	float y = vector.GetY();
	return (float)sqrt((x * x) + (y * y));
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
