/*
	(1) little characters, a,b,c are used for object instances
	(2) big characters A,B,C are used for matrix
*/

#include <iostream>

template <typename T>
class Mobject
{
public:
	T A;		// the first type of matrix
	int n, m;	// rows=n; columns=m;
	Mobject(int n, int m):n(n),m(m){
		A=new int*[n];
		for(int i=0; i< n; i++)
			A[i]=new int[m];
		int k=0;	
		for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			A[i][j]	=k++;
		printMatrixDimension();
		printMatrix();			
	}
	void printMatrixDimension(){
		std::cout<<"The matrix dimensions n=" << n<< " m= "<<m<<std::endl;
	}
	
	void printMatrix(){
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++) std::cout<< A[i][j]	<< " ";	
			std::cout<<std::endl;			
		}	
	}
	
	void deleteMatrix(){
	    for (int i = 0; i < n; ++i) delete[] A[i]; // Release memory and Ball destruBtor 
		delete[] A; // Release memory and Ball destruBtor		
	} 
	
};

int main() {
	Mobject<int**> a(3,5);
	Mobject<int**> b(5,3);
	
	a.deleteMatrix();
	b.deleteMatrix();
	
	int i;
	std::cin>>i;
	
	return 0;
}
