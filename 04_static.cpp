#include <iostream>
 
// ��??�� 
void func(void);
 
static int count = 10; /* ����?�q */
 
int main()
{
    while(count--)
    {
       func();
    }
    return 0;
}
// ��?�w?
void func( void )
{
    static int i = 5; // ����???�q
    i++;
    std::cout << "?�q i ? " << i ;
    std::cout << " , ?�q count ? " << count << std::endl;
}
