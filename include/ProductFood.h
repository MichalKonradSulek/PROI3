#ifndef PRODUCTFOOD
#define PRODUCTFOOD

#include <iostream>
#include "Product.h"

class ProductFood : public Product
{ protected:
    unsigned expiryDate;
  public:
    ProductFood(std::string name = "Something", int price = 100, unsigned expiryDate = 2020);
    ~ProductFood();
    std::string getInfo();
};

#endif // PRODUCTFOOD
