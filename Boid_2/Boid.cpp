#include "Boid.h"
#include <corecrt_math_defines.h>

Boid::Boid(float x, float y) : position(x, y), radius(50), velocity(rand() % 20, rand() % 20) {
	updateOrientation();
};

Vector2D Boid::align(const vector<Boid>& boids) const {
	Vector2D avgVelocity(0, 0);
	int count = 0;
	float alignRadius = 30.0f;

	for (const auto& boid : boids) {
		Vector2D tempVec = this->position - boid.position;
		float distance = tempVec.norme();
		if (distance > 0 && distance < alignRadius) {
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
	Vector2D directionToCenter(0, 0);
	int count = 0;
	float cohereRadius = 20.0f;

	for (const auto& boid : boids) {
		float distance = (this->position - boid.position).norme();
		if (&boid != this && distance < cohereRadius) {
			centerOfMass = centerOfMass + boid.position * (1.0f / distance); // Moyenne pondérée
			count++;
		}
	}

	if (count > 0) {
		centerOfMass = centerOfMass * (1.0f / count);
		directionToCenter = centerOfMass - this->position; // Direction vers le centre de masse
		directionToCenter.normalize();
	}

	return directionToCenter;
}





Vector2D Boid::separate(const vector<Boid>& boids) const {
	Vector2D separation(0, 0);
	float separationRadius = 20.0f;

	for (const auto& boid : boids) {
		float distance = (this->position - boid.position).norme();
		if (distance > 0 && distance < separationRadius) {
			separation = separation - (boid.position - this->position);
		}
	}

	return separation;
}


void Boid::update(const vector<Boid>& boids, int width, int height) {
	Vector2D alignement = align(boids);
	Vector2D cohesion = cohere(boids);
	Vector2D separation = separate(boids);

	this->velocity = this->velocity + alignement + cohesion + separation;

	this->velocity.normalize();
	this->velocity = this->velocity * 2.0f;

	this->position = this->position + this->velocity;

	if (this->position.x < 0) {
		this->position.x += width;
	}
	else if (this->position.x > width) {
		this->position.x -= width;
	}
	
	if (this->position.y < 0) {
		this->position.y += height;
	}
	else if (this->position.y > height) {
		this->position.y -= height;
	}

}

Vector2D Boid::getPosition() {
	Vector2D out(this->position.x, this->position.y);
	return out;
}

Vector2D Boid::getVelocity() {
	Vector2D out(this->velocity.x, this->velocity.y);
	return out;
}

void Boid::draw(sf::RenderWindow& window) {
	sf::ConvexShape triangle;
	triangle.setPointCount(3); // Définir le nombre de points du triangle
	triangle.setPoint(0, sf::Vector2f(0, -5)); // Définir les coordonnées des points du triangle
	triangle.setPoint(1, sf::Vector2f(2, 2));
	triangle.setPoint(2, sf::Vector2f(-2, 2));
	triangle.setFillColor(sf::Color::Green); // Définir la couleur de remplissage du triangle
	triangle.setOutlineColor(sf::Color::Black); // Définir la couleur du contour du triangle
	triangle.setOutlineThickness(2); // Définir l'épaisseur du contour du triangle
	triangle.setOrigin(0, 0); // Définir l'origine du triangle (pour la rotation et le positionnement)

	// Définir la position du triangle sur la position du Boid
	triangle.setPosition(position.x, position.y);

	// Définir la rotation du triangle en fonction de l'orientation du Boid
	updateOrientation();
	triangle.setRotation(this->orientation);

	// Dessiner le triangle dans la fenêtre SFML
	window.draw(triangle);
}

void Boid::updateOrientation() {
	float angle_rad = atan2(velocity.y, velocity.x);

	// Convertir l'angle en degrés
	float angle_deg = angle_rad * (180.0f / M_PI);

	// Ajuster l'angle pour qu'il soit dans la plage [0, 360)
	if (angle_deg < 0) {
		angle_deg += 360.0f;
	}

	// Mettre à jour l'orientation du Boid
	this->orientation = angle_deg + 90.0f;

	if (this->orientation >= 360.0f) {
		this->orientation -= 360.0f;
	}
}