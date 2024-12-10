#include <iostream>
using namespace std;
#include "wind_rose.h"
#include "file_reader.h"
#include "constants.h"
int main()
{
    setlocale(LC_ALL, "Russian");
     cout << "Laboratory work #8. GIT\n";
    cout << "Variant #1. Роза ветров\n";
    cout << "Author: Archip Kupchenko\n";
    cout << "Group: XX\n";
    int size;
    wind_rose* all[MAX_FILE_ROWS_COUNT];
    try
    { 
        read("data.txt", all, size);
        cout << "****РОЗА ВЕТРОВ****\n\n";
        for (int i = 0; i < size; i++) {
            cout << "Дата ";
            /*Выводит день*/
            cout << all[i]->start.day << '\n';
            /*Выводит месяц*/
            cout << all[i]->start.month << '\n';
            cout << "Направление ветра ";
            cout << all[i]->mid.direction << '\n';
            cout << "Скорость в м/c";
            cout << all[i]->speed << '\n';
            cout << '\n';
        }
        for (int i = 0; i < size; i++)
        {
            delete all[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    return 0;
}
