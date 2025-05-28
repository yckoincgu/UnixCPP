#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    // 設定欄位寬度
    const int city_width = 20;
    const int date_width = 20;
    const int high_temp_width = 30;
    const int low_temp_width = 30;

    // 顯示表頭
    cout << left << setw(city_width) << "City"
         << left << setw(date_width) << "Date"
         << right << setw(high_temp_width) << "Highest Temperature"
         << right << setw(low_temp_width) << "Lowest Temperature" << endl;

    // 分隔線
    cout << setfill('-') 
         << setw(city_width + date_width + high_temp_width + low_temp_width) << "" 
         << setfill(' ') << endl;

    // 範例資料列
    cout << left << setw(city_width) << "Taipei"
         << left << setw(date_width) << "2025-05-28"
         << right << setw(high_temp_width) << "34.5°C"
         << right << setw(low_temp_width) << "26.3°C" << endl;

    cout << left << setw(city_width) << "Tokyo"
         << left << setw(date_width) << "2025-05-28"
         << right << setw(high_temp_width) << "29.0°C"
         << right << setw(low_temp_width) << "21.5°C" << endl;

    cout << left << setw(city_width) << "New York"
         << left << setw(date_width) << "2025-05-28"
         << right << setw(high_temp_width) << "23.2°C"
         << right << setw(low_temp_width) << "17.8°C" << endl;

    return 0;
}