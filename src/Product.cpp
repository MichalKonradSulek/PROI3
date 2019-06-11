/* 	Projekt 3 
    created by:
    Jakub Kieżun
 	300225
    modified by:
    Michal Sulek
    259686
	teacher:
    Wiktor Kuśmirek
*/

#include <iostream>
#include <string>
#include <sstream>
#include "Product.h"

Product::Product (std::string name, int price) {
    this->name = name;
    this->price = price;
    //std::cout<<"Product " + name + " created.\n";  //Debugging purposes
}

Product::~Product() {
    //std::cout<<"Product " + name + " deleted.\n";  //Debugging
}
int Product::changePrice (int newPrice) {
    this->price = newPrice;
    return this->price;
}

std::string Product::getName() {
    return this->name;
}

int Product::getPrice() {
    return this->price;
}

std::string Product::getInfo()
{ std::string output;
  std::stringstream sst;
  sst<<"--Name:" + name + " --Price:"<<price;
  std::getline(sst, output);
  return output;
}
