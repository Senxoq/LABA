#include "filer.h"
#include "constants.h"
#include <fstream>
#include <cstring>
#include <iostream>


void read(const char* file_name, weather* array[], int& size) {
    std::ifstream file(file_name);
    if (file.is_open()) {
         size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
     while (!file.eof() )
        {
            weather* item = new weather;
            file >> tmp_buffer;
            item->day_month.day = atoi(tmp_buffer);
            file >> tmp_buffer;
            item->day_month.month = atoi(tmp_buffer);
            file >> item->direction;
            file >> tmp_buffer;
            item->speed = atoi(tmp_buffer);
            array[size++] = item;
        }
        file.close();
    }
    else {
        throw "Ошибка открытия файла";
    }
}
