#include <iostream>
#include <string>
#include "Employee.h"

template <class T>  Employee<T>::Employee(std::string name, int age, T salary) {
    this->age = age;
    this->salary = salary;
    this->name = name;
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
