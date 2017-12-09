#pragma once

class ConnectionToServer {
public:
    ProductList recognizeProducts(void* rawData);
    string getSuggestionOfRecipes(ProductList products);
};

typedef std::shared_ptr<ConnectionToServer> ConnectionToServerPtr;
