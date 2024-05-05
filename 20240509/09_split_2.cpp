#include <iostream>
#include <string>
#include <sstream>

class Split{

public:
	std::string* ptrStrings;
	std::string line;
	char delimiter;
	Split(std::string line, char delimiter):line(line), delimiter(delimiter) {
		
		int n=0;
		std::stringstream tempStr(line);
		std::string words;
		while(std::getline(tempStr, words, delimiter)) n++;	
		//std::cout << "string length is " << n<< std::endl;
		
		int i=0;
		std::string strings[n];
		std::stringstream str(line);
		while(std::getline(str, words, delimiter)){
			strings[i]=words+'\0';
			//std::cout << strings[i] << std::endl;
			i++;
		}
		ptrStrings=strings;
		while(ptrStrings != NULL){
			std::cout << *ptrStrings << std::endl;
			ptrStrings++;
		}
				
	} 

};



int main()
{
    std::string line="I am a student";
    int i=1;
	char delimiter=' ';
	
    Split r(line, delimiter);
    std::cout << r.line << std::endl;

	std::cin>>i;
    
 }
