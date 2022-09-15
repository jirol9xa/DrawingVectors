#include <utility>
#include <cmath>
#include <iostream>
#include "vector.h"

double Vector::setX(double x)
{
    double temp = x_;
    x_ = x;
    length_ = -1;

    return temp;
}

double Vector::setY(double y)
{
    double temp = y_;
    y_ = y;
    length_ = -1;
    
    return temp;
}

double Vector::setZ(double z)
{
    double temp = z_;
    z_ = z;
    length_ = -1;
    
    return temp;
}

void Vector::draw(sf::RenderWindow & window) const
{
    double X0 = basis_.getX();
    double Y0 = basis_.getY();
    double Scale = basis_.getScale();

    sf::Vertex mainLine[] = 
    {
        sf::Vertex(sf::Vector2f(basis_.getX(), basis_.getY())),
        sf::Vertex(sf::Vector2f(getAbsX(), getAbsY())),
    };
    window.draw(mainLine, 2, sf::Lines);

    sf::Vertex rightLine[] =
    {
        sf::Vertex(sf::Vector2f(getAbsX(), getAbsY())),
        sf::Vertex(sf::Vector2f((arrow_x1_ + x_) * Scale + X0, 
                                (-arrow_y1_ - y_) * Scale + Y0))
    };
    window.draw(rightLine, 2, sf::Lines);

    sf::Vertex leftLine[] =
    {
        sf::Vertex(sf::Vector2f(getAbsX(), getAbsY())),
        sf::Vertex(sf::Vector2f((arrow_x2_ + x_) * Scale + X0,
                                (-arrow_y2_ - y_) * Scale + Y0))
    };
    window.draw(leftLine, 2, sf::Lines);
}

void Vector::rotate(double angle)
{
    double sin = std::sin(angle),
           cos = std::cos(angle);
    
    double x_temp = x_, y_temp = y_;

    x_ = x_temp * cos - y_temp * sin;
    y_ = x_temp * sin + y_temp * cos;
    // OZ меня не е6ет
    length_ = -1;

    rotateArrow(sin, cos);

    return;
}
    
void Vector::rotateArrow(double sin, double cos)
{
    if (!(sin || cos))
    {
        arrow_x1_ = -0.5;
        arrow_x2_ = -0.5;

        arrow_y1_ =  0.5;
        arrow_y2_ = -0.5;

        return;
    }

    double x_temp = arrow_x1_, y_temp = arrow_y1_;

    arrow_x1_ = x_temp * cos - y_temp * sin;
    arrow_y1_ = x_temp * sin + y_temp * cos;

    x_temp = arrow_x2_, y_temp = arrow_y2_;

    arrow_x2_ = x_temp * cos - y_temp * sin;
    arrow_y2_ = x_temp * sin + y_temp * cos;

    return;
}
