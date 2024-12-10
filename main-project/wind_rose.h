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
  char direction[MAX_STRING_SIZE];
};

struct all
{ date start;
direction mid;
  double speed;
};

#endif
