#include <iostream>
#include <sstream>
#include <string>

int main(){
    // making iss is now an input string stream associated with the string data
    std::string data = "123 4.56 Hello true";
    std::istringstream iss(data);
    int intValue;
    double doubleValue;
    std::string stringValue;
    bool boolValue;

    
    // Extraction:  The >> operator extracts formatted data, typically separated by whitespace
    iss >> intValue >> doubleValue >> stringValue >> boolValue;
    std::cout << "Integer: " << intValue << std::endl;     // Output: Integer: 123
    std::cout << "Double: " << doubleValue << std::endl;   // Output: Double: 4.56
    std::cout << "String: " << stringValue << std::endl;   // Output: String: Hello
    std::cout << "Boolean: " << boolValue << std::endl;    // Output: Boolean: 1



    // Line-by-Line Reading
    std::string lineData = "First line\nSecond line with spaces";
    std::istringstream iss2(lineData);
    std::string line1, line2;

    std::getline(iss2, line1);
    std::getline(iss2, line2);

    std::cout << "Line 1: " << line1 << std::endl; // Output: Line 1: First line
    std::cout << "Line 2: " << line2 << std::endl; // Output: Line 2: Second line with spaces

}
