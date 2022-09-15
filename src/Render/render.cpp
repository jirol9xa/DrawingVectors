#include "render.h"

void Render::draw(double x, double y, double z, double arrow_x1, double arrow_x2,
                  double arrow_y1, double arrow_y2) const
{
    double X0    = basis_.getX(),
           Y0    = basis_.getY(),
           Scale = basis_.getScale(),
           absX  = X0 + x * Scale,
           absY  = Y0 - y * Scale;

    sf::Vertex mainLine[] = 
    {
        sf::Vertex(sf::Vector2f(X0, Y0)),
        sf::Vertex(sf::Vector2f(absX, absY)),
    };
    window_->draw(mainLine, 2, sf::Lines);
    
    sf::Vertex rightLine[] =
    {
        sf::Vertex(sf::Vector2f(absX, absY)),
        sf::Vertex(sf::Vector2f(arrow_x1  * Scale + absX, 
                                -arrow_y1 * Scale + absY))
    };
    window_->draw(rightLine, 2, sf::Lines);
    
    sf::Vertex leftLine[] =
    {
        sf::Vertex(sf::Vector2f(absX, absY)),
        sf::Vertex(sf::Vector2f(arrow_x2  * Scale + absX,
                                -arrow_y2 * Scale + absY))
    };
    window_->draw(leftLine, 2, sf::Lines);
}