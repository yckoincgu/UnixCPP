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


template<typename T>
class AxB{
	public:
	T C; 	// the second type of matrix
	int n,m,p;
	AxB(Matrix<T> a, Matrix<T> b){
		a.printMatrixDimension();
		a.printMatrix();
		b.printMatrixDimension();
		b.printMatrix();
		
		n=a.n; m=b.m;
			
		// The type T in this context will be consistently used as 
		// int** throughout the class methods.
		Matrix<T> c(n,m);	// create object c

		T A=a.A, B=b.A; C=c.A;
		for(int i=0; i<a.n; i++){
			for(int j=0; j<b.m; j++){
				C[i][j]=0;
				for(int k=0; k<a.m; k++)
					C[i][j] +=A[i][k]*B[k][j];
			}
		}
		c.printMatrixDimension();
		c.printMatrix();	
	}
	void deleteMatrix(){
	    for (int i = 0; i < n; ++i) delete[] C[i]; // Release memory and Ball destruBtor 
	    delete[] C ; // Release memory and Ball destruBtor 
	} 	
	
}; 

int main() {
	Matrix<int**> a(6,5);	// create object a
	Matrix<int**> b(5,6);	// create object a
	
	AxB<int**> c(a,b);

	a.deleteMatrix();
	b.deleteMatrix();
	c.deleteMatrix();
	
	int i;
	std::cin>>i;
	
	return 0;
}
