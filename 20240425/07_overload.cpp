#include <iostream>
using namespace std;

// 預設引數 (Default Argument)
int sum(int a, int b=20)
{
  int result;

  result = a + b;

  return (result);
}

// 函數多載 (Function Overloading) - 加總兩個整數
int add(int a, int b) {
    return a + b;
}

// 函數多載 (Function Overloading) - 加總三個整數
int add(int a, int b, int c) {
    return a + b + c;
}

// 函數多載 (Function Overloading) - 加總兩個雙精度浮點數
double add(double a, double b) {
    return a + b;
}

int main ()
{

    /* 函數多載 (Overloaded Functions),
       (1) 編譯器會根據提供的引數 (arguments) 判斷要呼叫哪個版本的函數。
       (2) 函數必須在參數 (parameters) 的數量或型別上有所不同。
    */
    std::cout << add(2, 3) << std::endl;         // 呼叫第一個 add 函數
    std::cout << add(2, 3, 4) << std::endl;      // 呼叫第二個 add 函數
    std::cout << add(2.5, 3.7) << std::endl;     // 呼叫第三個 add 函數

   // 區域變數 (Local Variables)
   int a = 100;
   int b = 200;
   int result;

   // 傳遞 (Pass) 參數 (parameters) a 和 b，因此 b 的預設值 20 會被覆寫
   result = sum(a, b);
   cout << "總值是 :" << result << endl;

   // 只傳遞 (Pass) 參數 (parameter) a，因此 b 使用預設值 20
   result = sum(a);
   cout << "總值是 :" << result << endl;


   return 0;
}