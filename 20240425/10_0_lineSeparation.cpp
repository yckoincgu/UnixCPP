#include <sstream>
#include <iostream>

int main() {
/*
    std::cout within <iostream> for output
    << within <sstream> for inserting and formatting data
    >> within <sstream> for data extraction    
*/

    std::stringstream ss;
    ss << "Value: " << 100;  // Stream content: "Value: 100"

    std::string dummy;
    int val;
    
    ss >> dummy;    // Read "Value:" into a dummy string
    ss >> val;      // Now extracts 100

    std::cout << val << std::endl;  // Output: 100
}