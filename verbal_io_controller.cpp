#include "verbal_io_controller.h"

#include "model.h"

#include <cstdio>

#define OUTPUT_BEGIN "\x1b[1;32m"
#define OUTPUT_END "\x1b[0m"

VerbalIOController::VerbalIOController(Model& model)
    : model(model)
{
}

void VerbalIOController::processInput() {
    char buff[1024];
    char* ret = fgets(buff, sizeof(buff), stdin);
    if (!ret) {
        return;
    }
    string s(buff);
    s.pop_back();
    model.processMessageFromIOController(string("{\"message\":") + s + ", \"source\": \"verbal\"}");
}

void VerbalIOController::output(string message) {
    printf(OUTPUT_BEGIN "VerbalIOController>>>>> %s" OUTPUT_END "\n", message.c_str());
}
