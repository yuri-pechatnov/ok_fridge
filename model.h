#pragma once

#include "fridge.h"
#include "bringing_module.h"
#include "connection_to_server.h"
#include "io_controller.h"
#include "external_module.h"

class Model {
public:
    Model();
    void processMessageFromIOController(string message);
    void processMessageFromBringingModule(string message);
    void processMessageFromFridge(string message);
    void processMessageFromExternalModule(string message);
    void loop();
public:
    Fridge fridge;
    BringingModulePtr module;
    ConnectionToServerPtr connectionToServer;
    IOControllerList ioControllers;
    ExternalModuleList externalModules;
};
