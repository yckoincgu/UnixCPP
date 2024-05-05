#include <iostream>

/* Templates declaration
	
	Ex3.
		template <typename T>
		class ClassName {
		public:
		    T memberVariable;
		    void memberFunction(T param);
		};
	Template class with a non-type template parameter		
	Ex4.
	template <int N>	N is a constant at compiler time
	 
*/

template <int N>
class Xarray {
private:
    int data[N]; // Array of size N
public:
    // Constructor initializes elements of the array with value 0
    Xarray() {
        for (int i = 0; i < N; ++i) {
            data[i] = i;
        }
    }

    // Method to display elements of the array
    void display() {
        for (int i = 0; i < N; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    // Instantiate Xarray with a template variable of value 5
    Xarray<5> arr1;
    arr1.display(); 

    // Instantiate Xarray with a template variable of value 10
    Xarray<10> arr2;
    arr2.display(); 

    return 0;
}

