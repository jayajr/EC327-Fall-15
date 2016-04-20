//
// Created by Jerome on 11/9/2015.
//

#include <iostream>
#include "GameObject.h"

GameObject::GameObject(char in_code, int in_id)
{
    display_code = in_code;
    id_num = in_id;
    location = CartPoint(0, 0);
    std::cout << "GameObject default constructed" << std::endl;
};

GameObject::GameObject(char in_code, int in_id, CartPoint in_loc)
{
    display_code = in_code;
    id_num = in_id;
    location = in_loc;
    std::cout << "GameObject constructed" << std::endl;
};

GameObject::~GameObject()
{
    std::cout << "GameObject destructed" << std::endl;
}

CartPoint GameObject::get_location()
{
    return location;
};

int GameObject::get_id()
{
    return id_num;
}

void GameObject::show_status()
{
    return;
}

bool GameObject::update()
{
    return false;
}

void GameObject::drawself(char* grid)
{
    grid[0] = display_code;
    grid[1] = (char)(id_num + 48);
    return;
}