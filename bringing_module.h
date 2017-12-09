#pragma once

class BringingModule {
public:
    void fetchFood(string foodName, string userName);
    void deliverProductToUser();
    void ejectProductFromFridge(ProductPtr product);
};


typedef std::shared_ptr<BringingModule> BringingModulePtr;
