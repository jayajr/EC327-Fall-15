//
// Created by Jerome on 11/13/2015.
//

#include <iostream>
#include "Dock.h"
#include "Sailor.h"

Dock::Dock() : GameObject('d', id_num)
{
    berth = 30;
    state = 'u';
    std::cout << "Dock default constructed" << std::endl;
};

Dock::Dock(int in_id, CartPoint in_loc) : GameObject('d', in_id, in_loc)
{
    berth = 30;
    state = 'u';
    std::cout << "Dock constructed" << std::endl;
}

Dock::~Dock()
{
    std::cout << "Dock destructed." << std::endl;
}

bool Dock::dock_boat(Sailor* sailor_to_dock)
{
    if (berth >= sailor_to_dock -> get_size())
    {
        berth -= sailor_to_dock -> get_size();
        return true;
    }

    else return false;
}

bool Dock::set_sail(Sailor* sailor_to_sail)
{
    if (sailor_to_sail -> get_cargo() == 0)
    {
        berth += sailor_to_sail -> get_size();
        return true;
    }

    std::cout <<display_code <<id_num <<"Did not set sail";
    return false;
}

bool Dock::update()
{
    if(berth == 0 && state != 'p')
    {
        state = 'p';
        display_code = 'D';
        std::cout << "Dock " << id_num << " is packed" << std::endl;
        return true;
    }

    if ((berth > 0 && berth < 30) && state == 'p')
    {
        state = 'u';
        display_code = 'd';
        return true;
    }

    return false;
}

void Dock::show_status()
{
    std::cout << "Dock Status: " << display_code << " with ID " << id_num
              << " at location " << location << " has " << berth << " berths"
              << std::endl;
}