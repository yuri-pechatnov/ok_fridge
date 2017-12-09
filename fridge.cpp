#include "fridge.h"

#include "model.h"

Fridge::Fridge(Model& model)
    : model(model)
{
}

string Fridge::getSuggestionsOfRecipes() {

    {
        auto milkProducts = getProduct("milk");
        if (milkProducts.size() > 0) {
            return "Leave it in fridge. And after a week you will get clabber."
        }
    }

    if (model.connectionToServer) {
        return model.connectionToServer.getSuggestionsOfRecipes(products);
    }
}

ProductList Fridge::getProduct(string name) {
    ProductList list;
    for (auto product : products) {
        if (product->name == name) {
            list.push_back(product);
        }
    }
    return list;
}

void Fridge::onDoorClose() {
    recognizer.updateProductList();
}

