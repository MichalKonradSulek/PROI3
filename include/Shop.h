#ifndef SHOP_H
#define SHOP_H

#include <iostream>
#include <string>
#include "Product.h"
#include "Employee.h"
#include "vector"
template <class T1, class T2>  // T1 - capital "range", T2 - the highest salary "range", each can be short int, int or long int
class Shop {
    public:
    Shop<T1,T2>(std::string name = "", std::string address = "", T1 capital = 0);
    ~Shop();

    void printInfo();

    //Employee methods
    int payEmployees();
    Employee<T2> hireEmployee(Employee<T2> const &employee);
    int fireEmployee(std::string name); //returns 1 if suceeded, -1 if failed
    void listEmployees(); // list all employees
    void listEmployees(int n); // list n employees

    //Product methods
    void listProducts(); // list all products
    Product buyProduct(Product const &product);
    int sellProduct(std::string prod_name);
    int binProduct(std::string name);

    //operator + overload
    Shop operator+(Shop const &shop2);


    //private:
    std::string name;
    std::string address;
    T1 capital;
    std::vector<Product> products;
    int numProducts;
    Employee<T2> *employees;
    int numEmployees;
};
#endif
