#include <iostream>
#include <SFML/Graphics.hpp>
#include "src/Vector/vector.h"
#include "src/VideoSettings.h"

int main()
{
    // Vector vec1(1, 1, 0);
    Vector vec2(2, 3);
    Vector vec3{1, 0};
    vec2 *= 0.5;

    vec2.setY(2);

    using Settings::Width;
    using Settings::Heigth;

    sf::RenderWindow window(sf::VideoMode(Width, Heigth),Settings::WindowName);
    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        if (clock.getElapsedTime().asMilliseconds() >= 10)
        {
            vec2.rotate(-0.02);
            vec3.rotate(-0.006);
            clock.restart();
        }
        
        // vec1.draw(window);
        vec2.draw(window);
        vec3.draw(window);

        window.display();
        window.clear();
    }
    
    return 0;
}