#include "model.h"

#include "json/src/json.hpp"

#include <iostream>

using json = nlohmann::json;

Model::Model()
    : fridge(*this)
    , module(new BringingModule(*this))
    , connectionToServer(new ConnectionToServer(*this))
{
}

void Model::processMessageFromIOController(string jsonText) {
    std::cerr << "Model::processMessageFromIOController(" << jsonText << ")" << std::endl;
    auto j = json::parse(jsonText);
    string source = j["source"];
    auto message = j["message"];
    string type = message["type"];

    if (type == "fetch") {
        string productName = message["productName"];
        string userName = message["userName"];
        module->fetchFood(productName, userName);
    } else {
        // ...
    }
}

void Model::processMessageFromBringingModule(string jsonText) {
    std::cerr << "Model::processMessageFromBringingModule(" << jsonText << ")" << std::endl;
    auto j = json::parse(jsonText);
    string source = j["source"];
    auto message = j["message"];
    string type = message["type"];

    if (type == "output") {
        string text = message["text"];
        for (auto io : ioControllers) {
            io->output(text);
        }
    } else {
        // ...
    }
}

void Model::processMessageFromFridge(string message) {
    // not used in prototype
}

void Model::processMessageFromExternalModule(string message) {
    // not used in prototype
}


void Model::loop() {
    for (auto io : ioControllers) {
        io->processInput();
    }
}
