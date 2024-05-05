// C++ program to demonstrate accessing of data members 
#include <iostream> 
using namespace std; 

class Student { 
	
public: // Access specifier 
	// Data Members 
	string name; 
	
	// Member Functions() 
	void printname() { cout << "The student name is:" << name; } 
}; 
int main() 
{ 
	
	Student student; 		// Declare an object named student 
	
	student.name = "Abhi"; 	// accessing data member 
	
	student.printname(); 	// accessing member function 
	return 0; 
}

