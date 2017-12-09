#pragma once

#include "types_as_in_uml.h"
#include "fwd.h"

class Recognizer {
public:
    Recognizer(Fridge& fridge);
    void updateProductList();
private:
    void* getRawData();
    bool tryToRecognize();
    void askFromServer();

private:
    Fridge& fridge;
};
