//
// Created by Jerome on 11/9/2015.
//

#ifndef Q1_PORT_H
#define Q1_PORT_H


#include "GameObject.h"

class Port : public GameObject
{
private:
    double inventory;

public:
    Port();
    Port(int, CartPoint);
    ~Port();

    bool is_empty();
    double provide_supplies(double amount_to_provide = 50.0);
    bool update();
    void show_status();
};


#endif //Q1_PORT_H
