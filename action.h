#ifndef ACTION_H
#define ACTION_H

#include "city.h"

class Action
{
public:
    Action();
    Action(City from, City to, int cost);
    City from;
    City to;
    int cost;
};

#endif // ACTION_H
