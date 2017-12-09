#pragma once

#include "io_controller.h"
#include "types_as_in_uml.h"

class VerbalIOController : public IOController {
public:
    void output(string message) override;
};
