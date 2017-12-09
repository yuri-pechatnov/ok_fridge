#include "connection_to_server.h"

#include "model.h"

ConnectionToServer::ConnectionToServer(Model& model)
    : model(model)
{
}

ProductList ConnectionToServer::recognizeProducts(void* rawData) {
    return ProductList();
}

string ConnectionToServer::getSuggestionsOfRecipes(ProductList products) {
    return "mock recipe from server";
}

