#ifndef VECTOR_H
#define VECTOR_H

#include "basis.h"
#include <SFML/Graphics.hpp>
#include <cmath>

class Vector
{
private:
    double x_,
           y_,
           z_;
    long double length_;

public:
    double arrow_x1_,
           arrow_y1_,
           arrow_x2_,
           arrow_y2_;

    Vector(double x = 0, double y = 0, double z = 0) : 
           x_(x), y_(y), z_(z), length_(-1), arrow_x1_(0), 
           arrow_y1_(0), arrow_x2_(0), arrow_y2_(0)  
    {        
        length_ = x_ * x_ + y_ * y_ + z_ * z_;
        double length = std::sqrt(length_);

        arrow_x1_ = arrow_x2_ = -0.5;
        arrow_y1_ = 0.5, arrow_y2_ = -0.5;

        rotateArrow(y_ / length, x_ / length);
    }

    Vector(const Vector &&vec) : x_(vec.x_), y_(vec.y_), z_(vec.z_), length_(vec.length_), 
                                 arrow_x1_(vec.arrow_x1_), arrow_x2_(vec.arrow_x2_), 
                                 arrow_y1_(vec.arrow_y1_), arrow_y2_(vec.arrow_y2_) {}
    Vector(const Vector &vec) :  x_(vec.x_), y_(vec.y_), z_(vec.z_), length_(vec.length_),
                                 arrow_x1_(vec.arrow_x1_), arrow_x2_(vec.arrow_x2_), 
                                 arrow_y1_(vec.arrow_y1_), arrow_y2_(vec.arrow_y2_) {}

    double getX() const { return x_; }
    double getY() const { return y_; }
    double getZ() const { return z_; }

    double setX(double x);
    double setY(double y);
    double setZ(double z);

    double getLen() 
    {
        if (length_ < 0)
            length_ = x_*x_ + y_*y_ + z_*z_;

        return length_;
    }

    void rotate(double angle);
    void rotateArrow(double sin = 0, double cos = 0);

    friend const Vector operator*(double coef, const Vector &vec);

    const Vector & operator=(const Vector &&vec);
    const Vector & operator=(const Vector &vec);
    const Vector   operator+(const Vector &vec);
    const Vector   operator-(const Vector &vec);
    const Vector   operator*(double coef);
    const Vector   operator-();

    double operator*(const Vector &arg);

    explicit operator double() const { return std::sqrt(x_*x_ + y_*y_ + z_*z_); }
    void operator+=(const Vector &arg);
    void operator-=(const Vector &arg);
    void operator*=(double coef); 

private:
    void autoRotateArrow(double old_x, double old_y, double old_z, double old_length);
};


inline const Vector & Vector::operator=(const Vector &&vec)
{
    x_      = vec.x_;
    y_      = vec.y_;
    z_      = vec.z_;
    length_ = vec.length_;

    arrow_x1_ = vec.arrow_x1_;
    arrow_x2_ = vec.arrow_x2_;
    arrow_y1_ = vec.arrow_y1_;
    arrow_y2_ = vec.arrow_y2_;

    return *this;
}

inline const Vector & Vector::operator=(const Vector &vec)
{
    x_      = vec.x_;
    y_      = vec.y_;
    z_      = vec.z_;
    length_ = vec.length_;

    arrow_x1_ = vec.arrow_x1_;
    arrow_x2_ = vec.arrow_x2_;
    arrow_y1_ = vec.arrow_y1_;
    arrow_y2_ = vec.arrow_y2_;

    return *this;
}

inline const Vector Vector::operator*(double coef)
{
    return Vector(x_ * coef, y_ * coef, z_ * coef);
}

inline double Vector::operator*(const Vector &vec)
{
    return (x_ * vec.x_ + y_ * vec.y_ + z_ * vec.z_);
}


inline const Vector operator*(double coef, const Vector &vec)
{
    return Vector(vec.x_ * coef, vec.y_ * coef, vec.z_ * coef);
}

inline const Vector Vector::operator+(const Vector &arg)
{
    return Vector(x_ + arg.x_, y_ + arg.y_, z_ + arg.z_);
}

inline void Vector::operator+=(const Vector &arg)
{
    double old_x = x_,
           old_y = y_,
           old_z = z_;

    x_ += arg.x_;
    y_ += arg.y_;
    z_ += arg.z_;

    length_ = -1;

    autoRotateArrow(old_x, old_y, old_z, length_);
}

inline const Vector Vector::operator-(const Vector &arg)
{
    return Vector(x_ - arg.x_, y_ - arg.y_, z_ - arg.z_);
}

inline const Vector Vector::operator-()
{
    return (-1) * (*this);
}

inline void Vector::operator-=(const Vector &arg)
{
    double old_x = x_,
           old_y = y_,
           old_z = z_;

    x_ += arg.x_;
    y_ += arg.y_;
    z_ += arg.z_;

    length_ = -1;

    autoRotateArrow(old_x, old_y, old_z, length_);
}

inline void Vector::operator*=(double coef)
{
    x_ *= coef;
    y_ *= coef;
    z_ *= coef;

    length_ = -1;
}

#endif