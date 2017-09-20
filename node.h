#ifndef NODE_H
#define NODE_H

#include "city.h"
#include "action.h"
#include "state.h"

class Node
{
public:
    Node();
    bool operator==(const Node &b);
    State state;
    Node *father;
    Action action;
    int cost;
};

#endif // NODE_H
