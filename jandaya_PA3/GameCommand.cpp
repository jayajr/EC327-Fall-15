//
// Created by Jerome on 11/19/2015.
//

#include <iostream>
#include "GameCommand.h"

using namespace std;

void GameCommand::do_sail_command(Model& model)
{
    cin >> arg1 >> arg2 >> arg3;
    Sailor* sailor = model.get_Sailor_ptr(arg1);

    sailor->start_sailing(CartPoint(arg2, arg3));
}
void GameCommand::do_go_command(Model& model)
{
    std::cout << "Advancing time one tick" <<std::endl;
    model.update();
}

void GameCommand::do_run_command(Model& model)
{
    std::cout << "Advancing to next event or 5 ticks" <<std::endl;
    for (int i = 0 ; i < 5 ; i++)
    {
        if(model.update())
            break;
    }
}

void GameCommand::do_port_command(Model& model)
{
    cin >> arg1 >> arg2;
    Sailor* sailor = model.get_Sailor_ptr(arg1);
    Port* port = model.get_Port_ptr(arg2);

    sailor -> start_supplying(port);
}

void GameCommand::do_hide_command(Model& model)
{
    cin >> arg1;
    Sailor* sailor = model.get_Sailor_ptr(arg1);

    sailor->start_hiding();
}

void GameCommand::do_anchor_command(Model& model)
{
    cin >> arg1;
    Sailor* sailor = model.get_Sailor_ptr(arg1);

    sailor -> anchor();
}

void GameCommand::do_list_command(Model& model)
{
    model.show_status();
}

void GameCommand::do_dock_command(Model& model)
{
    cin >> arg1 >> arg2;
    Sailor* sailor = model.get_Sailor_ptr(arg1);
    Dock* dock = model.get_Dock_ptr(arg2);

    sailor->start_docking(dock);
}
