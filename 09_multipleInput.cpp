// C++ program to input multiple items 
#include <iostream> 
#include <vector> 
using namespace std; 

int main() 
{ 
	int n; 
	// Input the number of elements 
	cout << "Enter the number of elements you want to "
			"input: "; 
	cin >> n; 

	// Initialize a vector of size n 
	vector<int> vec(n); 

	// Input n numbers into the vector 
	cout << "Enter " << n << " numbers: "; 
	for (int i = 0; i < n; i++) { 
		cin >> vec[i]; 
	} 

	// Output the entered numbers 
	cout << "You entered: "; 
	for (int i=0; i< sizeof(vec); i++) { 
		cout << vec[i] << " "; 
	} 
	cout << endl; 

	return 0; 
}

