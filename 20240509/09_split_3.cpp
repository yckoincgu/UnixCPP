#include <iostream>
#include <sstream>
#include <vector>
#include <string>

std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    std::string input = "Hello,World,Split,Example";
    char delimiter = ',';
    std::vector<std::string> tokens = split(input, delimiter);
    for (size_t i = 0; i < tokens.size(); ++i) {
        std::cout << "Token " << i << ": " << tokens[i] << std::endl;
    }
    return 0;
}

