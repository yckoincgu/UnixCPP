/*
	(1) little characters, a,b,c are used for object instances
	(2) big characters A,B,C are used for matrix
*/
#include <iostream>

#ifndef Matrix
#define Matrix


template <typename T>
class Matrix
{
public:
	T A;		// the first type of matrix
	int n, m;	// rows=n; columns=m;
	Matrix(int n, int m):n(n),m(m);
	void printMatrixDimension();
	
	void printMatrix();
	
	void deleteMatrix();
	
};


template<typename T>
class AxB{
	public:
	T C; 	// the second type of matrix
	int n,m,p;
	AxB(Matrix<T> a, Matrix<T> b);
	void deleteMatrix();
	
}; 

#endif
