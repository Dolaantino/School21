#include "calc.h"

int operator_1(type_t type) {
  int res = 0;
  if (type == plus_1 || type == minus_1 || type == mult_1 || type == div_1 ||
      type == mod_1 || type == pow_1) {
    res = 1;
  }
  return res;
}
int func(type_t type) {
  int res = 0;
  if (type == cos_1 || type == sin_1 || type == tan_1 || type == acos_1 ||
      type == asin_1 || type == atan_1 || type == sqrt_1 || type == ln_1 ||
      type == log_1) {
    res = 1;
  }
  return res;
}

Node *inverse_stack(Node *line) {
  Node *tmp = NULL;
  while (line != NULL) {
    push(&tmp, line->priority, line->num, line->type);
    pop(&line);
  }
  return tmp;
}
