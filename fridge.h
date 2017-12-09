#pragma once

#include "types_as_in_uml.h"
#include "product.h"
#include "statistics.h"
#include "recognizer.h"

class Fridge {
public:
    Fridge(Model& model);
    string getSuggestionsOfRecipes();
    ProductList getProduct(string name);
    void onDoorClose();
public:
    ProductList products;
    Statistics statistics;
    Recognizer recognizer;
    Model& model;
};
