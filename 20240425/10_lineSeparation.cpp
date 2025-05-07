#include <iostream>
#include <cstring>	// C-style string functions
#include <vector>
#include <sstream>
#include <string>


int main() {
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
		std::cout << word << std::endl;
		words.push_back(word);
		wordsLength++;
	}

	
	for (int i=0; i< wordsLength; i++) {
		std::cout << words.at(i) << " ";
	}
	
    return 0;
}