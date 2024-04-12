// C++ program to input multiple items 
#include <iostream> 
#include <sstream>
#include <string>
#include <vector> 
using namespace std; 

int main() 
{ 
	
	/* std::string 
	   (1) 	a class in the C++ Standard Library 
	 		that represents a sequence of characters
	   (2) 	managing its own memory and can 
	    	dynamically resize itself to accommodate the length of the text it holds
	*/
	std::string inputLine, word;
	
	std::getline(std::cin, inputLine);	// get an input line
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
	
    while (std::getline(iss, word, ' ')) {
        words.push_back(word);
        std::cout << word << " ";
    }
	
		
    
    

	
	std::cout << "You entered: " << inputLine << std::endl;



	
	
	
	

	return 0; 
}

