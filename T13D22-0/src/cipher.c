#include <stdio.h>
#include <stdlib.h>
// Copyright name

int main() {
  FILE *f;
  char file[200];
  char s[100];
  char s2[100] = {0};
  int i = 1;
  int d;

  while (i > 0) {
    if (!scanf("%d", &d)) {
      printf("n/a\n");
      i = 0;
    } else if (d == 1) {
      if (!scanf("%s", file)) {
        printf("n/a\n");
      }
      f = fopen(file, "r");
      if (f != NULL) {
        fgets(s, 100, f);
        printf("%s\n", s);
      }
      fclose(f);
    } else if (d == 2) {
        getchar();
        scanf("%99[^\n]", s2);
        f = fopen(file, "a");
        if (f != NULL) {
            fputs(s2, f);
            fclose(f);
            // fgets(s, 100, f);
            // fgets(s2, 100, f);
            // printf("%s\n%s\n", s, s2);
            // fclose(f);
        }
        f = fopen(file, "r");
        if (f != NULL) {
            // printf("gyubgyu");
            while (fgets(s, 100, f) != NULL) {
                printf("%s", s);
            }
        fclose(f);
      }
  } else if (d == -1) {
      i = 0;
    } else {
        printf("n/a\n");
    }
    }
  // fclose(f);
  // fclose(f);
  return 0;
}
