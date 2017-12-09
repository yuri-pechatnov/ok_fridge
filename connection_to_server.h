#pragma once

#include "product.h"

#include "types_as_in_uml.h"
#include "fwd.h"

class ConnectionToServer {
public:
    ConnectionToServer(Model& model);
    ProductList recognizeProducts(void* rawData);
    string getSuggestionsOfRecipes(ProductList products);
public:
    Model& model;
};

typedef std::shared_ptr<ConnectionToServer> ConnectionToServerPtr;
