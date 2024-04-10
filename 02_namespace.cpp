#include <iostream>
using namespace std;
/*
	namespace: a system keyword for updating defined names in current scope
	using: a prepreprocess directive to perform tasks before the compilation process begins
	std: standard libraries
*/

// Declaration of a namespace called MyNamespace
namespace MyNamespace {
    int myFunction(int a, int b) {
        return a + b;
    }
}

using MyNamespace::myFunction; // Bring myFunction into the current scope

int main() {
    cout << myFunction(3, 4) << endl; // No need to use MyNamespace::
    return 0;
}

