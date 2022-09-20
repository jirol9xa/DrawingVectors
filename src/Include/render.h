#ifndef RENDER_H
#define RENDER_H

#include "basis.h"
#include "vector.h"
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
    
    void draw(Vector &vec) const;
    void draw(Vector &vec, Basis basis)
    {
        basis_ = basis;
        draw(vec);
    }
};
#endif