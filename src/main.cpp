/* 	Jakub Kieżun
 	300225
	Wiktor Kuśmirek
	Projekt 2
*/

#include <iostream>
#include "Product.h"
#include "Shop.h"
#include "ProductFood.h"
#include "ProductTechnical.h"

using namespace std;

int main() {
	Shop<int, long int> sklep1("Janbol", "Gdynia", 1000);
	sklep1.hireEmployee(Employee<long int>("John", 18, 2500));
	sklep1.hireEmployee(Employee<long int>("Mark", 20, 2000));
	sklep1.buyProduct(ProductFood("Mleko", 2));
	sklep1.buyProduct(Product("Cola", 3));
	sklep1.buyProduct(ProductTechnical("PowerTape", 10, false));
	sklep1.buyProduct(Product("Ziemniaki", 3));
	sklep1.printInfo();
	sklep1.sellProduct("Cola");
	sklep1.printInfo();
	Shop<int, long int> sklep2("Rumiak", "Rumia", 2000);
	sklep2.hireEmployee(Employee<long int>("Zenon" ,18, 2300));
	sklep2.buyProduct(Product("Banana", 5));
	sklep2.buyProduct(ProductTechnical("Lighter", 1));
	sklep2.printInfo();
/*	Shop<int, long int> sklep3 = sklep1 + sklep2;
	sklep3.printInfo();
	sklep3.sellProduct("Banana");
	sklep3.printInfo();*/
}
