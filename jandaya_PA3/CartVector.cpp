//
// Created by Jerome on 11/8/2015.
//

#include <iostream>
#include "CartVector.h"

CartVector::CartVector()
{
    x = 0;
    y = 0;
};

CartVector::CartVector(double in_x, double in_y)
{
    x = in_x;
    y = in_y;
};

std::ostream& operator<<(std::ostream& os, CartVector v1)
{
    os << "<" << v1.x << ", " << v1.y << ">";
};

CartVector operator*(CartVector v1, double d)
{
    double new_x = v1.x * d;
    double new_y = v1.y * d;
    return CartVector(new_x, new_y);
};

CartVector operator/(CartVector v1, double d)
{
    if (d == 0)
        return v1;

    double new_x = v1.x / d;
    double new_y = v1.y / d;
    return CartVector(new_x, new_y);
};