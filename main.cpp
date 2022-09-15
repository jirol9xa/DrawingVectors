#include <iostream>
#include <SFML/Graphics.hpp>
#include "vector.h"
#include "videoSettings.h"
#include "render.h"


int main()
{
    // Vector vec1(1, 1, 0);
    

    using Settings::Width;
    using Settings::Heigth;

    sf::RenderWindow window(sf::VideoMode(Width, Heigth),Settings::WindowName);
    Render sfml_window(&window);
    sf::Clock clock;

    Vector vec2(sfml_window, 2, 3);
    Vector vec3{sfml_window, 1, 0};
    vec2 *= 0.5;

    vec2.setY(2);

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
        
        vec2.draw();
        vec3.draw();

        window.display();
        window.clear();
    }
    
    return 0;
}