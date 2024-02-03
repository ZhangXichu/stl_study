#include <string>
#include <iostream>

class Person {
public:
    std::string name;
    int age;

    Person(const std::string& name, int age) : name(name), age(age) {}

    void introduce() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }

    ~Person() {
        std::cout << "Destroying " << name << std::endl;
    }
};