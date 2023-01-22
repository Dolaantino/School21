#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INT 2147483647
#define MIN_INT -2147483646
#define S21_EPS 1e-16
#define S21_EPS_T 1e-6
#define S21_M_PI 3.14159265358979323846264338327950288
#define S21_DBL_MAX 1.79769e+308
#define S21_INF (__builtin_inff())
#define S21_NAN (__builtin_nanf(""))

#define s21_finite(x) __builtin_isfinite(x)

#define s21_nan(x) __builtin_isnan(x)
#define s21_inf(x) __builtin_isinf(x)

#define S21_LONG_LONG_MAX 9223372036854775807

int s21_abs(int x);

long double s21_fabs(double x);

long double s21_factorial(double x);

double s21_int_pow(double base, unsigned int exp);

int pow_special_case(double base, double exp, long double *result);

long double s21_pow(double base, double exp);

long double s21_sin(double x);

long double s21_cos(double x);

long double s21_tan(double x);

long double s21_atan(double x);

long double s21_asin(double x);

long double s21_acos(double x);

long double s21_exp(double x);

long double s21_sqrt(double x);

long double s21_ceil(double x);

long double s21_floor(double x);

long double s21_fmod(double x, double y);

long double s21_log(double x);

#endif  // SRC_S21_MATH_H_
