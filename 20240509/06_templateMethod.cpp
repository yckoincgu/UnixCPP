#include <iostream>

// Template class with a templated method
template <typename T>
class MyClass {
private:
    T data;
public:
	/* 	It takes a parameter of type T and 
		initializes the member variable data with the value passed to the constructor.
	*/	
    MyClass(T d) : data(d) {}

    // Templated method to display data
    template <typename U>
    void display(U prefix) {
        std::cout << prefix << ": " << data << std::endl;
    }
};

int main() {
    // Instantiate MyClass with int data type
    // intObj is an object variable
    MyClass<int> intObj(42);
    intObj.display("Integer");

    // Instantiate MyClass with double data type
    MyClass<double> doubleObj(3.14);
    doubleObj.display("Double");

    return 0;
}

