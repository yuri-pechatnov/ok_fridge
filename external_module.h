#pragma once

#include "types_as_in_uml.h"
#include "fwd.h"

#include <memory>

class ExternalModule {
public:
    virtual ~ExternalModule() = default;
    virtual void receiveMessage(string message) = 0;
};

typedef std::shared_ptr<ExternalModule> ExternalModulePtr;
typedef std::vector<ExternalModulePtr> ExternalModuleList;
