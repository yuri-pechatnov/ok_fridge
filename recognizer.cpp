#include "recognizer.h"

#include "model.h"


Recognizer::Recognizer(Fridge& fridge)
    : fridge(fridge)
{
}

void Recognizer::updateProductList() {
    if (void* rawData = getRawData()) {
        if (false) {
            // case, when local recognition is implemented
        }
        else {
            askFromServer(rawData);
        }
    } else {
        // we have no camera, so list is static
        static bool first = true;
        if (!first) {
            return;
        }
        fridge.products.clear();
        fridge.products.emplace_back(new Product{.name = "milk", .amount = 3, .shelfLife = 12345671234, .owner = "Peter"});
        first = false;
    }

}

void* Recognizer::getRawData() {
    // we have no camera, so no data
    return nullptr;
}

void Recognizer::askFromServer(void* rawData) {
    if (fridge.model.connectionToServer) {
        fridge.products = fridge.model.connectionToServer->recognizeProducts(rawData);
    }
}
