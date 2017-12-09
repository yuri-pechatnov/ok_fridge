#pragma once

#include "types_as_in_uml.h"
#include <memory>

class IOController {
public:
    virtual ~IOController() = default;
    virtual void output(string message) = 0;
    virtual void processInput() = 0;
};

typedef std::shared_ptr<IOController> IOControllerPtr;
typedef std::vector<IOControllerPtr> IOControllerList;
