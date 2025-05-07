#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int main() {
    std::string data = "apple,banana,cherry";
    std::istringstream iss(data);
    std::string fruit;
    std::vector<std::string> fruits;

    while (std::getline(iss, fruit, ',')) {
        fruits.push_back(fruit);
    }

    std::cout << "Fruits: ";
    for (const auto& f : fruits) {
        std::cout << f << " ";
        // // You cannot modify f here, and you are not making a copy by "const auto&"
    }
    std::cout << std::endl; // Output: Fruits: apple banana cherry

    return 0;
}