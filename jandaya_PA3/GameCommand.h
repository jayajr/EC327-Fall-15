//
// Created by Jerome on 11/19/2015.
//

#ifndef Q1_GAMECOMMAND_H
#define Q1_GAMECOMMAND_H


#include "Model.h"

class GameCommand
{
public:
    double arg1, arg2, arg3;
    void do_sail_command(Model&);
    void do_go_command(Model&);
    void do_run_command(Model&);
    void do_port_command(Model&);
    void do_hide_command(Model&);
    void do_anchor_command(Model&);
    void do_list_command(Model&);
    void do_dock_command(Model&);
};


#endif //Q1_GAMECOMMAND_H
