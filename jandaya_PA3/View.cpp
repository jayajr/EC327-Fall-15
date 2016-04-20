//
// Created by Jerome on 11/19/2015.
//

#include <iostream>
#include "View.h"

View::View()
{
    size =  11;
    scale = 2;
    origin = CartPoint(0, 0);
}

View::~View()
{
    std::cout << "View destructed." << std::endl;
}

bool View::get_subscripts(int& ix, int& iy, CartPoint location)
{
    ix = (int)((location.x - origin.x) / scale) + 1;
    iy = (int)((location.y - origin.y) / scale) + 1;

    if (ix >= 0 && iy >= 0)
        return true;
    else
        std::cout << "An object is outside the display " <<std::endl;

    return false;
}

void View::clear()
{
    for (int i = 0; i < size + 1 ; i++)
    {
        for (int j = 0; j < size + 1 ; j++)
        {
            if ((j == 0 || i == 0))
            {
                if (j == 11 || i == 11)
                {
                    grid[i][j][0] = (char)(2+48);
                    grid[i][j][1] = (char)(0+48);
                }

                else if (j == 9 || i == 9)
                {
                    grid[i][j][0] = (char)(1+48);
                    grid[i][j][1] = (char)(6+48);
                }

                else if (j == 7 || i == 7)
                {
                    grid[i][j][0] = (char)(1+48);
                    grid[i][j][1] = (char)(2+48);
                }

                else if (j == 5 || i == 5)
                {
                    grid[i][j][1] = ' ';
                    grid[i][j][0] = (char)(8+48);
                }

                else if (j == 3 || i == 3)
                {
                    grid[i][j][1] = ' ';
                    grid[i][j][0] = (char)(4+48);
                }

                else if (j == 1 || i == 1)
                {
                    grid[i][j][1] = ' ';
                    grid[i][j][0] = (char)(0+48);
                }

                else
                {
                    grid[i][j][0] = ' ';
                    grid[i][j][1] = ' ';
                }
            }
            else
            {
                grid[i][j][0] = '.';
                grid[i][j][1] = ' ';
            }
        }
    }
}

void View::plot(GameObject* ptr)
{
    int x = 0;
    int y = 0;
    if (get_subscripts(x, y, ptr -> get_location()))
    {
        if (grid[x][y][0] != '.')
        {
            grid[x][y][0] = '*';
            grid[x][y][1] = ' ';
        }
        else
            ptr->drawself(grid[x][y]);
    }
    return;
}

void View::draw()
{

    for (int i = size; i >= 0 ; i--)
    {
        for (int j = 0; j < size + 1 ; j++)
        {
            std::cout << grid[j][i][0];
            std::cout << grid[j][i][1];
        }
        std::cout << std::endl;
    }
}