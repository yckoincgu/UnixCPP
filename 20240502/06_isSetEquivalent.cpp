// C++ program to implement the approach

#include <bits/stdc++.h>
using namespace std;

void swap(int *ptrX, int *ptrY){
	int temp=0;
	temp=*ptrX; *ptrX=*ptrY; *ptrY=temp;
}

// Sorting function
int* sort(int *arr, int n)
{
	int *ptrX, *ptrY, i,j;
	for(i=0; i< n; i++){
		ptrX=&arr[i];
		for(j=i+1; j< n; j++){
			ptrY=&arr[j];
			if(*ptrX<*ptrY) swap(ptrX, ptrY);	
		}
	}
	return arr;
}


// Function to check if both arrays are equal
bool isSetEquivalent(int *A, int *B,
				int n, int m)
{
	// If lengths of array are not equal
	// means array are not equal
	if (n != m)
		return false;

	// Sort both arrays
	int *ptrX=sort(A, n);
	int *ptrY=sort(B, m);

	// Linearly compare elements
	for (int i = 0; i < n; i++)
		if (*ptrX++ != *ptrY++)
			return false;

	// If elements are same
	return true;
}

// Driver Code
int main()
{
	int arr1[] = { 1, 2, 3, 4, 5 };
	int arr2[] = { 5, 4, 3, 2, 1 };
	int n = sizeof(arr1) / sizeof(int);
	int m = sizeof(arr2) / sizeof(int);

	// Function call
	if (isSetEquivalent(arr1, arr2, n, m))
		cout << "Equal";
	else
		cout << "Not Equal";
	return 0;
}

