// C++ program to implementation
// Function Pointer
#include <iostream>
using namespace std;

int multiply(int a, int b) { return a * b; }

int main()
{
	int (*func)(int, int);

	// func is pointing to the multiplyTwoValues function

	func = multiply;

	int prod = func(15, 2);
	cout << "The value of the product is: " << prod << endl;

	return 0;
}

