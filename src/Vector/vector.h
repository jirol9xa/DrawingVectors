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

    double arrow_x1_,
           arrow_y1_,
           arrow_x2_,
           arrow_y2_;

public:
    Vector(double x = 0, double y = 0, double z = 0, double basis_x = 400, 
           double basis_y = 400, double basis_z = 0, double basis_scale = 100.0) : 
           basis_(basis_x, basis_y, basis_z, basis_scale), x_(x), y_(y), z_(z), 
           length_(-1), arrow_x1_(0), arrow_y1_(0), arrow_x2_(0), arrow_y2_(0)  
    {
        length_ = x_ * x_ + y_ * y_ + z_ * z_;
        double length = std::sqrt(length_);

        arrow_x1_ = arrow_x2_ = -0.5;
        arrow_y1_ = 0.5, arrow_y2_ = -0.5;


        rotateArrow(y_ / length, x_ / length);
    }

    Vector(const Vector &&vec) : basis_(std::move(vec.basis_)), x_(vec.x_), y_(vec.y_), 
                                 z_(vec.z_), length_(vec.length_), arrow_x1_(vec.arrow_x1_),
                                 arrow_x2_(vec.arrow_x2_), arrow_y1_(vec.arrow_y1_),
                                 arrow_y2_(vec.arrow_y2_) {}
    Vector(const Vector &vec) :  basis_(vec.basis_), x_(vec.x_), y_(vec.y_), z_(vec.z_),
                                 length_(vec.length_), arrow_x1_(vec.arrow_x1_),
                                 arrow_x2_(vec.arrow_x2_), arrow_y1_(vec.arrow_y1_),
                                 arrow_y2_(vec.arrow_y2_) {}

    double getRelativeX() const { return x_; }
    double getRelativeY() const { return y_; }
    double getRelativeZ() const { return z_; }

    double getAbsX() const { return basis_.getX() + x_ * basis_.getScale(); }
    double getAbsY() const { return basis_.getY() - y_ * basis_.getScale(); }
    double getAbsZ() const { return basis_.getZ() + z_ * basis_.getScale(); }

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

    void draw(sf::RenderWindow & window) const;

    friend const Vector operator*(double coef, const Vector &vec);

    const Vector & operator=(const Vector &&vec);
    const Vector & operator=(const Vector &vec);
    const Vector operator+(const Vector &vec);
    const Vector operator-(const Vector &vec);
    const Vector operator*(double coef);
    const Vector operator-();

    double operator*(const Vector &arg);

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

inline double Vector::operator*(const Vector &vec)
{
    return (x_ * vec.x_ + y_ * vec.y_ + z_ * vec.z_);
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
                  basis_.getX(), basis_.getY(),
                  basis_.getZ(), basis_.getScale());
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
                  basis_.getX(), basis_.getY(),
                  basis_.getZ(), basis_.getScale());
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