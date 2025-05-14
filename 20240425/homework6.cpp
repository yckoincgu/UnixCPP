#include <iostream>
#include <vector>
#include <string>
#include <iomanip> 


struct WeatherData {
    std::string city;
    std::string date;
    std::string highTemp;
    std::string lowTemp;
};

int main() {
    // --- Configuration ---
    const int CITY_WIDTH = 20;
    const int DATE_WIDTH = 20;
    const int TEMP_WIDTH = 30; 


    const int TOTAL_TABLE_WIDTH = CITY_WIDTH + DATE_WIDTH + TEMP_WIDTH + TEMP_WIDTH;

   
    std::vector<WeatherData> weatherLog = {
        {"New York", "2024-07-15", "30 C (86 F)", "22 C (72 F)"},
        {"New York", "2024-07-16", "31 C (88 F)", "23 C (73 F)"},
        {"New York", "2024-07-17", "29 C (84 F)", "21 C (70 F)"},
        {"New York", "2024-07-18", "32 C (90 F)", "24 C (75 F)"},

        {"London", "2024-07-15", "22 C (72 F)", "15 C (59 F)"},
        {"London", "2024-07-16", "24 C (75 F)", "16 C (61 F)"},
        {"London", "2024-07-17", "23 C (73 F)", "14 C (57 F)"},
        {"London", "2024-07-18", "25 C (77 F)", "17 C (63 F)"},

        {"Tokyo", "2024-07-15", "32 C (90 F)", "25 C (77 F)"},
        {"Tokyo", "2024-07-16", "33 C (91 F)", "26 C (79 F)"},
        {"Tokyo", "2024-07-17", "31 C (88 F)", "24 C (75 F)"},
        {"Tokyo", "2024-07-18", "34 C (93 F)", "27 C (81 F)"},

        {"Paris", "2024-07-15", "25 C (77 F)", "18 C (64 F)"},
        {"Paris", "2024-07-16", "27 C (81 F)", "19 C (66 F)"},
        {"Paris", "2024-07-17", "26 C (79 F)", "17 C (63 F)"},
        {"Paris", "2024-07-18", "28 C (82 F)", "20 C (68 F)"}
    };

  
    std::cout << std::setfill('-') << std::setw(TOTAL_TABLE_WIDTH) << "" << std::endl;
    std::cout << std::setfill(' '); 

    
    std::cout << std::left << std::setw(CITY_WIDTH) << "City"
              << std::left << std::setw(DATE_WIDTH) << "Date"
              << std::right << std::setw(TEMP_WIDTH) << "Highest Temperature"
              << std::right << std::setw(TEMP_WIDTH) << "Lowest Temperature"
              << std::endl;

    
    std::cout << std::setfill('-') << std::setw(TOTAL_TABLE_WIDTH) << "" << std::endl;
    std::cout << std::setfill(' '); 
    
    for (const auto& entry : weatherLog) {
        std::cout << std::left << std::setw(CITY_WIDTH) << entry.city
                  << std::left << std::setw(DATE_WIDTH) << entry.date
                  << std::right << std::setw(TEMP_WIDTH) << entry.highTemp
                  << std::right << std::setw(TEMP_WIDTH) << entry.lowTemp
                  << std::endl;
    }

    std::cout << std::setfill('-') << std::setw(TOTAL_TABLE_WIDTH) << "" << std::endl;
    std::cout << std::setfill(' '); 

    return 0;
}
