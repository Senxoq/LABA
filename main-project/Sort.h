#ifndef SORT_H
#define SORT_H
#include "Wind_rose.h"
void shaker_sort(weather* array[], int size, int (*compare)(const weather*, const weather*));
void merge(weather* array[], int left, int mid, int right, int (*compare)(const weather*, const weather*));
void merge_sort(weather* array[], int left, int right, int (*compare)(const weather*, const weather*));
int compare_by_speed_desc(const weather* a, const weather* b);
int compare_by_direction_date(const weather* a, const weather* b);

	


#endif