#include "filer.h"
#include "constants.h"
#include <fstream>
#include <cstring>
#include <iostream>

date convert(char* str) {
     date result;
    char* context = NULL;
    char* str_number = strtok_s(str, " ", &context);
    if (str_number == NULL) { 
        result.day = 0; 
        result.month = 0; 
        return result; }

    result.day = atoi(str_number);
    str_number = strtok_s(NULL, " ", &context);
    if (str_number == NULL) {
        result.month = 0;
        return result;
    }

    result.month = atoi(str_number);
    return result;
}

void read(const char* file_name, weather* array[], int& size) {
    std::ifstream file(file_name);
    if (file.is_open()) {
         size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
     while (!file.eof() )
        {
            weather* item = new weather;
           /* file >> tmp_buffer;
            std::cerr << tmp_buffer;

            file >> tmp_buffer;
            std::cerr << tmp_buffer;

                       file >> tmp_buffer;
            std::cerr << tmp_buffer;*/

           // item->day_month = convert(tmp_buffer);
          //  std::cerr << tmp_buffer;
            file >> tmp_buffer;
            item->day_month.day = atoi(tmp_buffer);
            file >> tmp_buffer;
            item->day_month.month = atoi(tmp_buffer);
            file >> item->direction;
          //  item->direction = tmp_buffer;
            file >> tmp_buffer;
            item->speed = atoi(tmp_buffer);
           
         //   std::cout << item->day_month.day<< " " << item->day_month.month << " " << item->direction << " " << item->speed;
            //std::cout << std::endl;
            //file >> item->day_month.day;
            //file >> item->day_month.month;
            //file >> item->direction;
            //file >> item->speed;

            //std::cout << item->day_month.day << item->day_month.month << item->direction << item->speed;
            array[size++] = item;
        }
        file.close();
    }
    else {
        throw "Ошибка открытия файла";
    }
}
