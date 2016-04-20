//
// Created by Jerome on 11/9/2015.
//

#ifndef Q1_GAMEOBJECT_H
#define Q1_GAMEOBJECT_H

#include "CartPoint.h"

class GameObject
{
public:
    int id_num;

protected:
    CartPoint location;
    char display_code;
    char state;

public:
    GameObject(char, int);
    GameObject(char, int, CartPoint);
    virtual ~GameObject();

    CartPoint get_location();
    int get_id();
    virtual void show_status();
    virtual bool update();
    void drawself(char*);
};

#endif //Q1_GAMEOBJECT_H
