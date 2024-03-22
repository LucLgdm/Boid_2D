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
    window.setFramerateLimit(30);

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
        vector<Boid> flock;

        for (int i = 0; i < 10; i++) {
            flock.push_back(Boid(rand() % 800, rand() % 600));
        }

        for (int i = 0; i < 1000; i++) {
            for (auto& boid : flock) {
                boid.update(flock);
            }
        }

        // Effacer l'�cran (avec une couleur de fond blanc)
        window.clear(sf::Color::Black);
        // Afficher ce qui a �t� dessin�
        window.display();

    }




	

	return 0;
}