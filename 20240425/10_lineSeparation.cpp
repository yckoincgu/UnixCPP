#include <iostream>
#include <vector>
#include <sstream>
#include <string>


int main() {
	std::string inputLine= "Hello world This is a test", 	// a container with string
	word;

	//std::getline(std::cin, inputLine);	// get an input line


	std::vector<std::string> words;
	/*
	std::vector
	A container (data structure) to store objects
	providing dynamic array functionality
	std::vector<std::string>
	a dynamic array that can store strings. 

	std is a namespace to identifying groups
	*/
	std::istringstream iss(inputLine); 
	/*
	std::istringstream, It prepares the stream for parsing
	iss is an object containing inputline string but it is not a container
	it can read data, does not change data, support formated extraction, Tokenize/convert strings, etc.
	*/

	int wordsLength=0;
	while (std::getline(iss, word, ' ')) {
		// parsing inputLine into words 
		std::cout << word << std::endl;
		words.push_back(word);
		wordsLength++;
	}

	
	for (int i=0; i< wordsLength; i++) {
		std::cout << words.at(i) << " ";
	}
	std::cout << std::endl;
	std::cout << "The last part as below:  "<< std::endl;
	// Rewind the stream to read again
    iss.clear();                   // Clear any error flags (e.g., eof)
    iss.seekg(0);                  // Reset read position to start
	while(iss >> word)
		std::cout << word << std::endl;
	
    return 0;
}