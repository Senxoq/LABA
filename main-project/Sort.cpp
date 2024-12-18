#include "Wind_rose.h"
#include "Sort.h"
#include <string.h>
#include <algorithm> 

int compare_by_speed_desc(const weather* a, const weather* b) {
    return (a->speed < b->speed) - (a->speed > b->speed);
}

int compare_by_direction_date(const weather* a, const weather* b) {
    int direction_cmp = strcmp(a->direction, b->direction);
    if (direction_cmp != 0) return direction_cmp;
    if (a->day_month.month != b->day_month.month)
        return a->day_month.month - b->day_month.month;
    return a->day_month.day - b->day_month.day;
}

void shaker_sort(weather* array[], int size, int (*compare)(const weather*, const weather*)) {
    bool swapped = true;
    int start = 0;
    int end = size - 1;
    while (swapped) {
        swapped = false;
        for (int i = start; i < end; ++i) {
            if (compare(array[i], array[i + 1]) > 0) {
                std::swap(array[i], array[i + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
        swapped = false;
        --end;
        for (int i = end - 1; i >= start; --i) {
            if (compare(array[i], array[i + 1]) > 0) {
                std::swap(array[i], array[i + 1]);
                swapped = true;
            }
        }
        ++start;
    }
}

void merge(weather* array[], int left, int mid, int right, int (*compare)(const weather*, const weather*)) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    weather** L = new weather * [n1];
    weather** R = new weather * [n2];

    for (int i = 0; i < n1; ++i)
        L[i] = array[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = array[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (compare(L[i], R[j]) <= 0) {
            array[k] = L[i];
            ++i;
        }
        else {
            array[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        array[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        array[k] = R[j];
        ++j;
        ++k;
    }

    delete[] L;
    delete[] R;
}

void merge_sort(weather* array[], int left, int right, int (*compare)(const weather*, const weather*)) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(array, left, mid, compare);
        merge_sort(array, mid + 1, right, compare);

        merge(array, left, mid, right, compare);
    }
}

