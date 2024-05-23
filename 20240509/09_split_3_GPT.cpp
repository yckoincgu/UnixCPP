#include <iostream>
#include <sstream>
#include <vector>
#include <string>

// Function to split a string by a given delimiter
std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    
    // Extract tokens separated by the delimiter
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    std::string input = "Hello,World,Split,Example";
    char delimiter = ',';

    // Split the input string
    std::vector<std::string> tokens = split(input, delimiter);

    // Print each token using a range-based for loop
    int index = 0;
    for (const auto& token : tokens) {
        std::cout << "Token " << index++ << ": " << token << std::endl;
    }

    // Wait for user input before closing
    std::cin.get();

    return 0;
}

