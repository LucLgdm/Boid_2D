#include "Vector2D.h"

using namespace std;

Vector2D::Vector2D(float x, float y) : x(x), y(y) {};

const float Vector2D::norme() {
	return sqrt(x * x + y * y);
}

void Vector2D::normalize() {
	float n = norme();
	if (n != 0) {
		x /= n;
		y /= n;
	}
}

Vector2D Vector2D::operator+(const Vector2D& other) const {
    return Vector2D(this->x + other.x, this->y + other.y);
}

Vector2D Vector2D::operator-(const Vector2D& other) const {
    return Vector2D(this->x - other.x, this->y - other.y);
}

Vector2D Vector2D::operator*(float scalar) const {
    return Vector2D(this->x * scalar, this->y * scalar);
}