#ifndef DATA_STAT_H
#define DATA_STAT_H
#include <stdio.h>
#include <math.h>
#include "data_stat.c"

double max(double *data, int n);
double min(double *data, int n);
double mean(double *data, int n);
double variance(double *data, int n);

#endif
