#include <iostream>
//#include "Matrix.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
template <typename T>
class Mx
{
public:
	T A;
	int rows=0, columns=0;
	Mx(int n, int m){
		rows=n; columns=m;
		std::cout<<"create a matrix with dimensions n=" << n<< " m= "<<m<<std::endl;
		A=new int*[n];
		for(int i=0; i< n; i++)
			A[i]=new int[m];
		int k=0;	
		for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			A[i][j]	=k++;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++) std::cout<< A[i][j]	<< " ";	
			std::cout<<std::endl;			
		}

	}
	
	void deleteMatrix(){
	    for (int i = 0; i < rows; ++i) {
	        delete[] A[i];
	    }
	    delete[] A;		
	} 
	
};

class AxB{
	public:

	int n=0,m=0,p=0;
	AxB(int** a, int** b){
		int** t=a;
		std::cout<<"AxB" << std::endl;
	    while (t[n] != NULL) ++n;
	    std::cout<<"n =" << n << std::endl;
		while (a[0][m] != '\0') ++m;
		std::cout<<"m =" << m << std::endl;
		 
		//std::cout<<"a matrix with dimensions n=" << n <<std::endl;
	}
}; 

int main(int argc, char** argv) {
	Mx<int**> a(2,3);
	Mx<int**> b(3,2);
	//std::cout<<"main()" << std::endl;
	
	AxB c(a.A, b.A);
	
	//std::cout<<"after c" << std::endl;
	a.deleteMatrix();
	b.deleteMatrix();
	
	return 0;
}
