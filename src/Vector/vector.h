#ifndef VECTOR_H
#define VECTOR_H

#include "../CoordSys/basis.h"
#include <SFML/Graphics.hpp>
#include <cmath>

class Vector
{
private:
    Basis basis_;
    double x_,
           y_,
           z_;
    long double length_;

public:
    Vector(double x = 0, double y = 0, double z = 0, double basis_x = 0, 
           double basis_y = 0, double basis_z = 0, double basis_scale = 0) :
           basis_(basis_x, basis_y, basis_z, basis_scale), x_(x), y_(y), z_(z), 
           length_(-1)   {}

    Vector(const Vector &&vec) : basis_(std::move(vec.basis_)), x_(vec.x_), y_(vec.y_), 
                                 z_(vec.z_), length_(vec.length_) {}
    Vector(const Vector &vec) :  basis_(vec.basis_), x_(vec.x_), y_(vec.y_), z_(vec.z_),
                                 length_(vec.length_) {}

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

    friend const Vector operator*(double coef, const Vector &vec);

    const Vector & operator=(const Vector &&vec);
    const Vector & operator=(const Vector &vec);
    const Vector operator+(const Vector &arg);
    const Vector operator-(const Vector &arg);
    const Vector operator*(double coef);
    const Vector operator-();

    explicit operator double() const { return std::sqrt(x_*x_ + y_*y_ + z_*z_); }
    void operator+=(const Vector &arg);
    void operator-=(const Vector &arg);
    void operator*=(const Vector &arg); 
};


inline const Vector & Vector::operator=(const Vector &&vec)
{
    basis_  = std::move(vec.basis_);
    x_      = vec.x_;
    y_      = vec.y_;
    z_      = vec.z_;
    length_ = vec.length_;

    return *this;
}

inline const Vector & Vector::operator=(const Vector &vec)
{
    basis_  = vec.basis_;
    x_      = vec.x_;
    y_      = vec.y_;
    z_      = vec.z_;
    length_ = vec.length_;

    return *this;
}

inline const Vector Vector::operator*(double coef)
{
    return Vector(x_ * coef, y_ * coef, z_ * coef, basis_.getX() * coef,
                  basis_.getY(), basis_.getZ(), basis_.getScale());
}

inline const Vector operator*(double coef, const Vector &vec)
{
    return Vector(vec.x_ * coef, vec.y_ * coef, vec.z_ * coef,
                  vec.basis_.getX(), vec.basis_.getY(), vec.basis_.getZ(),
                  vec.basis_.getScale());
}

inline const Vector Vector::operator+(const Vector &arg)
{
    return Vector(x_ + arg.x_, y_ + arg.y_, z_ + arg.z_,
                  basis_.getX() + arg.basis_.getX(), basis_.getY() + arg.basis_.getY(),
                  basis_.getZ() + arg.basis_.getZ(), basis_.getScale() + arg.basis_.getScale());
}

inline void Vector::operator+=(const Vector &arg)
{
    x_ += arg.x_;
    y_ += arg.y_;       // Try to get y, when It private
    z_ += arg.z_;

    length_ = -1;
}

inline const Vector Vector::operator-(const Vector &arg)
{
    return Vector(x_ - arg.x_, y_ - arg.y_, z_ - arg.z_,
                  basis_.getX() - arg.basis_.getX(), basis_.getY() - arg.basis_.getY(),
                  basis_.getZ() - arg.basis_.getZ(), basis_.getScale() - arg.basis_.getScale());
}

inline const Vector Vector::operator-()
{
    return (-1) * (*this);
}

inline void Vector::operator-=(const Vector &arg)
{
    x_ -= arg.x_;
    y_ -= arg.y_;
    z_ -= arg.z_;

    length_ = -1;
}

inline void Vector::operator*=(const Vector &arg)
{
    x_ *= arg.x_;
    y_ *= arg.y_;
    z_ *= arg.z_;

    length_ = -1;
}


#endif