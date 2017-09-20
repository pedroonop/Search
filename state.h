#ifndef STATE_H
#define STATE_H

#include "city.h"
#include <vector>

using namespace std;

class State
{
public:
    State();
    City city;
    bool operator==(const State &b);
};

#endif // STATE_H
