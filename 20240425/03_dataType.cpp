#include<iostream>  
#include <limits>
 
using namespace std;  
  
int main()  
{  
    cout << "type: \t\t" << "************size**************"<< endl;  
    cout << "bool: \t\t" << "�ҥe�r??�G" << sizeof(bool);  
    cout << "\t�̤j�ȡG" << (numeric_limits<bool>::max)();  
    cout << "\t\t�̤p�ȡG" << (numeric_limits<bool>::min)() << endl;  
    cout << "char: \t\t" << "�ҥe�r??�G" << sizeof(char);  
    cout << "\t�̤j�ȡG" << (numeric_limits<char>::max)();  
    cout << "\t\t�̤p�ȡG" << (numeric_limits<char>::min)() << endl;  
    cout << "signed char: \t" << "�ҥe�r??�G" << sizeof(signed char);  
    cout << "\t�̤j�ȡG" << (numeric_limits<signed char>::max)();  
    cout << "\t\t�̤p�ȡG" << (numeric_limits<signed char>::min)() << endl;  
    cout << "unsigned char: \t" << "�ҥe�r??�G" << sizeof(unsigned char);  
    cout << "\t�̤j�ȡG" << (numeric_limits<unsigned char>::max)();  
    cout << "\t\t�̤p�ȡG" << (numeric_limits<unsigned char>::min)() << endl;  
    cout << "wchar_t: \t" << "�ҥe�r??�G" << sizeof(wchar_t);  
    cout << "\t�̤j�ȡG" << (numeric_limits<wchar_t>::max)();  
    cout << "\t\t�̤p�ȡG" << (numeric_limits<wchar_t>::min)() << endl;  
    cout << "short: \t\t" << "�ҥe�r??�G" << sizeof(short);  
    cout << "\t�̤j�ȡG" << (numeric_limits<short>::max)();  
    cout << "\t\t�̤p�ȡG" << (numeric_limits<short>::min)() << endl;  
    cout << "int: \t\t" << "�ҥe�r??�G" << sizeof(int);  
    cout << "\t�̤j�ȡG" << (numeric_limits<int>::max)();  
    cout << "\t�̤p�ȡG" << (numeric_limits<int>::min)() << endl;  
    cout << "unsigned: \t" << "�ҥe�r??�G" << sizeof(unsigned);  
    cout << "\t�̤j�ȡG" << (numeric_limits<unsigned>::max)();  
    cout << "\t�̤p�ȡG" << (numeric_limits<unsigned>::min)() << endl;  
    cout << "long: \t\t" << "�ҥe�r??�G" << sizeof(long);  
    cout << "\t�̤j�ȡG" << (numeric_limits<long>::max)();  
    cout << "\t�̤p�ȡG" << (numeric_limits<long>::min)() << endl;  
    cout << "unsigned long: \t" << "�ҥe�r??�G" << sizeof(unsigned long);  
    cout << "\t�̤j�ȡG" << (numeric_limits<unsigned long>::max)();  
    cout << "\t�̤p�ȡG" << (numeric_limits<unsigned long>::min)() << endl;  
    cout << "double: \t" << "�ҥe�r??�G" << sizeof(double);  
    cout << "\t�̤j�ȡG" << (numeric_limits<double>::max)();  
    cout << "\t�̤p�ȡG" << (numeric_limits<double>::min)() << endl;  
    cout << "long double: \t" << "�ҥe�r??�G" << sizeof(long double);  
    cout << "\t�̤j�ȡG" << (numeric_limits<long double>::max)();  
    cout << "\t�̤p�ȡG" << (numeric_limits<long double>::min)() << endl;  
    cout << "float: \t\t" << "�ҥe�r??�G" << sizeof(float);  
    cout << "\t�̤j�ȡG" << (numeric_limits<float>::max)();  
    cout << "\t�̤p�ȡG" << (numeric_limits<float>::min)() << endl;  
    cout << "size_t: \t" << "�ҥe�r??�G" << sizeof(size_t);  
    cout << "\t�̤j�ȡG" << (numeric_limits<size_t>::max)();  
    cout << "\t�̤p�ȡG" << (numeric_limits<size_t>::min)() << endl;  
    cout << "string: \t" << "�ҥe�r??�G" << sizeof(string) << endl;  
    // << "\t�̤j�ȡG" << (numeric_limits<string>::max)() << "\t�̤p�ȡG" << (numeric_limits<string>::min)() << endl;  
    cout << "type: \t\t" << "************size**************"<< endl;  
    return 0;  
}
