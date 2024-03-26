#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>
#include "Boid.h"

int main() {

    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    int width = desktopMode.width;
    int height = desktopMode.height;

    // Créer une fenêtre SFML
    sf::RenderWindow window(sf::VideoMode(width, height), "Boids");
    window.setFramerateLimit(50);
    
    // Creation du troupeau
    vector<Boid> flock;

    for (int i = 0; i < 100; i++) {
        flock.push_back(Boid(rand() % 800, rand() % 600));
    }

    // Boucle principale
    while (window.isOpen()) {
        // Gérer les événements
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                // Fermer la fenêtre si l'utilisateur clique sur la croix
                window.close();
            }
        }
        // Effacer l'écran (avec une couleur de fond blanc)
        window.clear(sf::Color::Blue);

        for (auto& boid : flock) {
            boid.update(flock, width, height);
            boid.draw(window);
        }
        
        // Afficher ce qui a été dessiné
        window.display();

    }
	return 0;
}