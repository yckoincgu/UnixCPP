#include <iostream>
#include <cstring>	// C-style string functions
#include <vector>
#include <sstream>
#include <string>


int main() {
    char str[] = "Hello, world! This is a test.";
    const char* delim = " ,.!"; // Delimiters are space, comma, and period

	std::cout<< "The first part" << std::endl;
    // Get the first token
    char* token = strtok(str, delim);
    // Iterate through the tokens
    while (token != NULL) {
        std::cout << token << std::endl;
        // Get the next token
        token = strtok(NULL, delim);	// NULL means "Continue searching for the next token 
										// In the same string that it was working on, 
										// strtok continues the previous call, 
										// using the delimiters specified before.
    }
	
    return 0;
}

