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
    window.setFramerateLimit(30);

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
        vector<Boid> flock;

        for (int i = 0; i < 10; i++) {
            flock.push_back(Boid(rand() % 800, rand() % 600));
        }

        for (int i = 0; i < 1000; i++) {
            for (auto& boid : flock) {
                boid.update(flock);
            }
        }

        // Effacer l'écran (avec une couleur de fond blanc)
        window.clear(sf::Color::Black);
        // Afficher ce qui a été dessiné
        window.display();

    }




	

	return 0;
}