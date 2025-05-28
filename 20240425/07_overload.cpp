#include <iostream>

// Overloaded functions for different types
int max(int a, int b) {
    return (a > b) ? a : b;
}

double max(double a, double b) {
    return (a > b) ? a : b;
}

char max(char a, char b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << max(3, 5) << std::endl;          // Calls int version
    std::cout << max(3.14, 2.71) << std::endl;    // Calls double version
    std::cout << max('a', 'z') << std::endl;      // Calls char version
    
    return 0;
}