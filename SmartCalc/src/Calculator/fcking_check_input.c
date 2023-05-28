#include "calc.h"

int check_input(const char *s) {
  int err = 0, open = 0, close = 0, len = strlen(s);
  check_input_start(s, &err);
  for (int i = 0; i < len; i++) {
    if (err == 0) check_input_arithmetic(s, &err, i);
    if (err == 0) check_input_brackets(s, &err, i);
    if (err == 0) check_correct(s, &err, &open, &close, &i);
  }
  sum_brackets(&err, open, close);
  return err;
}
void check_input_start(const char *s, int *err) {
  if (strlen(s) < 1 || strlen(s) > 256) {
    *err = 4;
  }
  if (s[0] == '0' && s[1] == '0')
    *err = 1;
  else if (s[0] == '/' || s[0] == '*' || s[0] == '^' || s[0] == 'm' ||
           s[0] == '.')
    *err = 1;
}
void check_input_arithmetic(const char *s, int *err, int i) {
  if ((s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*' ||
       s[i] == '^') &&
      (s[i + 1] == '+' || s[i + 1] == '-' || s[i + 1] == '/' ||
       s[i + 1] == '*' || s[i + 1] == '^')) {
    *err = 1;
  }
  if (*err == 0) {
    int z = strlen(s) - 1;
    if ((s[z] == '+' || s[z] == '-' || s[z] == '*' || s[z] == '/' ||
         s[z] == '^') &&
        (err == 0)) {
      *err = 1;
    }
    if (*err == 0 && (s[z] == '+' || s[z] == '-' || s[z] == '*' ||
                      s[z] == '/' || s[z] == '^')) {
      *err = 1;
    }
  }
  if (*err == 0 && s[i] == '/' && s[i + 1] == '0') {
    *err = 5;
  }
}
void check_input_brackets(const char *s, int *err, int i) {
  if ((s[i] == '(') && (s[i + 1] == ')')) {
    *err = 2;
  }
  if ((*err == 0) &&
      (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' ||
       s[i] == '^') &&
      (s[i + 1] == ')')) {
    *err = 1;
  }
}
void sum_brackets(int *err, int open, int close) {
  if (*err == 0 && open != close) {
    *err = 3;
  }
}
void check_correct(const char *s, int *err, int *open, int *close, int *i) {
  if (s[*i] == '.') {
    *i = *i;
  } else if (s[*i] == 'x') {
    *i = *i;
  } else if (s[*i] >= '0' && s[*i] <= '9') {
    *i = *i;
  } else if (s[*i] == '+' || s[*i] == '-' || s[*i] == '*' || s[*i] == '/' ||
             s[*i] == '^') {
    *i = *i;
  } else if (s[*i] == '(') {
    *open = *open + 1;
  } else if (s[*i] == ')') {
    *close = *close + 1;
  } else if ((s[*i] == 'm' && s[*i + 1] == 'o' && s[*i + 2] == 'd') &&
             (s[*i + 3] >= '0' && s[*i + 3] <= '9')) {
    *i = *i + 2;
  } else if (s[*i] == 'c' && s[*i + 1] == 'o' && s[*i + 2] == 's' &&
             s[*i + 3] == '(') {
    *i = *i + 2;
  } else if (s[*i] == 's' && s[*i + 1] == 'i' && s[*i + 2] == 'n' &&
             s[*i + 3] == '(') {
    *i = *i + 2;
  } else if (s[*i] == 't' && s[*i + 1] == 'a' && s[*i + 2] == 'n' &&
             s[*i + 3] == '(') {
    *i = *i + 2;
  } else if (s[*i] == 'a' && s[*i + 1] == 'c' && s[*i + 2] == 'o' &&
             s[*i + 3] == 's' && s[*i + 4] == '(') {
    *i = *i + 3;
  } else if (s[*i] == 'a' && s[*i + 1] == 's' && s[*i + 2] == 'i' &&
             s[*i + 3] == 'n' && s[*i + 4] == '(') {
    *i = *i + 3;
  } else if (s[*i] == 'a' && s[*i + 1] == 't' && s[*i + 2] == 'a' &&
             s[*i + 3] == 'n' && s[*i + 4] == '(') {
    *i = *i + 3;
  } else if (s[*i] == 's' && s[*i + 1] == 'q' && s[*i + 2] == 'r' &&
             s[*i + 3] == 't' && s[*i + 4] == '(') {
    *i = *i + 3;
  } else if (s[*i] == 'l' && s[*i + 1] == 'n' && s[*i + 2] == '(') {
    *i = *i + 1;
  } else if (s[*i] == 'l' && s[*i + 1] == 'o' && s[*i + 2] == 'g' &&
             s[*i + 3] == '(') {
    *i = *i + 2;
  } else {
    *err = 1;
  }
  if (*close > *open) *err = 1;
}
