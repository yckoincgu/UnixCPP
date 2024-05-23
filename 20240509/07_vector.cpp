#include <iostream>
#include <vector>

// std::vector is a template class from the Standard Library for dynamic arrays
// <int> specifies that it's a vector of integers
// allowing you to store a sequence of elements that can grow or shrink in size.
void printVectorNumbers(std::vector<int> numbers){
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    numbers.push_back(40);

    // Access elements of the vector using index
    std::cout << "First element: " << numbers[0] << std::endl;
    std::cout << "Second element: " << numbers[1] << std::endl;

    // std::vector<int>::iterator is the data type *it
     std::cout << "Elements:";
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << std::endl;
}

// std::vector is a template class from the Standard Library for dynamic arrays
// <int> specifies that it's a vector of char
void printVectorCharacters(std::vector<char> characters){
    characters.push_back('a');
    characters.push_back('b');
    characters.push_back('c');
    characters.push_back('d');

    // Access elements of the vector using index
    std::cout << "First element: " << characters[0] << std::endl;
    std::cout << "Second element: " << characters[1] << std::endl;

    // Access elements of the vector using iterator
    std::cout << "Elements:";
    for (std::vector<char>::iterator it = characters.begin(); it != characters.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << std::endl;
}

int main() {
    // Declare a vector of integers
	std::vector<int> numbers;
	printVectorNumbers(numbers);
    
	std::vector<char> characters;
	printVectorCharacters(characters);

    int i;
	std::cin>>i;

    return 0;
}

