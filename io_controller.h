#pragma once

#include "types_as_in_uml.h"
#include <memory>

class IOController {
public:
    virtual ~IOController();
    virtual void output(string message);
};

typedef std::shared_ptr<IOController> IOControllerPtr;
typedef std::vector<IOControllerPtr> IOControllerList;
