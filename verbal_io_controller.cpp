#include "verbal_io_controller.h"

#include <cstdio>

void VerbalIOController::output(string message) {
    printf("VerbalIOController>>>>> %s\n", message.c_str());
}
