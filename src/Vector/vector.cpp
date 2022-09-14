#include <utility>
#include "vector.h"

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

