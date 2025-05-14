#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int main() {
    std::string data = "apple,banana,cherry";   // std::string = Container for text (store, modify, access randomly).
                                                    
    std::istringstream iss(data);               // Creates a stream from the string
                                                // Streams = I/O tools for sequential reading/writing (files, parsing).
    std::string fruit;
    std::vector<std::string> fruits;

    while (std::getline(iss, fruit, ',')) {         // Stops at the first comma
                                                    // Returns a reference to iss (useful for chaining operations).
                                                    // after the loop finishes, iss is empty (all data has been extracted).
        fruits.push_back(fruit);
    }

    std::cout << "Fruits: ";
    for (const auto& f : fruits) {
        std::cout << f << " ";
        // You cannot modify f here, and you are not making a copy by "const auto&"
    }
    std::cout << std::endl; // Output: Fruits: apple banana cherry

    return 0;
}