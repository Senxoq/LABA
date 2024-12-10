#ifndef WIND_ROSE.H
#define WIND_ROSE.H

#include "constants.h"

struct date
{
    int day;
    int month;
};
struct direction
{
  char direction[MAX_STRING_SIZE]
};

struct speed 
{
  double speed;
};

#endif
