#include "filter.h"
#include <cstring>
#include <iostream>
weather** filter(weather* array[], int size, bool (*check)(weather* element), int& result_size) 
{ 
	weather** result = new weather * [size];
	result_size = 0; 
	for (int i = 0; i < size; ++i) { 
		if (check(array[i])) {
			result[result_size++] = array[i]; 
		} }
	return result; }

bool check_speed(weather* element) {
	return element->speed > 5.0;
}

bool check_direction(weather* element) {
	return strcmp(element->direction, "West") == 0 || strcmp(element->direction, "NorthWest") == 0 || strcmp(element->direction, "North") == 0; 
}