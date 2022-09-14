#include <iostream>
#include <SFML/Graphics.hpp>
#include "src/Vector/vector.h"
#include "src/VideoSettings.h"


int main()
{
    Vector vec1(2, 2, 2);
    Vector vec2 = vec1;

    std::cout << "double = " << double(vec2) << "\n" 
              << "vec2 * 2 = " << double(vec2 * 2) << "\n"
              << "2 * vec1 = " << double(2 * vec1) << "\n";

    std::cout << 3.0 + double(vec2) << std::endl;

    using Settings::Width;
    using Settings::Heigth;

    uint32_t pixel_arr[Width][Heigth] = {};

    sf::RenderWindow window(sf::VideoMode(Width, Heigth),Settings::WindowName);
    
    sf::Texture texture;
    texture.create(Width, Heigth);

    sf::Sprite sprite(texture);

    int i = 0,
        j = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        if (i < 800 * 600)
            pixel_arr[i / 800][i % 600] = 0xFFFFFFFF;

        // std::cout << i << std::endl;
        i++;    
        texture.update((const uint8_t *) (pixel_arr));

        window.draw(sprite);
        window.display();
    }
    
    return 0;
}