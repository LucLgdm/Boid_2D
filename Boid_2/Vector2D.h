#pragma once
#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>
#include <cmath>

class Vector2D
{
	public:
		float x, y;

		Vector2D(float, float);
		const float norme();
		void normalize();

		Vector2D operator+(const Vector2D&) const;
		Vector2D operator-(const Vector2D&) const;
		Vector2D operator*(const float) const;

};

#endif // VECTOR2D_H