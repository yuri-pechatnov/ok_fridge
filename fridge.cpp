#include "fridge.h"

#include "model.h"

Fridge::Fridge(Model& model)
    : model(model)
    , statistics(*this)
    , recognizer(*this)
{
}

string Fridge::getSuggestionsOfRecipes() {
    // local mock of suggesting recipes
    {
        auto milkProducts = getProducts("milk");
        if (milkProducts.size() > 0) {
            return "Leave it in fridge. And after a week you will get clabber.";
        }
    }

    if (model.connectionToServer) {
        return model.connectionToServer->getSuggestionsOfRecipes(products);
    }

    return "";
}

ProductList Fridge::getProducts(string name) {
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

