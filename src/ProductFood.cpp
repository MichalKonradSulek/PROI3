/* 	Projekt 3 
    created by:
    Michal Sulek
    259686
	teacher:
    Wiktor Kuśmirek
*/

#include <iostream>
#include <sstream>
#include "ProductFood.h"

using namespace std;

ProductFood::ProductFood(string name, int price, unsigned expiryDate)
{ this->price = price;
  this->name = name;
  this->expiryDate = expiryDate;
}

ProductFood::~ProductFood() {}

string ProductFood::getInfo()
{ std::string output;
  std::stringstream sst;
  sst<<"--Name:" + name + " --Price:"<< price << " --ExpiryDate:" << expiryDate;
  std::getline(sst, output);
  return output;
}
