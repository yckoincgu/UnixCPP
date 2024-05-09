// C++ program to input multiple items 
#include <iostream> 
#include <string>

using namespace std; 

int main() 
{ 
	
	/* std::string 
	   (1) 	a class in the C++ Standard Library 
	 		that represents a sequence of characters
	   (2) 	managing its own memory and can 
	    	dynamically resize itself to accommodate the length of the text it holds
	*/
	std::string line;
	std::cout << "Please input a string " << std::endl;
	std::getline(std::cin, line);
	std::cout << "You entered: " << line << std::endl;
	std::cout << "Another input by cin " << std::endl;
	std::cin>> line;
	std::cout << "You entered by cin: " << line << std::endl;
	std::getline(std::cin, line);



	
	
	
	

	return 0; 
}

