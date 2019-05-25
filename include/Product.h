#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

class Product {
    public:
    Product (std::string name = "Something", int price = 100);
    ~Product();
    int changePrice(int newPrice);
    std::string getName();
    int getPrice();
    std::string getInfo();

    //protected:
    int price;
    std::string name;
};

#endif
