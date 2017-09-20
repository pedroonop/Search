#include "action.h"

Action::Action(){

}

Action::Action(City from, City to, int cost){
    this->from = from;
    this->to = to;
    this->cost = cost;
}
