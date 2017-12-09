#pragma once

#include "io_controller.h"
#include "types_as_in_uml.h"

#include "fwd.h"

class VerbalIOController : public IOController {
public:
    VerbalIOController(Model& model);
    void output(string message) override;
    void processInput() override;
public:
    Model& model;
};
