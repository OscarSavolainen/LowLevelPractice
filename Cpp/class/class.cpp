#include <iostream>
#include <string>

class MyClass {
private:
    int age;
    std::string name;

public:
    MyClass(int i, const std::string& str) : age(i), name(str) {}

    void SetAge(int i) {
        age = i;
    }

    void SetName(std::string& str) {
        name = str;
    }

    const std::string& GetName() const {
        return name;
    }

    

};

int main() {
    MyClass instance(27, "Oscar");

    std::cout << instance.GetName() << std::endl;


    return 0;
}