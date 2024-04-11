// C++ program to read multiple numbers in a single line of 
// input 
#include <iostream> 
#include <windows.h>
using namespace std; 

int main() 
{ 
	int numbers[10]; 
	int num, count; 

	// Prompt the user to enter numbers separated by spaces 
	cout << "Enter numbers separated by spaces: "; 

	// Input numbers until the user enters something other 
	// than an integer 
	
	while (count< sizeof(numbers)) {
		count=0;
		while (!(GetAsyncKeyState(VK_RETURN) & 0x8000)) { 
		 	// Add the entered number to the array
			cin >> num; 
			numbers[count]=num;
			count++; 
		}
		break;
	} 
	cout << "You entered: "<< count << " integers";
	
	// Output the entered numbers 
	cout << endl; 
	for (int i =0; i< count; i++) { 
		cout << numbers[i] << " "; 
	} 
	cout << endl; 

	return 0; 
}

