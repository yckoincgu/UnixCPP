#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string line;

    std::cout << "Enter a line of text: ";
    std::getline(std::cin, line);
    std::cout << "You entered: " << line << std::endl;


    // The previous content of "line object" is cleared before the new line is read into it
    std::istringstream iss("This is a line with multiple words.");
    std::getline(iss, line);  
    std::cout << "From string stream: " << line << std::endl;

    return 0;
}