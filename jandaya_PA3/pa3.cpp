#include <iostream>
#include "CartVector.h"
#include "CartPoint.h"
#include "Port.h"
#include "Dock.h"
#include "Model.h"
#include "GameCommand.h"
#include "View.h"


using namespace std;

//Checkpoint 4
int main()
{
    Model model = Model();
    View view = View();
    GameCommand game_command = GameCommand();

    game_command.do_list_command(model);
    model.display(view);

    char command;
    do
    {
        cout << "Enter command: ";
        cin >> command;
        switch(command)
        {
            case 's':
                game_command.do_sail_command(model);
                model.display(view);
                break;
            case 'g':
                game_command.do_go_command(model);
                game_command.do_list_command(model);
                model.display(view);
                break;
            case 'r':
                game_command.do_run_command(model);
                game_command.do_list_command(model);
                model.display(view);
                break;
            case 'p':
                game_command.do_port_command(model);
                model.display(view);
                break;
            case 'h':
                game_command.do_hide_command(model);
                model.display(view);
                break;
            case 'a':
                game_command.do_anchor_command(model);
                model.display(view);
                break;
            case 'l':
                game_command.do_list_command(model);
                model.display(view);
                break;
            case 'd':
                game_command.do_dock_command(model);
                model.display(view);
                break;
            default:
                break;
        }
    } while (command != 'q');

    std::cout << "Terminating Program" << std::endl;
    model.display(view);

    return 0;
}

/*
//Checkpoint 3
int main()
{
    CartPoint p1(10,20);
    CartPoint p2(11,35);
    Dock dock1(1,p1);
    Port port1(2, p2);
    Sailor sailor1(3, &dock1);

    cout << "******************" << endl;
    port1.update();
    port1.show_status();
    cout << "******************" << endl;
    dock1.update();
    dock1.show_status();
    cout << "******************" << endl;
    sailor1.update();
    sailor1.show_status();
    cout << "******************" << endl;

    CartPoint p3(11, 20);
    sailor1.start_sailing(p3);
    sailor1.update();
    sailor1.show_status();
    cout << "******************" << endl;
    sailor1.start_supplying(&port1);
    sailor1.update();
    sailor1.show_status();
    cout << "******************" << endl;
    sailor1.update();
    sailor1.show_status();
    cout << "******************" << endl;
    sailor1.update();
    sailor1.show_status();
    cout << "******************" << endl;
    sailor1.start_hiding();
    sailor1.update();
    sailor1.show_status();
    cout << "******************" << endl;
    sailor1.update();
    sailor1.show_status();
    cout << "******************" << endl;
    sailor1.start_sailing(CartPoint(30, 20));
    sailor1.update();
    sailor1.show_status();
    cout << "******************" << endl;
    sailor1.update();
    sailor1.show_status();
    cout << "******************" << endl;
    sailor1.start_docking(&dock1);
    sailor1.update();
    sailor1.show_status();
    cout << "******************" << endl;
    sailor1.update();
    sailor1.show_status();
    cout << "******************" << endl;
    sailor1.update();
    sailor1.show_status();
    cout << "******************" << endl;
    sailor1.anchor();
    sailor1.update();
    sailor1.show_status();
    cout << "******************" << endl;

    // all tests passed!
    cout << "Checkpoint3 passed!" << endl;
    return 0;
}
*/
/*
// Checkpoint 2
int main()
{
    CartPoint p1(45, 90);
    Port port1(1, p1);
    port1.update();
    port1.show_status();
    port1.provide_supplies(10);
    port1.update();
    port1.show_status();
    port1.provide_supplies(491);
    port1.update();
    port1.show_status();

    return 0;
};
*/
/*
//Checkpoint 1
int main()
{
    CartPoint p1 = CartPoint(0,0);
    if (p1.x != 0 && p1.y != 0) {
        cout << "CartPoint is not working!" << endl;
    }
    cout << p1 <<endl;
    CartVector v1 = CartVector(4, -3);
    cout << v1 << endl;
    CartPoint p2 = p1 + v1;
    cout << p2 << endl;
    p2 = p2 + v1;
    cout << p2 << endl;


    double a = 0.0;
    double b = 3.0;

    CartPoint p3 (a, b);
    CartPoint p4;

    cout << "Distance: " << cart_distance(p3, p4) <<endl;
    cout << "Compare: " << cart_compare(p3, p4) << endl;

    cout << "p4 = " <<p4 << endl;
    cout << "p3 = " <<p3 << endl;

    CartVector v2(5.0, 10.0);
    CartVector v3(15.0, 20.0);

    cout << "v2 = " << v2 << endl;
    cout << "v3 = " << v3 << endl;

    cout << "v2 * 10 = " << v2 * 10 <<endl;
    cout << "v3 / 10 = " << v3 / 10 <<endl;
    cout << "v3 /  0 = " << v3 /  0 <<endl;
    cout << "v3 / -1 = " << v3 / -1 <<endl;

    return 0;
}
*/