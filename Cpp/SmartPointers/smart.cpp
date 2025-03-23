#include <iostream>
#include <memory>

class MyClass {
    public:
        MyClass() {
        std::cout << "Constructor"<<std::endl;
        }

        ~MyClass() {
            std::cout << "Destructor" << std::endl;
        }
};

int main () {

    std::cout << "Shared " << std::endl;

    std::shared_ptr<MyClass> sPtr1 = std::make_shared<MyClass>();
    {
        std::shared_ptr<MyClass> sPtr2 = sPtr1;
        std::cout << "shared count: " << sPtr1.use_count() << std::endl;
    }
    std::cout << "shared count: " << sPtr1.use_count() << std::endl;
    return 0;
}