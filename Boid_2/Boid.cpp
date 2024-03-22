#include "Boid.h"

Vector2D Boid::align(const vector<Boid>& boids) const {
	Vector2D avgVelocity(0, 0);
	int count = 0;

	for (const auto& boid : boids) {
		Vector2D tempVec = this->position - boid.position;
		float distance = tempVec.norme();
		if (distance > 0 && distance < this->radius) {
			avgVelocity = avgVelocity + boid.velocity;
			count++;
		}
	}

	if (count > 0) {
		avgVelocity = avgVelocity * (1.0f / count);
		avgVelocity.normalize();
	}

	return avgVelocity;
}

Vector2D Boid::cohere(const vector<Boid>& boids) const {
	Vector2D centerOfMass(0, 0);
	int count = 0;

	for (const auto& boid : boids) {
		float distance = (this->position - boid.position).norme();
		if (distance > 0 && distance < this->radius) {
			centerOfMass = centerOfMass + boid.position;
			count++;
		}
	}

	if (count > 0) {
		centerOfMass = centerOfMass * (1.0f / count);
		return(centerOfMass - this->position);
	}

	return Vector2D(0, 0);
}

Vector2D Boid::separate(const vector<Boid>& boids) const {
	Vector2D separation(0, 0);

	for (const auto& boid : boids) {
		float distance = (this->position - boid.position).norme();
		if (distance > 0 && distance < this->radius) {
			separation = separation - (boid.position - this->position);
		}
	}

	return separation;
}


Boid::Boid(float x, float y) : position(x, y), velocity(1, 0), radius(50) {};


void Boid::update(const vector<Boid>& boids) {
	Vector2D alignement = align(boids);
	Vector2D cohesion = cohere(boids);
	Vector2D separation = separate(boids);

	this->velocity = this->velocity + alignement + cohesion + separation;

	this->velocity.normalize();
	this->velocity = this->velocity * 2.0f;

	this->position = this->position + this->velocity;
}

Vector2D Boid::getPosition() {
	Vector2D out(this->position.x, this->position.y);
	return out;
}

Vector2D Boid::getVelocity() {
	Vector2D out(this->velocity.x, this->velocity.y);
	return out;
}