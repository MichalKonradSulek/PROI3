#include <iostream>
#include <sstream>
#include "ProductTechnical.h"

using namespace std;

ProductTechnical::ProductTechnical(string name, int price, bool inflammable)
{ this->price = price;
  this->name = name;
  this->inflammable = inflammable;
}

ProductTechnical::~ProductTechnical() {}

string ProductTechnical::getInfo()
{ std::string output;
  std::stringstream sst;
  sst<<"--Name:" + name + " --Price:"<< price << " --Iinflammable:" << boolalpha << inflammable << noboolalpha;
  std::getline(sst, output);
  return output;
}
