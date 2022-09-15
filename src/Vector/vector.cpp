#include <utility>
#include <cmath>
#include <iostream>
#include "vector.h"

double Vector::setX(double x)
{
    double old_x = x_;
    x_ = x;
    length_ = -1;

    autoRotateArrow(old_x, y_, z_, length_);

    return old_x;
}

double Vector::setY(double y)
{
    double old_y = y_;
    y_ = y;
    length_ = -1;

    autoRotateArrow(x_, old_y, z_, length_);

    return old_y;    
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


void Vector::autoRotateArrow(double old_x, double old_y, double old_z, double old_length)
{
    if (old_length < 0) 
        old_length = std::sqrt(old_x * old_x + old_y * old_y + old_z * old_z);

    double length = length_;
    if (length < 0)
    {
        length_ = x_ * x_ + y_ * y_ + z_ * z_;
        length = std::sqrt(length_);
    }
    else
        length = std::sqrt(length_);

    double sin     = y_ / length,
           cos     = x_ / length,
           old_sin = old_y / old_length,
           old_cos = old_x / old_length;

    rotateArrow(sin * old_cos - old_sin * cos, cos * old_cos + sin * old_sin);
}
