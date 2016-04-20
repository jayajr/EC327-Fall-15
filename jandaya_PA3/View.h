//
// Created by Jerome on 11/19/2015.
//

#ifndef Q1_VIEW_H
#define Q1_VIEW_H


#include "CartPoint.h"
#include "GameObject.h"

class View
{
private:
    const static int view_maxsize = 20;
    int size;
    double scale;
    CartPoint origin;
    char grid[view_maxsize][view_maxsize][2];
    bool get_subscripts(int&, int&, CartPoint);

public:
    View();
    ~View();

    void clear();
    void plot(GameObject*);
    void draw();
};


#endif //Q1_VIEW_H
