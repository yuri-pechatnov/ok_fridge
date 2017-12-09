#include "bringing_module.h"

#include "model.h"

#include <algorithm>

BringingModule::BringingModule(Model& model)
    : model(model)
{
}

void BringingModule::fetchFood(string foodName, string userName) {
    auto products = model.fridge.getProducts(foodName);
    if (products.size() == 0) {
        throw std::runtime_error("no such product in fridge");
    }
    product = products[0];

    ejectProductFromFridge(product);

    deliverProductToUser(userName);
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
