/*
	(1) little characters, a,b,c are used for object instances
	(2) big characters A,B,C are used for matrix
*/

#include <iostream>

template <typename T>
class Matrix
{
public:
	T A;		// the first type of matrix
	int n, m;	// rows=n; columns=m;
	Matrix(int n, int m):n(n),m(m){
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
	Matrix<int**> a(3,5);
	Matrix<int**> b(5,3);
	
	a.deleteMatrix();
	b.deleteMatrix();
	
	int i;
	std::cin>>i;
	
	return 0;
}
