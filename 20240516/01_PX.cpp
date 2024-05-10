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

int main(int argc, char** argv) {
	Mx<int**> a(3,5);
	a.printMatrixDimension();
	a.printMatrix();
	Mx<int**> b(5,3);
	b.printMatrixDimension();
	b.printMatrix();	
	
	a.deleteMatrix();
	b.deleteMatrix();
	return 0;
}
