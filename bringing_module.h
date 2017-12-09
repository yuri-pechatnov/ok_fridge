#pragma once

#include "types_as_in_uml.h"
#include "fwd.h"
#include "product.h"

class BringingModule {
public:
    BringingModule(Model& model);
    void fetchFood(string foodName, string userName);
    void deliverProductToUser(string userName);
    void ejectProductFromFridge(ProductPtr product);
public:
    Model& model;
    ProductPtr product;
};


typedef std::shared_ptr<BringingModule> BringingModulePtr;
