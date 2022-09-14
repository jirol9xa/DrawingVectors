#include <iostream>
#include <SFML/Graphics.hpp>
#include "src/Vector/vector.h"
#include "src/VideoSettings.h"


int main()
{
    Vector vec1(3, 2, 0);

    using Settings::Width;
    using Settings::Heigth;

    uint32_t pixel_arr[Width][Heigth] = {};

    sf::RenderWindow window(sf::VideoMode(Width, Heigth),Settings::WindowName);
    
    sf::Texture texture;
    texture.create(Width, Heigth);

    sf::Sprite sprite(texture);
    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        texture.update((const uint8_t *) (pixel_arr));

        if (clock.getElapsedTime().asMilliseconds() >= 10)
        {
            vec1.rotate(-0.02);
            // vec2.rotate(0.02 / 60);
            clock.restart();
        }
        
        vec1.draw(window);

        window.display();
        window.clear();
    }
    
    return 0;
}