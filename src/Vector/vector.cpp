#include <utility>
#include "vector.h"
#include <cmath>

inline double Vector::setX(double x)
{
    double temp = x_;
    x_ = x;
    length_ = -1;

    return temp;
}

inline double Vector::setY(double y)
{
    double temp = y_;
    y_ = y;
    length_ = -1;
    
    return temp;
}

inline double Vector::setZ(double z)
{
    double temp = z_;
    z_ = z;
    length_ = -1;
    
    return temp;
}

void Vector::draw(sf::RenderWindow & window) const
{
    sf::Vertex line[] = 
    {
        sf::Vertex(sf::Vector2f(basis_.getX(), basis_.getY())),
        sf::Vertex(sf::Vector2f(getAbsX(), getAbsY()))
    };

    window.draw(line, 2, sf::Lines);

    sf::CircleShape circle(10.);
    sf::Vector2f pos(getAbsX(), getAbsY());
    circle.setPosition(pos);
    
    window.draw(circle);
}

void Vector::rotate(double angle)
{
    double sin = std::sin(angle),
           cos = std::cos(angle);
    
    x_ = x_ * cos - y_ * sin;
    y_ = x_ * sin + y_ * cos;
    // OZ меня не е6ет

    

    length_ = -1;

    return;
}
    
