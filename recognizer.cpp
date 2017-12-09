#include "recognizer.h"

#include "model.h"


Recognizer::Recognizer(Fridge& fridge)
    : fridge(fridge)
{
}

void Recognizer::updateProductList() {
    // we have no camera, so list is static
    void* rawData = getRawData();
    if (rawData) {
        throw std::runtime_error("not implemented");
    } else {
        fridge.products.clear();
        fridge.products.emplace_back(new Product{.name = "milk", .amount = 3, .shelfLife = 12345671234, .owner = "Peter"});
    }

}

void* Recognizer::getRawData() {
    // we have no camera, so no data
    return nullptr;
}

void Recognizer::askFromServer() {
    if (fridge.model.connectionToServer) {
        fridge.products = fridge.model.connectionToServer->recognizeProducts(getRawData());
    }
}
