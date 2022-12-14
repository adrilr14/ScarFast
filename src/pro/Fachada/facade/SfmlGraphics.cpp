#include "SfmlGraphics.hpp"
#include <iostream>

void SfmlGraphics::createWindow() {
    window = new sf::RenderWindow(sf::VideoMode(900,700),"Test");
}

bool SfmlGraphics::load_Sprites(std::string value) {
    
}

void SfmlGraphics::run() {
    sf::Texture tex;
    if (!tex.loadFromFile("resources/sprites.png")) {
        std::cerr << "Error cargando la imagen sprites.png";
        exit(0);
    }

    //Y creo el spritesheet a partir de la imagen anterior
    sf::Sprite sprite(tex);

    //Le pongo el centroide donde corresponde
    sprite.setOrigin(75 / 2, 75 / 2);
    //Cojo el sprite que me interesa por defecto del sheet
    sprite.setTextureRect(sf::IntRect(0 * 75, 0 * 75, 75, 75));

    // Lo dispongo en el centro de la pantalla
    sprite.setPosition(320, 240);

    //Bucle del juego
    while (window->isOpen()) {
        //Bucle de obtención de eventos
        sf::Event event;
        while (window->pollEvent(event)) {

        switch (event.type) {

        //Si se recibe el evento de cerrar la ventana la cierro
        case sf::Event::Closed:
            window->close();
            break;

        //Se pulsó una tecla, imprimo su codigo
        case sf::Event::KeyPressed:

            //Verifico si se pulsa alguna tecla de movimiento
            switch (event.key.code) {

            //Mapeo del cursor
            case sf::Keyboard::Right:
            sprite.setTextureRect(sf::IntRect(0 * 75, 2 * 75, 75, 75));
            //Escala por defecto
            sprite.setScale(1, 1);
            sprite.move(5, 0);
            break;

            case sf::Keyboard::Left:
            sprite.setTextureRect(sf::IntRect(0 * 75, 2 * 75, 75, 75));
            //Reflejo vertical
            sprite.setScale(-1, 1);
            sprite.move(-5, 0);
            break;

            case sf::Keyboard::Up:
            sprite.setTextureRect(sf::IntRect(0 * 75, 3 * 75, 75, 75));
            sprite.move(0, -5);
            break;

            case sf::Keyboard::Down:
            sprite.setTextureRect(sf::IntRect(0 * 75, 0 * 75, 75, 75));
            sprite.move(0, 5);
            break;

            //Tecla ESC para salir
            case sf::Keyboard::Escape:
            window->close();
            break;

            //Cualquier tecla desconocida se imprime por pantalla su código
            default:
            std::cout << event.key.code << std::endl;
            break;
            }
        }
        }

        window->clear();
        window->draw(sprite);
        window->display();
    }
}