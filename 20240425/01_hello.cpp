#include <iostream>

int main()
{
 /* std::endl: This is a manipulator 
 	that inserts a newline character into the output stream and  
 	
 	std::cout: 
    (1) This is the standard output stream object, 
    	which is used to send output to the standard output (usually the console)   
    (2) The scope resolution operator :: to access the function inside the namespace.	
 */	
	 std::cout << "Hello, World 1";
	 std::cout << "Hello, world 2 with a new line character \\n" << std::endl;	 
 return 0;
}
