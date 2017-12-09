#include "model.h"

Model::Model()
    : fridge(*this)
    , module(new BringingModule(*this))
    , connectionToServer(new ConnectionToServer(*this))
{
}

void Model::processMessageFromIOController(string message) {
    //TODO
}

void Model::processMessageFromBringingModule(string message) {
    // not used in prototype
}

void Model::processMessageFromFridge(string message) {
    // not used in prototype
}

void Model::processMessageFromExternalModule(string message) {
    // not used in prototype
}
