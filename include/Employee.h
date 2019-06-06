#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
template <class T> // T - salary "range", can be short int, int or long int
class Employee {
    public:
    Employee(std::string name = "Worker", int age = 18, T salary = 2500);
    ~Employee();
    std::string getName() const;
    int getAge() const;
    T getSalary();
    T setSalary(T& newSalary);

    private:
    int age;
    T salary;
    std::string name;
};

#endif
