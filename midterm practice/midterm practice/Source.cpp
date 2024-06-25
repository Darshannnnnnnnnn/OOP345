#include <iostream>
#include <memory> // For std::unique_ptr

class MyClass {
public:
    MyClass() { std::cout << "MyClass constructed!" << std::endl; }
    ~MyClass() { std::cout << "MyClass destructed!" << std::endl; }
    void someMethod() { std::cout << "Doing something..." << std::endl; }
};

int main() {
    // Creating a unique_ptr to manage an instance of MyClass
    std::unique_ptr<MyClass> ptr1(new MyClass());

    // Using the unique_ptr
    ptr1->someMethod();

    // The unique_ptr automatically manages memory deallocation
    // No need to explicitly delete ptr1

    // Example of transfer of ownership (moving)
    std::unique_ptr<MyClass> ptr2 = std::move(ptr1);
    // Now ptr2 owns the object, ptr1 is nullptr

    // Using ptr2
    ptr2->someMethod();

    // When ptr2 goes out of scope, the destructor of MyClass is automatically called

    return 0;
}
