#include "render.h"
#include "vector.h"
#include "videoSettings.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
  using namespace Settings;  

  sf::RenderWindow window(sf::VideoMode(Width, Heigth), "Vectors");
  Render sfml_window(&window);
  sf::Clock clock;

  Vector vec2(2, 3);
  vec2.setX(8);
  vec2 += {-3, 3};

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event))
      if (event.type == sf::Event::Closed)
        window.close();

    if (clock.getElapsedTime().asMilliseconds() >= 10) {
      vec2.rotate(-0.02);
      clock.restart();
    }

    sfml_window.draw(vec2);

    // vec2.draw();
    // vec3.draw();

    window.display();
    window.clear();
  }

  return 0;
}