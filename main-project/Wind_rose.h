#ifndef WIND_ROSE_H
#define WIND_ROSE_H

#include "constants.h"
struct date 
{
	int day; // ����� ��������������� ����� 
	int month; // ����� ��������������� ����� 
};
	struct weather 
	{
		date day_month; 
		char direction[MAX_STRING_SIZE]; // ����������� ����� (North, NorthEast, East, SouthEast, South, SouthWest, West, NorthWest) 
		float speed; // �������� ����� � �/� (������� ��������������� �����)
	};

#endif