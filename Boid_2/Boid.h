#pragma once
#ifndef BOID_H
#define BOID_H

#include <iostream>
using namespace std;
#include <vector>
#include "Vector2D.h"
#include <SFML/Graphics.hpp>

class Boid
{
	private:
		Vector2D position;
		Vector2D velocity;
		float radius;
		float orientation;

		Vector2D align(const vector<Boid>& boids) const;
		Vector2D cohere(const vector<Boid>& boids) const;
		Vector2D separate(const vector<Boid>& boids) const;

	public : 
		Boid(float, float);
		void update(const vector<Boid>& boids, int width, int height);
		Vector2D getPosition();
		Vector2D getVelocity();
		void draw(sf::RenderWindow& window);
		void updateOrientation();
};

#endif
