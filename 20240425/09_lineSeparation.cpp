#include <iostream>
#include <cstring>	// C-style string functions
#include <vector>
#include <sstream>
#include <string>


int main() {
    char str[] = "Hello, world! This is a test.";
    const char* delim = " ,.!"; // Delimiters are space, comma, and period

    // Get the first token
    char* token = strtok(str, delim);

    // Iterate through the tokens
    while (token != NULL) {
        std::cout << token << std::endl;
        // Get the next token
        token = strtok(NULL, delim);	// not recommended
    }
/* --------We will come back after introduction of class ---------*/    
	/* std::string 
	   (1) 	a class in the C++ Standard Library 
	 		that represents a sequence of characters
	   (2) 	managing its own memory and can 
	    	dynamically resize itself to accommodate the length of the text it holds
	*/
	std::string inputLine= "Hello world This is a test", 
				word;
	
	//std::getline(std::cin, inputLine);	// get an input line
	std::vector<std::string> words;
	/*
		std::vector
			providing dynamic array functionality
		std::vector<std::string>
		 	a dynamic array that can store strings. 
	*/
	std::istringstream iss(inputLine); 
	/*
		std::istringstream
			parsing inputLine into words 
	*/
	int wordsLength=0;
    while (std::getline(iss, word, ' ')) {
        std::cout << word << " ";
		words.push_back(word);
		wordsLength++;
    }
 
    for (int i=0; i< wordsLength; i++) {
        std::cout << words.at(i) << " ";
    }
	
    return 0;
}

