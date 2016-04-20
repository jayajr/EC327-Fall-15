//
// Created by Jerome on 11/13/2015.
//

#ifndef Q1_SAILOR_H
#define Q1_SAILOR_H


#include "GameObject.h"
#include "Port.h"
#include "Dock.h"

class Dock;

class Sailor : public GameObject
{
private:
    double health;
    double size;
    double hold;
    double cargo;
    double new_size;
    CartPoint destination;
    CartVector delta;
    Port* port;
    Dock* dock;
    Dock* hideout;

    bool update_location();
    void setup_destination(CartPoint);

public:
    Sailor();
    Sailor(int, Dock*);
    ~Sailor();

    bool update();
    double get_size();
    double get_cargo();
    void start_sailing(CartPoint);
    void start_supplying(Port*);
    void start_hiding();
    bool is_hidden();
    void start_docking(Dock*);
    void anchor();
    void show_status();
    double get_speed();
    void set_new_size();
};


#endif //Q1_SAILOR_H
