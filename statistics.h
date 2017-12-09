#pragma once

#include "types_as_in_uml.h"
#include "fwd.h"

class Statistics {
public:
    integer getFullness();
    Statistics(Fridge& fridge);
private:
    Fridge& fridge;
};
