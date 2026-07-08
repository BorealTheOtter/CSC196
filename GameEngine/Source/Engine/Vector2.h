#pragma once

#include <cmath>

namespace sr
{
	struct Vector2 {
		float x, y;

		Vector2() = default;
		Vector2(float x, float y) : x {x}, y {y} {}
		Vector2(float v) : x{ v }, y{ v } {}

		Vector2 operator + (const Vector2& v) const { return Vector2{ this->x + v.x, this->y + v.y}; }
		Vector2 operator - (const Vector2& v) const { return Vector2{ this->x - v.x, this->y - v.y}; }
		Vector2 operator * (const Vector2& v) const { return Vector2{ this->x * v.x, this->y * v.y}; }
		Vector2 operator / (const Vector2& v) const { return Vector2{ this->x / v.x, this->y / v.y}; }

		Vector2 operator + (float s) const { return Vector2{ this->x + s, this->y + s }; }
		Vector2 operator - (float s) const { return Vector2{ this->x - s, this->y - s }; }
		Vector2 operator * (float s) const { return Vector2{ this->x * s, this->y * s }; }
		Vector2 operator / (float s) const { return Vector2{ this->x / s, this->y / s }; }

		Vector2 operator += (const Vector2& v) { this->x += v.x; this->y += v.y; return *this; }
		Vector2 operator -= (const Vector2& v) { this->x -= v.x; this->y -= v.y; return *this; }
		Vector2 operator *= (const Vector2& v) { this->x *= v.x; this->y *= v.y; return *this; }
		Vector2 operator /= (const Vector2& v) { this->x /= v.x; this->y /= v.y; return *this; }

		Vector2 operator += (float s) { this->x += s; this->y += s; return *this; }
		Vector2 operator -= (float s) { this->x -= s; this->y -= s; return *this; }
		Vector2 operator *= (float s) { this->x *= s; this->y *= s; return *this; }
		Vector2 operator /= (float s) { this->x /= s; this->y /= s; return *this; }

		float LengthSqr() const { return (float)(pow(x, 2) + pow(y, 2)); }
		float Length() const { return sqrt(LengthSqr()); }
	};
}