#include <iostream>
 
// 函??明 
void func(void);
 
static int count = 10; /* 全局?量 */
 
int main()
{
    while(count--)
    {
       func();
    }
    return 0;
}
// 函?定?
void func( void )
{
    static int i = 5; // 局部???量
    i++;
    std::cout << "?量 i ? " << i ;
    std::cout << " , ?量 count ? " << count << std::endl;
}
