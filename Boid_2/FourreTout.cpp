/*#include <SFML/Graphics.hpp>

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
        // Effacer l'écran (avec une couleur de fond blanc)
        window.clear(sf::Color::Black);
        // Afficher ce qui a été dessiné
        window.display();

    }

    // Boids

    sf::Texture texture;
    sf::Sprite sprite;

    texture.loadFromFile("arrow.png");
    sprite.setTexture(texture);
    sprite.setOrigin(sf::Vector2f(texture.getSize().x / 2, texture.getSize().y / 2));

    sprite.setScale(0.02f, 0.02f);   
    sprite.setPosition(vectorPosition.ConvertToSf());


    friend bool operator!=(const Boids & a, const Boids & b);
    */