#include <iostream>
using namespace std;

//  
int sum(int a, int b=20)
{
  int result;
 
  result = a + b;
  
  return (result);
}

// Function to add two integers
int add(int a, int b) {
    return a + b;
}

// Overloaded function to add three integers
int add(int a, int b, int c) {
    return a + b + c;
}

// Overloaded function to add two doubles
double add(double a, double b) {
    return a + b;
}
 
int main ()
{

   	/* overloaded functions, 
	   (1) the compiler determines which version of the function to call based on the arguments provided.
	   (2) must differ in the number or type of their parameters
	   
	*/   
    std::cout << add(2, 3) << std::endl;         // Calls the first add function
    std::cout << add(2, 3, 4) << std::endl;      // Calls the second add function
    std::cout << add(2.5, 3.7) << std::endl;     // Calls the third add function   
   
   // local variables
   int a = 100;
   int b = 200;
   int result;
 
   // 如果parameter的值不留空，則使用傳遞的數值 
   result = sum(a, b);
   cout << "Total value is :" << result << endl;
 
   // 如果parameter的值留空，則使用默認值20 
   result = sum(a);
   cout << "Total value is :" << result << endl;
      
 
   return 0;
}
