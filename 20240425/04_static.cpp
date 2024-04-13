#include <iostream>
 
// ㄧ?? 
void func(void);
 
static int count = 10; /* 办 */
 
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
    static int i = 5; // Ы场
    i++;
    std::cout << "Ы场 i = " << i ;
    std::cout << " , 办 count = " << count << std::endl;
}
