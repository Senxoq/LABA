#include <iostream>
#include <iomanip>
using namespace std;
#include "constants.h"
#include "file_reader.h"
#include "Wind_rose.h"
int main()
{
    cout << "Laboratory work #8. GIT\n";
    cout << "Variant #6. The Wind Rose\n";
    cout << "Author: Arkhip Kupchenko\n";

    weather* weather_data[MAX_FILE_ROWS_COUNT]; 
    int size;
    try {
        read("data.txt", weather_data, size);
        for (int i = 0; i < size; i++) {
            cout << weather_data[i]->day_month.day << ' '; 
            cout << weather_data[i]->day_month.month << '\n';
            cout << weather_data[i]->direction << '\n'; 
            cout << weather_data[i]->speed << '\n';
            cout << '\n'; 
        } 
        for (int i = 0; i < size; i++) {
            delete weather_data[i];
        } }
    catch (const char* error) { 
        cout << error << '\n'; 
    } return 0;

    cout << "Group: 24PING_1D\n";
    return 0;
}
