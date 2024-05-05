// C++ program to demonstrate constructors 
#include <bits/stdc++.h> 
using namespace std; 
class Student 
{ 
	public: 
	std::string name;
	int id; 
	
	//Default Constructor 
	Student() 
	{ 
		cout << "Default Constructor called" << endl; 
		id=-1; 
	} 
	
	//Parameterized Constructor 
	Student(std::string name, int id):name(name), id(id) 
	{ 
		cout <<"Parameterized Constructor called "<< endl; 

	} 
}; 

int main() { 
	
	// student will call Default Constructor 
	Student student; 
	cout <<"student id is: "<<student.id << endl; 
	
	// student_2 will call Parameterized Constructor 
	Student student_2("john", 21); 
	cout <<"student_2 name is: " <<student_2.name << endl;
	cout <<"student_2 id is: " <<student_2.id << endl; 
	return 0; 
} 

