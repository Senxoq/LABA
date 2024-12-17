#include <iostream>
#include <iomanip>
using namespace std;
#include "constants.h"
#include "filer.h"
#include "Wind_rose.h"
#include "Filter.h"
#include "Sort.h"
int main()
{
    cout << "Laboratory work #8. GIT\n";
    cout << "Variant #6. The Wind Rose\n";
    cout << "Author: Arkhip Kupchenko\n";
    weather* weather_data[MAX_FILE_ROWS_COUNT]; 
    int size;
    try {
        read("data.txt", weather_data, size);

        int result_size;
        weather** filtered_by_speed = filter(weather_data, size, check_speed, result_size);
        cout << "\nFiltered by speed (> 5.0): " << result_size << " elements\n"; 
        for (int i = 0; i < result_size; ++i) {
            cout << "Speed: " << filtered_by_speed[i]->speed << ", Direction: " << filtered_by_speed[i]->direction << "\n"; 
        }
  
        weather** filtered_by_direction = filter(weather_data, size, check_direction, result_size); 
        cout << "\nFiltered by direction (West, NorthWest, North): " << result_size << " elements\n"; 
        for (int i = 0; i < result_size; ++i) { 
            cout << "Speed: " << filtered_by_direction[i]->speed << ", Direction: " << filtered_by_direction[i]->direction << "\n"; }


        shaker_sort(weather_data, size, compare_by_speed_desc);
        cout << "\nSorted by speed (descending):\n";
        for (int i = 0; i < size; ++i) {
            cout << "Speed: " << weather_data[i]->speed << ", Direction: " << weather_data[i]->direction << "\n";
        }
        merge_sort(weather_data, 0, size - 1, compare_by_direction_date); 
        cout << "\nSorted by direction and date:\n"; 
        for (int i = 0; i < size; ++i) { 
            cout << weather_data[i]->day_month.day << ' ';
            cout << weather_data[i]->day_month.month << ' '; 
            cout << weather_data[i]->direction << ' ';
            cout << weather_data[i]->speed << ' ';
            cout << '\n';
        }

        for (int i = 0; i < size; i++) {
            cout << weather_data[i]->day_month.day << ' '; 
            cout << weather_data[i]->day_month.month << ' ';
            cout << weather_data[i]->direction << ' '; 
            cout << weather_data[i]->speed << ' ';
            cout << '\n'; 
        } 
        delete[] filtered_by_speed;
        delete[] filtered_by_direction;
        for (int i = 0; i < size; i++) {
            delete weather_data[i];
        } }
    catch (const char* error) { 
        cout << error << '\n'; 
    } return 0;

    cout << "Group: 24PING_1D\n";
    return 0;
}
