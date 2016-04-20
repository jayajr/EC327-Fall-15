//
// Created by Jerome on 11/13/2015.
//

#ifndef Q1_DOCK_H
#define Q1_DOCK_H

#include "GameObject.h"
#include "Sailor.h"

class Sailor;

class Dock : public GameObject
{
private:
    double berth;

public:
    Dock();
    Dock(int, CartPoint);
    ~Dock();

    bool dock_boat(Sailor*);
    bool set_sail(Sailor*);
    bool update();
    void show_status();
};

#endif //Q1_DOCK_H
