//
// Created by Jerome on 11/8/2015.
//

#include <ostream>
#include <math.h>
#include "CartPoint.h"

CartPoint::CartPoint()
{
    x = 0;
    y = 0;
};

CartPoint::CartPoint(double in_x, double in_y)
{
    x = in_x;
    y = in_y;
};

double cart_distance(CartPoint p1, CartPoint p2)
{
    double differenceX = pow(p1.x - p2.x, 2);
    double differenceY = pow(p1.y - p2.y, 2);

    return sqrt(differenceX + differenceY);
};

bool cart_compare(CartPoint p1, CartPoint p2)
{
    return p1.x == p2.x && p1.y == p2.y;
};

std::ostream& operator<<(std::ostream& os, CartPoint p1)
{
    os << "(" << p1.x << ", " << p1.y << ")";
}

CartPoint operator+(CartPoint p1, CartVector v1)
{
    double new_x = p1.x + v1.x;
    double new_y = p1.y + v1.y;
    return CartPoint(new_x, new_y);
};

CartVector operator-(CartPoint p1, CartPoint p2)
{
    double new_x = p1.x - p2.x;
    double new_y = p1.y - p2.y;
    return CartVector(new_x, new_y);
};
