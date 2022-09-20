#include "render.h"

void Render::draw(Vector &vec) const
{
    double X0    = basis_.getX(),
           Y0    = basis_.getY(),
           Scale = basis_.getScale(),
           absX  = X0 + vec.getX() * Scale,
           absY  = Y0 - vec.getY() * Scale;

    sf::Vertex mainLine[] = 
    {
        sf::Vertex(sf::Vector2f(X0, Y0)),
        sf::Vertex(sf::Vector2f(absX, absY)),
    };
    window_->draw(mainLine, 2, sf::Lines);
    
    sf::Vertex rightLine[] =
    {
        sf::Vertex(sf::Vector2f(absX, absY)),
        sf::Vertex(sf::Vector2f(vec.arrow_x1_  * Scale + absX, 
                                -vec.arrow_y1_ * Scale + absY))
    };
    window_->draw(rightLine, 2, sf::Lines);
    
    sf::Vertex leftLine[] =
    {
        sf::Vertex(sf::Vector2f(absX, absY)),
        sf::Vertex(sf::Vector2f(vec.arrow_x2_  * Scale + absX,
                                -vec.arrow_y2_ * Scale + absY))
    };
    window_->draw(leftLine, 2, sf::Lines);
}