//
// Created by Jerome on 11/8/2015.
//

#ifndef Q1_CARTVECTOR_H
#define Q1_CARTVECTOR_H

class CartVector
{
    public:
    double x, y;

    CartVector();
    CartVector(double, double);
};

std::ostream& operator<<(std::ostream&, CartVector);
CartVector operator*(CartVector, double);
CartVector operator/(CartVector, double);

#endif //Q1_CARTVECTOR_H
