#include <iostream>
//#include "Matrix.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
template <typename T>
class Mx
{
public:
	T A;
	Mx(int n, int m){
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
	
};



int main(int argc, char** argv) {
	Mx<int**> a(2,3);
	Mx<int**> b(3,2);
	
	return 0;
}
