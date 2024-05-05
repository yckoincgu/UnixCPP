#include <iostream>
/*  1. allowing you to write generic algorithms and data structures 
	   that can work with a wide range of data types
	2. enabling you to define functions, classes, and methods 
	   that can operate on a variety of data types 
	   without having to duplicate code for each type
	3. Please check its definition https://chat.openai.com/c/aa5983b2-5c1a-45ec-aac0-1fc4212ebfec 
	4. templates declaration, 
	(A) typename is a system keyword in angle brackets
	(B) T can be any valid data type of C++
			
	Ex1. 
		template <typename T>
		T functionName(T param1, T param2) {
		    // Function body
		}
	Ex2.
		template <typename T>
		class ClassName {
		    // Class members and methods
		};
		
	  
*/

template <typename T>
T add(T a, T b) {
    return a + b;
}

template <typename T>
T subtract(T a, T b) {
    return a - b;
}


int main() {
    int result1 = add<int>(5, 10);  // calling add with int arguments
    std::cout << "addition result (int): " << result1 << std::endl;

    double result2 = add<double>(3.5, 2.7);  // calling add with double arguments
    std::cout << "addition result (double): " << result2 << std::endl;
    
    result1 = subtract<int>(5, 10);  // calling add with int arguments
    std::cout << "subtraction result (int): " << result1 << std::endl;

    result2 = subtract<double>(3.5, 2.7);  // calling add with double arguments
    std::cout << "subtraction result (double): " << result2 << std::endl;    

    return 0;
}

