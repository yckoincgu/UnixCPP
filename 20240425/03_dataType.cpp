#include<iostream>  
#include <limits>
 
using namespace std;  
  
int main()  
{  
    cout << "type: \t\t" << "************size**************"<< endl;  
    cout << "bool: \t\t" << "┮??" << sizeof(bool);  
    cout << "\t程" << (numeric_limits<bool>::max)();  
    cout << "\t\t程" << (numeric_limits<bool>::min)() << endl;  
    cout << "char: \t\t" << "┮??" << sizeof(char);  
    cout << "\t程" << (numeric_limits<char>::max)();  
    cout << "\t\t程" << (numeric_limits<char>::min)() << endl;  
    cout << "signed char: \t" << "┮??" << sizeof(signed char);  
    cout << "\t程" << (numeric_limits<signed char>::max)();  
    cout << "\t\t程" << (numeric_limits<signed char>::min)() << endl;  
    cout << "unsigned char: \t" << "┮??" << sizeof(unsigned char);  
    cout << "\t程" << (numeric_limits<unsigned char>::max)();  
    cout << "\t\t程" << (numeric_limits<unsigned char>::min)() << endl;  
    cout << "wchar_t: \t" << "┮??" << sizeof(wchar_t);  
    cout << "\t程" << (numeric_limits<wchar_t>::max)();  
    cout << "\t\t程" << (numeric_limits<wchar_t>::min)() << endl;  
    cout << "short: \t\t" << "┮??" << sizeof(short);  
    cout << "\t程" << (numeric_limits<short>::max)();  
    cout << "\t\t程" << (numeric_limits<short>::min)() << endl;  
    cout << "int: \t\t" << "┮??" << sizeof(int);  
    cout << "\t程" << (numeric_limits<int>::max)();  
    cout << "\t程" << (numeric_limits<int>::min)() << endl;  
    cout << "unsigned: \t" << "┮??" << sizeof(unsigned);  
    cout << "\t程" << (numeric_limits<unsigned>::max)();  
    cout << "\t程" << (numeric_limits<unsigned>::min)() << endl;  
    cout << "long: \t\t" << "┮??" << sizeof(long);  
    cout << "\t程" << (numeric_limits<long>::max)();  
    cout << "\t程" << (numeric_limits<long>::min)() << endl;  
    cout << "unsigned long: \t" << "┮??" << sizeof(unsigned long);  
    cout << "\t程" << (numeric_limits<unsigned long>::max)();  
    cout << "\t程" << (numeric_limits<unsigned long>::min)() << endl;  
    cout << "double: \t" << "┮??" << sizeof(double);  
    cout << "\t程" << (numeric_limits<double>::max)();  
    cout << "\t程" << (numeric_limits<double>::min)() << endl;  
    cout << "long double: \t" << "┮??" << sizeof(long double);  
    cout << "\t程" << (numeric_limits<long double>::max)();  
    cout << "\t程" << (numeric_limits<long double>::min)() << endl;  
    cout << "float: \t\t" << "┮??" << sizeof(float);  
    cout << "\t程" << (numeric_limits<float>::max)();  
    cout << "\t程" << (numeric_limits<float>::min)() << endl;  
    cout << "size_t: \t" << "┮??" << sizeof(size_t);  
    cout << "\t程" << (numeric_limits<size_t>::max)();  
    cout << "\t程" << (numeric_limits<size_t>::min)() << endl;  
    cout << "string: \t" << "┮??" << sizeof(string) << endl;  
    // << "\t程" << (numeric_limits<string>::max)() << "\t程" << (numeric_limits<string>::min)() << endl;  
    cout << "type: \t\t" << "************size**************"<< endl;  
    return 0;  
}
