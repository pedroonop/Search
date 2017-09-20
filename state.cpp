#include "state.h"

State::State()
{

}

bool State::operator==(const State &b){
    return this->city == b.city;
}
