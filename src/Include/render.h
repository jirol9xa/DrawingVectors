#ifndef RENDER_H
#define RENDER_H

#include "basis.h"
#include <SFML/Graphics.hpp>

class Render
{
private:
    Basis basis_;
    sf::RenderWindow *window_;
    
public:
    Render(Basis basis, sf::RenderWindow *window) : basis_(basis), window_(window)  {}
    Render(sf::RenderWindow *window) : window_(window) {}

    void setBasis(const Basis & basis) { basis_ = basis; }
    
    void draw(double x, double y, double z, double arrow_x1, double arrow_x2, 
              double arrow_y1, double arrow_y2) const;

};

#endif