#include <iostream>
#include <vector>
#include <string>

// Function that modifies the original vector
void addFruit(std::vector<std::string>& fruits, const std::string& fruit) {
    // std::string as argument type can accept conversions from string 
    // The compiler constructs a temporary std::string from "cherry"
    // & : Reference Binding
    fruits.push_back(fruit);
}

int main() {
    std::vector<std::string> fruits = {"apple", "banana"};
    addFruit(fruits, "cherry"); // Pass by reference, compiler will make it a std::string then pass

    for (const auto& f : fruits) {
        std::cout << f << " "; // Output: apple banana cherry
    }
}