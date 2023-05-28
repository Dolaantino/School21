#include "calc.h"

double calculation(Node *line) {
  Node *number = NULL;
  for (size_t i = 0; line != NULL; i++) {
    if (line->type == 0 || line->type == 1) {
      push(&number, line->priority, line->num, line->type);
      pop(&line);
    }
    if (line != NULL) {
      if (line->type > 1 && line->type < 8) {
        double val2 = number->num;
        pop(&number);
        double val1 = number->num;
        pop(&number);
        type_t operation_calc = line->type;
        pop(&line);
        double res = calculate(val1, val2, operation_calc);
        push(&number, 0, res, 0);
      }
      if (line != NULL) {
        if (line->type > 7 && line->type < 17) {
          double val2 = number->num;
          pop(&number);
          double val1 = 0;
          type_t operation_calc = line->type;
          pop(&line);
          double res = calculate(val1, val2, operation_calc);
          push(&number, 0, res, 0);
        }
      }
    }
  }
  double result = number->num;
  pop(&number);
  return result;
}

double calculate(double val1, double val2, type_t operation) {
  double result = 0.0;
  if (operation == 2)
    result = val1 + val2;
  else if (operation == 3)
    result = val1 - val2;
  else if (operation == 4)
    result = val1 * val2;
  else if (operation == 5)
    result = val1 / val2;
  else if (operation == 7)
    result = pow(val1, val2);
  else if (operation == 6)
    result = fmod(val1, val2);
  else if (operation == 9)
    result = sin(val2);
  else if (operation == 8)
    result = cos(val2);
  else if (operation == 10)
    result = tan(val2);
  else if (operation == 11)
    result = acos(val2);
  else if (operation == 12)
    result = asin(val2);
  else if (operation == 13)
    result = atan(val2);
  else if (operation == 14)
    result = sqrt(val2);
  else if (operation == 15)
    result = log(val2);
  else if (operation == 16)
    result = log10(val2);
  return result;
}
