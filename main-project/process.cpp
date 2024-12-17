#include "processing.h"
#include <string.h>
double process(weather* array[], int size, int month) {
	double total_speed = 0.0;
	int count = 0; 
	for (int i = 0; i < size; ++i) {
		if (array[i]->day_month.month == month) {
			total_speed += array[i]->speed; ++count; 
		} 
	}
	return (count > 0) ? (total_speed / count) : 0.0; }