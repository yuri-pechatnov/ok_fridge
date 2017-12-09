#include "bringing_module.h"

#include "model.h"

#include <algorithm>
#include <sstream>
#include <iostream>

BringingModule::BringingModule(Model& model)
    : model(model)
{
}

void BringingModule::fetchFood(string foodName, string userName) {
    std::cerr << "fetchFood(" << foodName << ", " << userName << ")\n";
    auto products = model.fridge.getProducts(foodName);
    if (products.size() == 0) {
        model.processMessageFromBringingModule((string)"{\"source\": \"bringing_module\", \"message\": {\"type\": \"output\", \"text\": \"No food '"
                                               + foodName + "' owned by '" + userName + "'\"}}");
        return;
    }
    product = products[0];

    ejectProductFromFridge(product);

    model.processMessageFromBringingModule((string)"{\"source\": \"bringing_module\", \"message\": {\"type\": \"output\", \"text\": \"Food '"
                                           + foodName + "' owned by '" + userName + "' has been ejected from Fridge\"}}");

    deliverProductToUser(userName);

    model.processMessageFromBringingModule((string)"{\"source\": \"bringing_module\", \"message\": {\"type\": \"output\", \"text\": \"Food '"
                                           + foodName + "' owned by '" + userName + "' has been delivered\"}}");
}


void BringingModule::deliverProductToUser(string userName) {
    // no physical module - no code
    // ...
    product.reset();
}

void BringingModule::ejectProductFromFridge(ProductPtr product) {
    auto& products = model.fridge.products;
    auto iter = std::find(products.begin(), products.end(), product);
    products.erase(iter);
    model.fridge.onDoorClose();
}
