#include <iostream>

template <typename T>  // T is a placeholder for any type
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << max(3, 5) << std::endl;          // int
    std::cout << max(3.14, 2.71) << std::endl;    // double
    std::cout << max('a', 'z') << std::endl;      // char
}