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

int main()
{
	int arr[] = {5, 2, 4, 3, 1};
	int n = sizeof(arr) / sizeof(int);
	int *ptr=sort(arr, n);
	for(int i=0; i< n; i++)
		cout << *ptr++ << " ";
	return 0;
}

