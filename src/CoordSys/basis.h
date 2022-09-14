#ifndef BASIS_H
#define BASIS_H

class Basis 
{
private:
    double x_, y_, z_, scale_;
public:
    Basis(double x = 400, double y = 300, double z = 0, double scale = 10.0) :
        x_(x), y_(y), z_(z), scale_(scale) {}
    Basis(const Basis &&basis) : x_(basis.x_), y_(basis.y_), z_(basis.z_), 
                           scale_(basis.scale_) {}
    Basis(const Basis &basis) : x_(basis.x_), y_(basis.y_), z_(basis.z_), 
                           scale_(basis.scale_) {}
    
    double getX() const { return x_; }
    double getY() const { return y_; }
    double getZ() const { return z_; }
    double getScale() const { return scale_; }

    double setScale(double scale)
    {
        double temp = scale_;
        scale_ = scale;

        return temp;
    }

    const Basis & operator=(const Basis & basis)
    {
        x_ = basis.getX();
        y_ = basis.getY();
        z_ = basis.getZ();
        
        scale_ = basis.getScale();

        return *this;
    }

    const Basis & operator=(Basis &&basis)
    {
        x_ = basis.x_;
        y_ = basis.y_;
        z_ = basis.z_;
        scale_ = basis.scale_;

        return *this;
    }
};

#endif