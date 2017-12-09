#pragma once

#include "types_as_in_uml.h"
#include "io_controller.h"

class WebIOController : public IOController {
public:
    void output(string message) override;
    void processInput() override;
};
