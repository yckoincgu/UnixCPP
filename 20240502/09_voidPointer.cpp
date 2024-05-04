// C Program to demonstrate that a void pointer
// can hold the address of any type-castable type

#include <stdio.h>
int main()
{
	int a = 10;
	char b = 'x';

	// void pointer holds address of int 'a'
	void* ptr = &a;
	// The void pointer 'ptr' is cast to an integer pointer
    // using '(int*)ptr' Then, the value is dereferenced
    // with `*(int*)ptr` to get the value at that memory
    // location
    printf("%d\n", *(int*)ptr);	
    
    
    
	// void pointer holds address of char 'b'
	ptr = &b;
	printf("%c", *(char*)ptr);	
}

