//
// Created by Jerome on 11/9/2015.
//

#include <iostream>
#include "GameObject.h"
#include "Port.h"

Port::Port() : GameObject('P', id_num)
{
    state = 'f';
    inventory = 500;
    std::cout << "Port default constructed" << std::endl;
};

Port::Port(int in_id, CartPoint in_loc) : GameObject('P', in_id, in_loc)
{
    state = 'f';
    inventory = 500;
    std::cout << "Port constructed" << std::endl;
};

Port::~Port()
{
    std::cout << "Port destructed." << std::endl;
}

bool Port::is_empty()
{
    return (inventory == 0 || state == 'e');

}

double Port::provide_supplies(double amount_to_provide)
{
    if (inventory >= amount_to_provide)
        inventory -= amount_to_provide;
    else
    {
        double temp = inventory;
        inventory = 0;
        return temp;
    }
    return amount_to_provide;
}

bool Port::update()
{
    if (inventory == 0 && state != 'e')
    {
        state = 'e';
        display_code = 'p';
        std::cout << "Port " << id_num << " has been depleted of supplies" << std::endl;
        return true;
    }

    return false;
}

void Port::show_status()
{
    std::cout << "Port Status: " << display_code << " with ID " << id_num << " at location "
              << location <<" containing supplies " << inventory << std::endl;
}