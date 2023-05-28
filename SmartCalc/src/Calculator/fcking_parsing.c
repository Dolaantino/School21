#include "calc.h"

// int main() {
//   char str_1[200] = "-0.1+0.2";
//   int err = 0;
//   err = check_input(str_1);
//   if (err == 0) {
//     Node *number_list = parsing(str_1);

//     number_list = polish_notation(number_list, 5);
//     double result = calculation(number_list);
//     printf("%lf\n", result);
//   }
//   return 0;
// }

Node *parsing(const char *str) {
  Node *number_list = NULL;
  char number_str[200] = {};
  for (size_t i = 0, j = 0; str[i] != '\0'; i++) {
    if ((str[i] >= '0' && str[i] <= '9') ||
        (str[i] == '.' && isdigit(str[i - 1]))) {
      number_str[j] = str[i];
      j++;
    }
    if ((!(str[i] >= '0' && str[i] <= '9') && (j && str[i] != '.')) ||
        (str[i + 1] == '\0' && j)) {
      push(&number_list, number, atof(number_str), number);
      bzero(&number_str, strlen(number_str));
      j = 0;
    }
    if (str[i] == 'x') {
      push(&number_list, 0, 0, X);
    }
    if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' ||
        str[i] == '%') {
      if (str[i] == '+') {
        if (str[0] == '+' && i == 0) {
          push(&number_list, 0, 0, number);
        }
        push(&number_list, 1, 0, plus_1);
      }
      if (str[i] == '-') {
        if (str[0] == '-' && i == 0) {
          push(&number_list, 0, 0, number);
        }
        push(&number_list, 1, 0, minus_1);
      }
      if (str[i] == '*') {
        push(&number_list, 2, 0, mult_1);
      }
      if (str[i] == '/') {
        push(&number_list, 2, 0, div_1);
      }
      if (str[i] == '%') {
        push(&number_list, 2, 0, mod_1);
      }
    } else if (str[i] == '^') {
      push(&number_list, 3, 0, pow_1);
    } else if (str[i] == 'c' || str[i] == 's' || str[i] == 't' ||
               str[i] == 'a' || str[i] == 'l' || str[i] == 'm') {
      if (str[i] == 'm' && str[i + 1] == 'o' && str[i + 2] == 'd') {
        push(&number_list, 3, 0, mod_1);
        i = i + 2;
      }
      if (str[i] == 's' && str[i + 1] == 'q' && str[i + 2] == 'r' &&
          str[i + 3] == 't') {
        push(&number_list, 3, 0, sqrt_1);
        i = i + 3;
      }
      if (str[i] == 'c' && str[i + 1] == 'o' && str[i + 2] == 's') {
        push(&number_list, 3, 0, cos_1);
        i = i + 2;
      }
      if (str[i] == 's' && str[i + 1] == 'i' && str[i + 2] == 'n') {
        push(&number_list, 3, 0, sin_1);
        i = i + 2;
      }
      if (str[i] == 't' && str[i + 1] == 'a' && str[i + 2] == 'n') {
        push(&number_list, 3, 0, tan_1);
        i = i + 2;
      }
      if (str[i] == 'c' && str[i + 1] == 'o' && str[i + 2] == 's') {
        push(&number_list, 3, 0, cos_1);
        i = i + 2;
      }
      if (str[i] == 'a') {
        if (str[i + 1] == 'c' && str[i + 2] == 'o' && str[i + 3] == 's') {
          push(&number_list, 3, 0, acos_1);
          i = i + 3;
        }
        if (str[i + 1] == 's' && str[i + 2] == 'i' && str[i + 3] == 'n') {
          push(&number_list, 3, 0, asin_1);
          i = i + 3;
        }
        if (str[i + 1] == 't' && str[i + 2] == 'a' && str[i + 3] == 'n') {
          push(&number_list, 3, 0, atan_1);
          i = i + 3;
        }
      }
      if (str[i] == 'l') {
        if (str[i + 1] == 'n') {
          push(&number_list, 3, 0, ln_1);
          i = i + 1;
        }
        if (str[i + 1] == 'o' && str[i + 2] == 'g') {
          push(&number_list, 3, 0, log_1);
          i = i + 2;
        }
      }
    } else if (str[i] == '(' || str[i] == ')') {
      if (str[i] == '(') {
        push(&number_list, 4, 0, Lbracket_1);
        if (str[i + 1] == '+' || str[i + 1] == '-') {
          push(&number_list, 0, 0, number);
        }
      }
      if (str[i] == ')') {
        push(&number_list, 4, 0, Rbracket_1);
      }
    }
  }
  return number_list;
}
