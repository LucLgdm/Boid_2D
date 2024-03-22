#pragma once
#ifndef BOID_H
#define BOID_H

#include <iostream>
using namespace std;
#include <vector>
#include "Vector2D.h"

class Boid
{
	private:
		Vector2D position;
		Vector2D velocity;
		float radius;

		Vector2D align(const vector<Boid>& boids) const;
		Vector2D cohere(const vector<Boid>& boids) const;
		Vector2D separate(const vector<Boid>& boids) const;

	public : 
		Boid(float, float);
		void update(const vector<Boid>& boids);
		Vector2D getPosition();
		Vector2D getVelocity();
};

#endif
