#ifndef PRODUCTTECHNICAL
#define PRODUCTTECHNICAL

#include <iostream>
#include "Product.h"

class ProductTechnical : public Product
{ protected:
    bool inflammable;
  public:
    ProductTechnical(std::string name = "Something", int price = 100, bool inflammable = true);
    ~ProductTechnical();
    std::string getInfo();
};

#endif // PRODUCTTECHNICAL
