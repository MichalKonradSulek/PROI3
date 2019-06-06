#include <iostream>
#include <string>
#include "Employee.h"

template <class T>  Employee<T>::Employee(std::string name, int age, T salary) {
  try{    
    if(age < 18) throw int(1);
	this->age = age;
    this->salary = salary;
    this->name = name;
  }
  catch (int n)
    {
      cerr << "Error " << n << ": person under age - Emploee not added" << '\n';
    }
//  std::cout<<"Employee " + name + " created.\n";  //Debugging
}
template <class T> Employee<T>::~Employee() {
//  std::cout<<"Employee " + name + " deleted.\n";   //Debugging
}
template <class T> 
std::string Employee<T>::getName() { return this->name; }
template <class T> 
int Employee<T>::getAge() { return this->age; }
template <class T> 
T Employee<T>::getSalary() { return this->salary; }
template <class T> 
T Employee<T>::setSalary(T& newSalary) {
    this->salary = newSalary;
    return this->salary;
}

// This is necessary in order to keep declaration and definition separated when using template
template class Employee<int>;
template class Employee<short int>;
template class Employee<long int>;
