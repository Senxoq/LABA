#ifndef FILTER_H
#define FILTER_H
#include "Wind_rose.h"
weather** filter(weather* array[], int size, bool (*check)(weather* element), int& result_size);
bool check_speed(weather* element);
bool check_direction(weather* element);
	

#endif


