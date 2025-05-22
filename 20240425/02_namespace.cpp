#include <iostream>
using namespace std;
/*
	namespace: 
	(1) providing a space where we can define or declare identifier 
		i.e. variable, method, classes.
	(2) a system keyword for updating defined names in current scope
	(3) using: a prepreprocess directive to perform tasks before the compilation process begins
	std: 
	(1) standard libraries
*/

namespace first_space
{
  void func()
  {
     cout << "Inside first_space" << endl;
  }
}
 
// second name space
namespace second_space
{
  void func()
  {
     cout << "Inside second_space" << endl;
  }
}

// A namespace called MyNamespace
namespace MyNamespace {
    int myFunction(int a, int b) {
        return a + b;
    }
}

int main() {
	using MyNamespace::myFunction; // Bring myFunction into the current scope	
    cout << myFunction(3, 4) << endl; // No need to use MyNamespace::
    
	using namespace second_space;
   	// This calls function from first name space.
  	func();
    
    return 0;
}

