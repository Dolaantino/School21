// #include <stdio.h>
// #include <stdlib.h>
#include "calc.h"

// typedef double char Data;
// typedef struct Node {
//   Data data;          // 1 число в 1 узле
//   struct Node *next;  // указатель на следующий
// } Node;

// void print(Node *list);
// void push(Node **plist, Data d);
// int is_empty(Node *list);

// Node *list = NULL;  // сначала список пустой
// NUMBER
void push(Node **plist, int prioritet, double number, type_t type_d) {
  Node *p = malloc(sizeof(Node));
  p->priority = prioritet;
  p->num = number;
  p->type = type_d;
  p->next = *plist;
  *plist = p;
}
void pop(Node **plist) {
  Node *p = *plist;
  if (plist == NULL) {
    exit(0);
  }
  // int res_priority = p->priority;
  // double res_num = p->num;
  // type_t res_type = p->type;
  *plist = p->next;
  free(p);

  // return res_priority, res_num, res_type;
}
// void print(Node *list) {
//   if (list == NULL) {
//     printf("NULL\n");
//     exit(0);
//   }
//   for (Node *p = list; p != NULL; p = p->next) {
//     printf("Приоритет - %d\nЧисло - %lf\nТип - %d\n-------------------\n",
//            p->priority, p->num, p->type);
//   }
//   printf("\n");
// }
// int is_empty(Node *list) { return list == NULL; }
// NUMBER

// CHAR
// void push_char(Node_char **plist, Data_char d) {
//   Node_char *p = malloc(sizeof(Node_char));
//   if (d == '+' || d == '-') {
//     p->priority = 1;
//   }
//   if (d == '*' || d == '/') {
//     p->priority = 2;
//   }
//   p->data = d;
//   p->next = *plist;
//   *plist = p;
// }
// Data pop_char(Node_char **plist) {
//   Node_char *p = *plist;
//   Data_char res = p->data;
//   *plist = p->next;
//   free(p);

//   return res;
// }
// void print_char(Node_char *list) {
//   for (Node_char *p = list; p != NULL; p = p->next) {
//     printf("%c ", p->data);
//   }
//   printf("\n");
// }
// int is_empty_char(Node_char *list) { return list == NULL; }
// CHAR

// int main() {
//   Data test[] = {21, 17, 3, 10};
//   Node *list = NULL;
//   // printf("%d\n", sizeof(test) / sizeof(test[0]));
//   printf("Empty: %s\n", is_empty(list) ? "YES" : "NO");
//   // Node a = {3}, b = {17}, c = {21}, t = {10};
//   for (size_t i = 0; i < sizeof(test) / sizeof(test[0]); i++) {
//     // print(list);
//     push(&list, test[i]);
//     print(list);
//   }
//   printf("Empty: %s\n", is_empty(list) ? "YES" : "NO");

//   while (!is_empty(list)) {
//     Data d = pop(&list);
//     printf("pop %d :", d);
//     print(list);
//   }

//   printf("Empty: %s\n", is_empty(list) ? "YES" : "NO");

//   // print(list);

//   return 0;
// }
