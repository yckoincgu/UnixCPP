#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream  fileDevice("X06512A.csv");
    std::string line;
    int i=1;
    while(std::getline(fileDevice,line))
    {
    	std::cout<< "student " << i++ << ": "<< line << std::endl;
    }

   
	std::cin>>i;
 }
