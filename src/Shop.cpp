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
#include "Shop.h"
#include <algorithm>

using namespace std;

template <class T1, class T2>
Shop<T1,T2>::Shop (std::string name, std::string address, T1 capital) {
    this->name = name;
    this->address = address;
    this->capital = capital;
    this->numProducts = 0;
    this->numEmployees = 0;
    this->employees = nullptr;
}

template <class T1, class T2>
Shop<T1,T2>::~Shop () {
    delete[] this->employees;
    for (vector<Product*>::iterator i = prods.begin(); i != prods.end(); ++i) delete *i;
    //std::cout<<"Shop " + name + " deleted.\n";   //Debugging
}

template <class T1, class T2>
void Shop<T1,T2>::printInfo() {
    std::cout<<"SHOP INFO\n";
    std::cout<<"Name:"<<this->name<<"\n";
    std::cout<<"Capital:"<<this->capital<<"\n";
    this->listEmployees();
    this->listProducts();
}

// Employee methods
template <class T1, class T2>
int Shop<T1,T2>::payEmployees() {
    for (int i = 0; i < this->numEmployees; i++) {
        if (this->capital >= employees[i].getSalary()) {
            this->capital-=employees[i].getSalary();
            std::cout<<employees[i].getName() + " got paid.\n";
        }
        else
            std::cout<<"Can't afford to pay " + employees[i].getName();
    }
    return this->capital;
}

template <class T1, class T2>
Employee<T2> Shop<T1,T2>::hireEmployee(Employee<T2> const &employee) {
	try
      {  
    	if(employee.getAge() < 18) throw int(1);
	  }
	catch (int n)
    {
      std::cerr << "Error " << n << ": person " << employee.getName() << " under age - Emploee not added" << '\n';
	  return employee;
    }
    Employee<T2> *tmp_emp = this->employees;
    this->numEmployees++;
    this->employees = new Employee<T2>[this->numEmployees];
    for(int i = 0; i < numEmployees - 1; i++) {
        this->employees[i] = tmp_emp[i];
    }
    this->employees[numEmployees - 1] = employee;

    delete[] tmp_emp;
    return employee;
}

template <class T1, class T2>
int Shop<T1,T2>::fireEmployee(std::string name) {
    bool found = 0;
    int foundIndex;
    for (int i = 0; i < numEmployees; i++) {
        if (this->employees[i].getName() == name) {
            found = 1;
            foundIndex = i;
            break;
        }
    }
    if (found == 0) {
        std::cout<<"Employee with name " + name + " not found.\n";
        return -1;
    }
    else {
        Employee<T2> *tmp_emp = this->employees;
        int j = 0;
        this->numEmployees--;
        this->employees = new Employee<T2>[this->numEmployees];
        while(j < numEmployees){
        for (int i = 0; i < numEmployees + 1; i++) {
            if (i != foundIndex) {
                this->employees[j] = tmp_emp[i];
                j++;
            }
        }
        }
        Employee<T2> returnEmployee = tmp_emp[foundIndex];
        delete[] tmp_emp;
        return 1;
    }
}

template <class T1, class T2>
void Shop<T1,T2>::listEmployees() {
    std::cout<<"EMPLOYEES\n";
    if (this->numEmployees > 0) {
        for (int i = 0; i < numEmployees; i++) {
            std::cout<<"--Name:" + employees[i].getName() + " --Salary:"<<employees[i].getSalary()<<" --Age:"<<employees[i].getAge()<<"\n";
        }
    }
    else {
        std::cout<<"There are no employees yet.\n";
    }
}

template <class T1, class T2>
void Shop<T1,T2>::listEmployees(int n) {
    int lastIndex;
    std::cout<<"EMPLOYEES\n";
    if (this->numEmployees > 0) {
        if (n > numEmployees) {
            lastIndex = numEmployees;
        }
        else {
            lastIndex = n;
        }
        for (int i = 0; i < lastIndex; i++) {
            std::cout<<"--Name:" + employees[i].getName() + " --Salary:"<<employees[i].getSalary()<<" --Age:"<<employees[i].getAge()<<"\n";
        }
    } else {
        std::cout<<"There are no employees yet.\n";
    }
}

// Product methods
template <class T1, class T2>
void Shop<T1,T2>::listProducts() {
    std::cout<<"PRODUCTS\n";
    if (this->numProducts > 0) {
        for (vector<Product*>::iterator it = this->prods.begin(); it < this->prods.end(); it++) {
            std::cout<<(*it)->getInfo()<<"\n";
        }
    }
    else {
        std::cout<<"There are no products yet.\n";
    }
}

template <class T1, class T2>
template <class ProductType>
Product Shop<T1,T2>::buyProduct(ProductType const &product)
  { try
    { prods.push_back(nullptr);
      prods.back() = new ProductType(product);
      this->numProducts++;
    }
    catch (bad_alloc& ba)
    {
      cerr << "bad_alloc caught in buyProduct: " << ba.what() << '\n';
      if(prods.back() == nullptr) prods.pop_back();
    }
    return product;
    }

template <class T1, class T2>
int Shop<T1,T2>::sellProduct(std::string prod_name) {
    for (vector<Product*>::iterator it = this->prods.begin(); it!= this->prods.end(); ++it) {
		if ((*it)->getName() == prod_name) {
			this->capital+=(*it)->getPrice();
            delete *it;
            prods.erase(it);
            return 1;
		}
	}
	std::cout<<"Product with name " + prod_name + " not found.\n";
	return -1;
}

//opearator + overload
/*template <class T1, class T2>
Shop<T1,T2> Shop<T1,T2>::operator+ (const Shop<T1,T2> &shop2) {
    Shop<T1,T2> newShop(this->name, this->address, this->capital + shop2.capital);
    newShop.numEmployees = this->numEmployees + shop2.numEmployees;
    newShop.numProducts = this->numProducts + shop2.numProducts;
    newShop.employees = new Employee<T2>[newShop.numEmployees];
    for (int i = 0; i < newShop.numEmployees; i++) {
        if (i < this->numEmployees)
            newShop.employees[i] = this->employees[i];
        else
            newShop.employees[i] = shop2.employees[i - this->numEmployees];
    }
    for (int i = 0; i < newShop.numProducts; i++) {
        if (i < this->numProducts)
            newShop.products.push_back(this->products.at(i));
        else
            newShop.products.push_back(shop2.products.at(i - this->numProducts));
    }
    return newShop;
}*/

//template class Shop<int,int>;
//template class Shop<long int, int>;
template class Shop<int,long int>;
template Product Shop<int, long int>::buyProduct<Product>(Product const &product);
template Product Shop<int, long int>::buyProduct<ProductFood>(ProductFood const &product);
template Product Shop<int, long int>::buyProduct<ProductTechnical>(ProductTechnical const &product);
//template class Shop<short int, long int>;
//template class Shop<long int, short int>;
//template class Shop <int, short int>;
//template class Shop <short int, int>;
//template class Shop<short int, short int>;
//template class Shop<long int, long int>;

