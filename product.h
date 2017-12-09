#pragma once

#include "types_as_in_uml.h"

#include <memory>

struct Product {
    string name;
    float amount;
    time_t shelfLife;
    string owner;
};

typedef std::shared_ptr<Product> ProductPtr;
typedef std::vector<ProductPtr> ProductList;

