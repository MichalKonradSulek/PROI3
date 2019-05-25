#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

class Product {
    public:
    Product (std::string name = "Something", int price = 100);
    virtual ~Product();
    int changePrice(int newPrice);
    std::string getName();
    int getPrice();
    virtual std::string getInfo();

    //protected:
    int price;
    std::string name;
};

#endif
