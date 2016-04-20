//
// Created by Jerome on 11/8/2015.
//

#ifndef Q1_CARTPOINT_H
#define Q1_CARTPOINT_H

#include <ostream>
#include "CartVector.h"

class CartPoint
{
    public:
    double x, y;

    CartPoint();
    CartPoint(double, double);
};

double cart_distance(CartPoint, CartPoint);
bool cart_compare(CartPoint, CartPoint);

std::ostream& operator<<(std::ostream&, CartPoint);
CartPoint operator+(CartPoint, CartVector);
CartVector operator-(CartPoint, CartPoint);

#endif //Q1_CARTPOINT_H
