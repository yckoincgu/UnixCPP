#include <iostream>

void func(void);

static int count = 10; /* 全域靜態變數 */

int main()
{
    while(count--)
    {
       func();
    }
    return 0;
}

void func( void )
{
    static int i = 5; // 局部靜態變數
    i++;
    std::cout << "局部靜態變數 i = " << i ;
    std::cout << " , 全域靜態變數 count = " << count << std::endl;
}