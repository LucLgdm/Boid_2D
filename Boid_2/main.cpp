#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>
#include "Boid.h"

int main() {

    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    int width = desktopMode.width;
    int height = desktopMode.height;

    // Cr�er une fen�tre SFML
    sf::RenderWindow window(sf::VideoMode(width, height), "Boids");
    window.setFramerateLimit(50);
    
    // Creation du troupeau
    vector<Boid> flock;

    for (int i = 0; i < 100; i++) {
        flock.push_back(Boid(rand() % 800, rand() % 600));
    }

    // Boucle principale
    while (window.isOpen()) {
        // G�rer les �v�nements
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                // Fermer la fen�tre si l'utilisateur clique sur la croix
                window.close();
            }
        }
        // Effacer l'�cran (avec une couleur de fond blanc)
        window.clear(sf::Color::Blue);

        for (auto& boid : flock) {
            boid.update(flock, width, height);
            boid.draw(window);
        }
        
        // Afficher ce qui a �t� dessin�
        window.display();

    }
	return 0;
}