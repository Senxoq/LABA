#ifndef WIND_ROSE_H
#define WIND_ROSE_H

#include "constants.h"
struct date 
{
	int day; // целое неотрицательное число 
	int month; // целое неотрицательное число 
};
	struct weather 
	{
		date day_month; 
		char direction[MAX_STRING_SIZE]; // направление ветра (North, NorthEast, East, SouthEast, South, SouthWest, West, NorthWest) 
		float speed; // скорость ветра в м/с (дробное неотрицательное число)
	};

#endif