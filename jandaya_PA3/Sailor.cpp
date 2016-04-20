//
// Created by Jerome on 11/13/2015.
//

#include <iostream>
#include <math.h>
#include "Sailor.h"
Sailor::Sailor() : GameObject('S', id_num)
{
    state = 'h';
    health = 25;
    size = 15;
    hold = 100;
    cargo = 0;
    destination = CartPoint(0,0);
    delta = CartVector(size - cargo * 0.1, size - cargo * 0.1);
    port = NULL;
    dock = NULL;
    hideout = NULL;
    new_size = size;
    std::cout<<"Sailor default constructed" <<std::endl;
}

Sailor::Sailor(int in_id, Dock* hideout) : GameObject('S', in_id, hideout -> get_location())
{
    state = 'h';
    health = 25;
    size = 15;
    hold = 100;
    cargo = 0;
    destination = hideout -> get_location();
    delta = CartVector(0,0);
    port = NULL;
    new_size = size;
    dock = hideout;
    this -> hideout = hideout;

    std::cout<<"Sailor constructed" <<std::endl;
}

Sailor::~Sailor()
{
    std::cout << "Sailor destructed." << std::endl;
}

bool Sailor::update_location()
{
    if (get_speed() >= fabs(cart_distance(destination, location)))
    {
        location = destination;
        std::cout << display_code << id_num << ": I'm there!" << std::endl;
        state = 'a';
        return true;
    }
    else
    {
        location = location + delta;

        std::cout << display_code << id_num << ": Just keep sailing..." << std::endl;
        return false;
    }
}

void Sailor::setup_destination(CartPoint destiny)
{
    destination = destiny;
    delta = (destination - location) * (get_speed()/cart_distance(destination, location));
}

bool Sailor::update()
{
    if (state == 's')
    {
        if(update_location())
            return true;
    }

    else if (state == 'o')
    {
        if (update_location())
        {
            state = 'l';
            std::cout <<display_code <<id_num <<": Starting to supply at a port"
                      <<std:: endl;
            return true;
        }
    }

    else if (state == 'h')
    {
        if (update_location())
        {
            dock = hideout;
            state = 'a';
            return true;
        }
    }

    else if (state == 'i')
    {
        if (update_location())
        {
            std::cout << display_code <<id_num <<": Starting to unload at a dock" << std::endl;
            state = 'u';
            return true;
        }
    }

    else if (state == 'l')
    {
        if (cargo == hold)
        {
            std::cout << display_code <<id_num <<": My boat is filled up. Send me to a Dock to unload. Dropping anchor" << std::endl;
            state = 'a';
            return true;
        }

        if (!port->is_empty())
        {
            if (hold - cargo >= 50)
                cargo += port -> provide_supplies();

            else
            {
                cargo = hold;
                port->provide_supplies();
            }

            std::cout <<display_code <<id_num <<": My new cargo is " << get_cargo()
            <<std:: endl;
            return false;
        }
        else
        {
            std::cout << display_code << id_num << ": This Port has no more supplies for me. Dropping anchor" <<
            std::endl;
            state = 'a';
            return true;
        }
    }

    else if (state == 'u')
    {
        state = 'd';

        if(dock -> dock_boat(this))
        {
            std::cout << display_code << id_num << ": I am unloading at the dock" << std::endl;
            if (cargo != 0) {
                cargo = 0;
                hold += 20;
                new_size += 5;
            }
                return true;
        }

        else
        {
            state = 't';
            std::cout << display_code << id_num <<": Help! My dock is full" << std::endl;
            return false;
        }
    }

    return false;
}

double Sailor::get_size()
{
    return size;
}

double Sailor::get_cargo()
{
    return cargo;
}

void Sailor::start_sailing(CartPoint destiny)
{
    if (state == 'd')
    {
        this -> dock -> set_sail(this);
        set_new_size();
    }
    setup_destination(destiny);

    state = 's';
    std::cout << "Sailing " << id_num <<" to " << destination << std::endl
              << display_code << id_num <<": On my way" <<std::endl;
}

void Sailor::start_supplying(Port* destPort)
{
    if (state == 'd')
    {
        this -> dock -> set_sail(this);
        set_new_size();
    }

    port = destPort;
    setup_destination(destPort->get_location());
    state = 'o';
    std::cout <<"Sailor " << id_num << " supplying at Port " << port -> id_num
              <<" and going to Port " << destPort -> id_num << std::endl;

    std::cout <<display_code << id_num << ": Supplies here I come!" << std::endl;
}

void Sailor::start_hiding()
{
    if (state == 'd')
    {
        this -> dock -> set_sail(this);
        set_new_size();
    }

    setup_destination(hideout -> get_location());
    state = 'h';
    std::cout <<"Sailor " <<id_num <<" hiding" << std::endl
              <<display_code <<id_num <<": Off to hide" << std::endl;
}

bool Sailor::is_hidden()
{
    return cart_compare(location, hideout -> get_location());
}

void Sailor::start_docking(Dock* destDock)
{
    if (state == 'd')
    {
        this -> dock -> set_sail(this);
        set_new_size();
    }

    dock = destDock;
    setup_destination(dock -> get_location());

    state = 'i';
    std::cout <<"Sailor " << id_num <<" sailing to Dock " << dock -> id_num <<std::endl
              <<display_code <<id_num <<": Off to Dock" <<std::endl;
}

void Sailor::anchor()
{
    setup_destination(location);
    state = 'a';

    std::cout <<"Stopping " <<id_num <<std::endl
              <<display_code <<id_num <<": Dropping anchor" <<std::endl;
}

void Sailor::show_status()
{
    switch(state)
    {
        case 'a':
            if (cart_compare(location, hideout -> get_location()))
                std::cout << "Sailor status: " << display_code << " with ID " << id_num
                          << " at location " << location << " is anchored (and hiding). Has a size of: " << size << ", cargo of: "
                          << cargo << ", hold of: " << hold << ", and health of: " << health
                          << std::endl;
            else
                std::cout << "Sailor status: " << display_code << " with ID " << id_num
                          << " at location " << location << " is anchored. Has a size of: " << size << ", cargo of: "
                          << cargo << ", hold of: " << hold << ", and health of: " << health
                          << std::endl;
            break;

        case 's':
            std::cout << "Sailor status: " << display_code << " with ID " << id_num
                      << " at location " << location<< " Has a speed of: " << get_speed() << " and is heading to: " << destination
                      << std::endl;
            break;

        case 'o':
            std::cout << "Sailor status: " << display_code << " with ID " << id_num
                      << " at location " << location<< " is outbound to Port: " << port -> get_id() << " with a speed of " << get_speed()
                      << std::endl;
            break;

        case 'i':
            std::cout << "Sailor status: " << display_code << " with ID " << id_num
                      << " at location " << location << " is inbound to Dock: " << dock -> get_id() << " with a speed of " << get_speed()
                      << std::endl;
            break;

        case 'h':
            std::cout << "Sailor status: " << display_code << " with ID " << id_num
                      << " at location " << location << " is going to hide at Dock " << dock -> get_id()
                      << std::endl;
            break;

        case 'l':
            if (cargo != hold)
            {
                if (port->is_empty())
                {
                    std::cout << "Sailor status: " << display_code << " with ID " << id_num
                              << " at location " << location << " is at an empty dock. Dropping anchor"
                              << std:: endl;
                }
                else
                {
                    std::cout << "Sailor status: " << display_code << " with ID " << id_num
                              << " at location " << location <<" is supplying at Port " << port -> get_id()
                              << std::endl;
                }
            }

            if (cargo == hold)
            {
                std::cout << "Sailor status: " << display_code << " with ID " << id_num
                          << " at location " << location << " is supplying at Port " << port -> get_id()
                          << std::endl;
            }

            break;

        case 'u':
            std::cout << "Sailor status: " << display_code << " with ID " << id_num
                      << " at location " << location << " is unloading at Dock " << dock -> get_id()
                      << std::endl;
            break;

        case 'd':
            std::cout << "Sailor status: " << display_code << " with ID " << id_num
                      << " at location " << location << " is docked at Dock " << dock -> get_id()
                      << std::endl;
            break;
        case 't':
            std::cout << "Sailor status: " << display_code << " with ID " << id_num
                      << " at location " << location << " is in trouble " << id_num
                      << std::endl;
            break;
        default:
            break;
    }
}

double Sailor::get_speed()
{
    double speed = size - (get_cargo() * 0.1);
    return speed;
}


void Sailor::set_new_size()
{
    size = new_size;
}