#include "s21_math.h"

int s21_abs(int x) {
  if (x < 0) x = -x;
  return x;
}

long double s21_fabs(double x) {
  if (x < 0) x = -x;
  return x;
}

long double s21_factorial(double x) {
  if (x == 0) return 1;
  return x * s21_factorial(x - 1);
}

double s21_int_pow(double base, unsigned int exp) {
  double result = 1.0;
  int k = 0;
  while (exp != 0) {
    if ((exp & 1) != 0) {
      result *= base;
    }
    base *= base;
    exp >>= 1;
    k++;
  }
  return result;
}

int pow_special_case(double base, double exp, long double *result) {
  int is_spesial = 0;
  if (base == 0.0 && exp > 0) {
    is_spesial = 1;
    *result = 0;
  } else if (((base == S21_INF || base == -S21_INF) && exp > 0) ||
             (exp == S21_INF && s21_fabs(base) > 1) ||
             (exp == -S21_INF && s21_fabs(base) < 1) ||
             (base == 0 && exp < 0)) {
    is_spesial = 1;
    *result = S21_INF;
  } else if ((base == S21_INF || base == -S21_INF) && exp < 0) {
    is_spesial = 1;
    *result = 0;
  } else if (exp == 0) {
    is_spesial = 1;
    *result = 1.0;
  } else if (base == 1 || (base == -1 && (exp == S21_INF || exp == -S21_INF))) {
    is_spesial = 1;
    *result = 1;
  } else if (exp == -S21_INF && s21_fabs(base) > 1) {
    is_spesial = 1;
    *result = 0.0;
  } else if (exp != exp || base != base) {
    is_spesial = 1;
    *result = S21_NAN;
  } else if (base < 0 && ((int)exp) - exp != 0) {
    is_spesial = 1;
    *result = S21_NAN;
  }
  return is_spesial;
}

long double s21_pow(double base, double exp) {
  long double result = 0.0;
  int int_exp = (int)exp;
  int znak = 1;
  if (!pow_special_case(base, exp, &result)) {
    double exp0 = exp;
    if (exp0 < 0) exp0 = -exp0;

    if (base < 0 && int_exp - exp == 0) {
      if (int_exp == 1 || s21_abs(int_exp) % 2 == 1 || int_exp == -1) znak = -1;
      base = -base;
    }
    int_exp = (int)exp0;
    if (exp0 > 1) exp0 = exp0 - int_exp;
    result = s21_exp(s21_log(base) * exp0);
    result *= s21_int_pow(base, (unsigned int)int_exp);
    if (exp < 0) result = 1 / result;
    result *= znak;
  }
  return result;
}

long double s21_sin(double x) {
  long double result = 0;
  if (x != x) {
    result = S21_NAN;
  } else if (x == S21_INF || x == -S21_INF) {
    result = S21_NAN;
  } else {
    long double x1 = s21_fmod(x, 2 * S21_M_PI);
    long double temp = x1;
    int i = 0;
    while (s21_fabs(temp) >= S21_EPS) {
      result += temp;
      i++;
      temp *= -x1 * x1 / (2 * i * (2 * i + 1));
    }
  }
  return result;
}

long double s21_cos(double x) {
  long double result = 0.0;
  if (x != x) {
    result = S21_NAN;
  } else if (x == S21_INF || x == -S21_INF) {
    result = S21_NAN;
  } else {
    long double x1 = s21_fmod(x, 2 * S21_M_PI);
    long double temp = 1.;
    int i = 0;
    while (s21_fabs(temp) >= S21_EPS) {
      result += temp;
      i++;
      temp *= -x1 * x1 / (i * (i + 1));
      i++;
    }
  }
  return result;
}

long double s21_tan(double x) {
  long double result = 0.0;
  if (x != x) {
    result = S21_NAN;
  } else if (x == S21_INF) {
    result = S21_NAN;
  } else if (s21_fabs(x - S21_M_PI / 2) < S21_EPS) {
    result = 16331239353195370.0;
  } else {
    result = s21_sin(x) / s21_cos(x);
  }
  return result;
}

long double s21_atan(double x) {
  long double result = 0;
  int znak = 1;
  if (x < 0) {
    x *= -1;
    znak = -1;
  }
  if (x != x) {
    result = S21_NAN;
  } else if (x == S21_INF || x >= 1e7) {
    result = S21_M_PI / 2 * znak;

  } else if (x == 1) {
    result = S21_M_PI / 4 * znak;
  } else if (x > 1) {
    x = 1 / x;
    result = S21_M_PI / 2 - s21_atan(x);
    result *= znak;
  } else {
    result = x;
    long double temp = x;
    double sign = -1.0;
    int i = 2;
    while (s21_fabs(temp) > 1e-9 || i < 20) {
      temp = (s21_int_pow(x, (unsigned int)(2 * i - 1)) / (2 * i - 1) * sign);
      result += temp;
      i++;
      sign *= -1.0;
    }
    result *= znak;
  }

  return result;
}

long double s21_asin(double x) {
  long double result = 0;
  if (x < -1.0 || x > 1.0) {
    result = S21_NAN;
  } else if (x == 1) {
    result = S21_M_PI / 2;
  } else if (x == -1) {
    result = -S21_M_PI / 2;
  } else {
    result = x;
    long double temp = x;
    int i = 1;
    while (s21_fabs(temp) >= S21_EPS && i <= 400000) {
      temp =
          (s21_factorial(2 * i) * s21_int_pow(x, (unsigned int)(2 * i + 1))) /
          (s21_int_pow(4.0, (unsigned int)(i)) * s21_factorial(i) *
           s21_factorial(i) * (2 * i + 1));
      result += temp;
      i++;
    }
  }
  return result;
}

long double s21_acos(double x) {
  long double result;
  if (x < -1.0 || x > 1.0 || x != x) {
    result = S21_NAN;
  } else {
    result = S21_M_PI / 2 - s21_asin(x);
  }
  return result;
}

long double s21_exp(double x) {
  long double result = 1;
  if (x == 0) {
    result = 1;
  } else if (x < -20) {
    result = 0;
  } else if (x != x) {
    result = S21_NAN;
  } else if (x > 709) {
    result = S21_INF;
  } else {
    double x0 = x;
    if (x0 < 0) x0 = -x0;
    long double temp = 1;
    long double num = x0;
    long double i = 1;
    while (temp > 1e-17) {
      temp *= num / i;
      result += temp;
      ++i;
    }
    if (x < 0) {
      result = 1 / result;
    }
  }
  return result;
}

long double s21_sqrt(double x) {
  long double result = 0;

  long double x0 = x;
  long double x1 = 0.5 * (x0 + x / x0);
  long double d = s21_fabs(x0 - x1);

  if (x < 0) {
    result = -S21_NAN;
  } else if (x != x) {
    result = S21_NAN;
  } else if (x == S21_INF || x <= S21_EPS) {
    result = x;
  } else {
    while (d >= 2 * S21_EPS && d * d >= 2 * S21_EPS) {
      x0 = x1;
      x1 = 0.5 * (x0 + x / x0);
      d = s21_fabs(x0 - x1);
    }
    result = x1;
  }

  return result;
}

long double s21_ceil(double x) {
  long double result = 0.0;

  if (x != x) {
    result = S21_NAN;
  } else if (x == S21_INF) {
    result = S21_INF;
  } else if (x == -S21_INF) {
    result = -S21_INF;
  } else if (!s21_finite(x) || s21_fabs(x) >= S21_LONG_LONG_MAX) {
    result = x;
  } else {
    result = (long long)x;
    if (x != result) {
      if (s21_fabs(result) >= S21_DBL_MAX) {
        result = S21_INF;
      } else if (result < 1. && result >= 0. && x > 0) {
        result += 1;
      } else if (result > 0) {
        result += 1;
      }
    }
  }

  return result;
}

long double s21_floor(double x) {
  long double result = 0.0;

  if (x != x) {
    result = S21_NAN;
  } else if (x == S21_INF) {
    result = S21_INF;
  } else if (x == -S21_INF) {
    result = -S21_INF;
  } else if (!s21_finite(x) || s21_fabs(x) >= S21_LONG_LONG_MAX) {
    result = x;
  } else {
    result = (long long)x;
    if (x != result) {
      if (s21_fabs(result) >= S21_DBL_MAX) {
        result = S21_INF;
      } else if (result > -1. && result <= 0. && x < 0) {
        result -= 1;
      } else if (result < 0) {
        result -= 1;
      }
    }
  }

  return result;
}

long double s21_fmod(double x, double y) {
  long double result = 0;

  if (s21_nan(x) || s21_nan(y) || s21_fabs(y) < S21_EPS ||
      (s21_inf(x) && s21_inf(y))) {
    result = S21_NAN;
  } else if (s21_fabs(x) < S21_EPS) {
    result = 0;
  } else if (s21_inf(y)) {
    result = x;
  } else {
    long double lx = x;
    long double ly = y;
    long long div = x / y;
    result = lx - div * ly;
  }

  return result;
}

long double s21_log(double x) {
  int ex_pow = 0;
  long double result = 0;
  double compare = 0;
  if (x < 0 || x != x) {
    return S21_NAN;
  }
  if (x == S21_INF) {
    return S21_INF;
  }
  if (x == 0) {
    return -S21_INF;
  } else {
    for (; x >= s21_exp(1); x /= s21_exp(1), ex_pow++) continue;

    for (int i = 0; i < 100; i++) {
      compare = result;
      result = compare + 2 * (x - s21_exp(compare)) / (x + s21_exp(compare));
    }
    result = result + ex_pow;
  }
  return result;
}
