#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <cwchar>  // For wchar_t support
#include <clocale> // For setlocale()

using namespace std;

int main() {
    // Set fixed column widths
    const int type_width = 25;
    const int size_width = 15;
    const int value_width = 40;

    // Header
    cout << left << setw(type_width) << "Types"
         << right << setw(size_width) << "unit bytes"
         << right << setw(value_width) << "maximun value"
         << right << setw(value_width) << "minimun values" << endl;
    cout << setfill('-') << setw(type_width + size_width + value_width*2) << "" << setfill(' ') << endl;

    // Boolean
    cout << left << setw(type_width) << "bool"
         << right << setw(size_width) << sizeof(bool)
         << right << setw(value_width) << (numeric_limits<bool>::max)()
         << right << setw(value_width) << (numeric_limits<bool>::min)() << endl;

    // Character types
    cout << left << setw(type_width) << "char"
         << right << setw(size_width) << sizeof(char)
         << right << setw(value_width) << static_cast<int>(numeric_limits<char>::max())
         << right << setw(value_width) << static_cast<int>(numeric_limits<char>::min()) << endl;

    cout << left << setw(type_width) << "signed char"
         << right << setw(size_width) << sizeof(signed char)
         << right << setw(value_width) << static_cast<int>(numeric_limits<signed char>::max())
         << right << setw(value_width) << static_cast<int>(numeric_limits<signed char>::min()) << endl;

    cout << left << setw(type_width) << "unsigned char"
         << right << setw(size_width) << sizeof(unsigned char)
         << right << setw(value_width) << static_cast<int>(numeric_limits<unsigned char>::max())
         << right << setw(value_width) << static_cast<int>(numeric_limits<unsigned char>::min()) << endl;


    // Integer types
    cout << left << setw(type_width) << "short integer:"
         << right << setw(size_width) << sizeof(short)
         << right << setw(value_width) << numeric_limits<short>::max()
         << right << setw(value_width) << numeric_limits<short>::min() << endl;

    cout << left << setw(type_width) << "integer"
         << right << setw(size_width) << sizeof(int)
         << right << setw(value_width) << numeric_limits<int>::max()
         << right << setw(value_width) << numeric_limits<int>::min() << endl;

    cout << left << setw(type_width) << "unsigned integer"
         << right << setw(size_width) << sizeof(unsigned)
         << right << setw(value_width) << numeric_limits<unsigned>::max()
         << right << setw(value_width) << numeric_limits<unsigned>::min() << endl;

         cout << left << setw(type_width) << "long integer:"
         << right << setw(size_width) << sizeof(long)
         << right << setw(value_width) << numeric_limits<long>::max()
         << right << setw(value_width) << numeric_limits<long>::min() << endl;

    cout << left << setw(type_width) << "unsigned long integer"
         << right << setw(size_width) << sizeof(unsigned long)
         << right << setw(value_width) << numeric_limits<unsigned long>::max()
         << right << setw(value_width) << numeric_limits<unsigned long>::min() << endl;
         

    // Floating-point types
    cout << left << setw(type_width) << "float"
         << right << setw(size_width) << sizeof(float)
         << right << setw(value_width) << scientific << numeric_limits<float>::max()
         << right << setw(value_width) << scientific << numeric_limits<float>::min() << endl;

    cout << left << setw(type_width) << "double"
         << right << setw(size_width) << sizeof(double)
         << right << setw(value_width) << scientific << numeric_limits<double>::max()
         << right << setw(value_width) << scientific << numeric_limits<double>::min() << endl;

    cout << left << setw(type_width) << "long double"
         << right << setw(size_width) << sizeof(long double)
         << right << setw(value_width) << scientific << numeric_limits<long double>::max()
         << right << setw(value_width) << scientific << numeric_limits<long double>::min() << endl;         

    cout << left << setw(type_width) << "wchar_t"
    << right << setw(size_width) << sizeof(wchar_t)
    << right << setw(value_width) << numeric_limits<wchar_t>::max()
    << right << setw(value_width) << numeric_limits<wchar_t>::min() << endl;



    cout << left << setw(type_width) << "size_t"
         << right << setw(size_width) << sizeof(size_t)
         << right << setw(value_width) << numeric_limits<size_t>::max()
         << right << setw(value_width) << numeric_limits<size_t>::min() << endl;

    // String type
    cout << left << setw(type_width) << "string"
    << right << setw(size_width) << sizeof(string)
    << right << setw(value_width) << ""
    << right << setw(value_width) << "" << endl;

    
    

    return 0;
}