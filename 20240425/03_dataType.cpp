#include<iostream>
#include <limits>
#include <string> // 記得包含 string 的標頭檔

using namespace std;

int main()
{
    cout << "型別: \t\t" << "************大小**************"<< endl;
    cout << "布林 (bool): \t\t" << "所佔位元組: " << sizeof(bool);
    cout << "\t最大值: " << (numeric_limits<bool>::max)();
    cout << "\t\t最小值: " << (numeric_limits<bool>::min)() << endl;
    cout << "字元 (char): \t\t" << "所佔位元組: " << sizeof(char);
    cout << "\t最大值: " << (numeric_limits<char>::max)();
    cout << "\t\t最小值: " << (numeric_limits<char>::min)() << endl;
    cout << "有符號字元 (signed char): \t" << "所佔位元組: " << sizeof(signed char);
    cout << "\t最大值: " << (numeric_limits<signed char>::max)();
    cout << "\t\t最小值: " << (numeric_limits<signed char>::min)() << endl;
    cout << "無符號字元 (unsigned char): \t" << "所佔位元組: " << sizeof(unsigned char);
    cout << "\t最大值: " << (numeric_limits<unsigned char>::max)();
    cout << "\t\t最小值: " << (numeric_limits<unsigned char>::min)() << endl;
    cout << "寬字元 (wchar_t): \t" << "所佔位元組: " << sizeof(wchar_t);
    cout << "\t最大值: " << (numeric_limits<wchar_t>::max)();
    cout << "\t\t最小值: " << (numeric_limits<wchar_t>::min)() << endl;
    cout << "短整數 (short): \t\t" << "所佔位元組: " << sizeof(short);
    cout << "\t最大值: " << (numeric_limits<short>::max)();
    cout << "\t\t最小值: " << (numeric_limits<short>::min)() << endl;
    cout << "整數 (int): \t\t" << "所佔位元組: " << sizeof(int);
    cout << "\t最大值: " << (numeric_limits<int>::max)();
    cout << "\t\t最小值: " << (numeric_limits<int>::min)() << endl;
    cout << "無符號整數 (unsigned): \t" << "所佔位元組: " << sizeof(unsigned);
    cout << "\t最大值: " << (numeric_limits<unsigned>::max)();
    cout << "\t\t最小值: " << (numeric_limits<unsigned>::min)() << endl;
    cout << "長整數 (long): \t\t" << "所佔位元組: " << sizeof(long);
    cout << "\t最大值: " << (numeric_limits<long>::max)();
    cout << "\t\t最小值: " << (numeric_limits<long>::min)() << endl;
    cout << "無符號長整數 (unsigned long): \t" << "所佔位元組: " << sizeof(unsigned long);
    cout << "\t最大值: " << (numeric_limits<unsigned long>::max)();
    cout << "\t\t最小值: " << (numeric_limits<unsigned long>::min)() << endl;
    cout << "雙精度浮點數 (double): \t" << "所佔位元組: " << sizeof(double);
    cout << "\t最大值: " << (numeric_limits<double>::max)();
    cout << "\t\t最小值: " << (numeric_limits<double>::min)() << endl;
    cout << "長雙精度浮點數 (long double): \t" << "所佔位元組: " << sizeof(long double);
    cout << "\t最大值: " << (numeric_limits<long double>::max)();
    cout << "\t\t最小值: " << (numeric_limits<long double>::min)() << endl;
    cout << "浮點數 (float): \t\t" << "所佔位元組: " << sizeof(float);
    cout << "\t最大值: " << (numeric_limits<float>::max)();
    cout << "\t\t最小值: " << (numeric_limits<float>::min)() << endl;
    cout << "尺寸型別 (size_t): \t" << "所佔位元組: " << sizeof(size_t);
    cout << "\t最大值: " << (numeric_limits<size_t>::max)();
    cout << "\t\t最小值: " << (numeric_limits<size_t>::min)() << endl;
    cout << "字串 (string): \t" << "所佔位元組: " << sizeof(string) << endl;
    // cout << "\t最大值: " << (numeric_limits<string>::max)() << "\t最小值: " << (numeric_limits<string>::min)() << endl; // string 沒有 numeric_limits 的 max 和 min
    cout << "型別: \t\t" << "************大小**************"<< endl;
    return 0;
}