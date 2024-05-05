#include <iostream>
#include <string>
#include <sstream>


int getWordsNumber(std::string line, char delimiter){
	int i=1;
	std::stringstream sstream_var(line);
	std::string words;
	while(std::getline(sstream_var, words, delimiter)) i++;
	
	return i;
} 

bool split(std::string line, char delimiter){
	
	int N=getWordsNumber(line, delimiter);
	
	std::stringstream sstream_var(line);
	std::string words;
	int i=0;
	
	std::string** strArray = new std::string*[N];
	
	while(std::getline(sstream_var, words, delimiter)){
		strArray[i++]=new std::string(words);
		std::cout << words << std::endl;
	} 
	return true;
};

int main()
{
    std::string line="I am a student";
    int i=1;
	char delimiter=' ';
    bool r=split(line, delimiter);

	std::cin>>i;
    
 }
