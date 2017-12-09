#include "model.h"
#include "verbal_io_controller.h"

#include <cstdio>
#include <cstdlib>
#include <algorithm>


int main() {
    Model model;
    model.ioControllers.emplace_back(new VerbalIOController(model));
    model.fridge.onDoorClose();
    return 0;
}
