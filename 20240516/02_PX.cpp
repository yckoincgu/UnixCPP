#include <iostream>

template <typename T>
class Mx
{
public:
	T A;
	int n=0, m=0;	//rows=n; columns=m;
	Mx(int n, int m):n(n),m(m){
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
	    for (int i = 0; i < n; ++i) {
	        delete[] A[i];
	    }
	    delete[] A;		
	} 
	
};


template<typename T>
class AxB{
	public:
	T c; 
	int n=0,m=0,p=0;
	AxB(Mx<T>& a, Mx<T>& b){
		T X=a.A, Y=b.A;
		a.printMatrixDimension();
		a.printMatrix();
		b.printMatrixDimension();
		b.printMatrix();
		Mx<int**> c(a.n,b.m);
		T Z=c.A;
		for(int i=0; i<a.n; i++){
			for(int j=0; j<b.m; j++){
				Z[i][j]=0;
				for(int k=0; k<a.m; k++)
					Z[i][j] +=X[i][k]*Y[k][j];
			}
		}
		c.printMatrixDimension();
		c.printMatrix();	
	}
	void deleteMatrix(){
	    for (int i = 0; i < n; ++i) {
	        delete[] c[i];
	    }
	    delete[] c;		
	} 	
	
}; 

int main(int argc, char** argv) {
	Mx<int**> a(3,5);
	Mx<int**> b(5,3);
	
	AxB<int**> c(a, b);

	a.deleteMatrix();
	b.deleteMatrix();
	c.deleteMatrix();
	
	return 0;
}
