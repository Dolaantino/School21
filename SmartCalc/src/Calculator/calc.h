#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "unistd.h"

typedef enum type_t {
  zero = -1,
  number = 0,
  X = 1,
  plus_1 = 2,
  minus_1 = 3,
  mult_1 = 4,
  div_1 = 5,
  mod_1 = 6,
  pow_1 = 7,
  cos_1 = 8,
  sin_1 = 9,
  tan_1 = 10,
  acos_1 = 11,
  asin_1 = 12,
  atan_1 = 13,
  sqrt_1 = 14,
  ln_1 = 15,
  log_1 = 16,
  Lbracket_1 = 17,
  Rbracket_1 = 18
} type_t;

typedef struct Node {
  int priority;
  double num;
  type_t type;        // 1 число в 1 узле
  struct Node *next;  // указатель на следующий
} Node;

// FUNCTIONS_BASIC
Node *polish_notation(Node *line, double x_value);
double calculation(Node *line);
double calculate(double val1, double val2, type_t operation);
Node *parsing(const char *str);

// FUNC_HELPERS_FOR_BASIC_FUNC
int operator_1(type_t type);  // E
int func(type_t type);
Node *inverse_stack(Node *line);

// FUNCTIONS_FOR_STACK
void print(Node *list);
void push(Node **plist, int prioritet, double number, type_t type_d);
void pop(Node **plist);
int is_empty(Node *list);

// FUNCTIONS_FOR_CHECK
int check_input(const char *s);
void check_input_start(const char *s, int *err);
void check_input_arithmetic(const char *s, int *err, int i);
void check_input_brackets(const char *s, int *err, int i);
void sum_brackets(int *err, int open, int close);
void check_correct(const char *s, int *err, int *open, int *close, int *i);

/* err
1 на ввод посупили некорректные данные
2 пустые скобки
3 несовпадает кол-во скобок
4 неверная длина выражения
5 деление на 0 или корень отрицательного числа
6 обработка nan, замена на Error
*/