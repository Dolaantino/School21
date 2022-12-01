#include <ctype.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct options {
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
} opts;

void parser(int argc, char **argv, opts *options);
void reader(int argc, char **argv, opts *options);

int main(int argc, char **argv) {
  char s[4096];
  opts options = {0};

  if (!argv[optind]) {
    int lin = 0;
    while (1) {
      scanf("%s", s);
      if (options.b) {
        printf("%6d\t", ++lin);
      }
      printf("%s\n", s);
    }
  }
  parser(argc, argv, &options);
  reader(argc, argv, &options);
  return 0;
}

void reader(int argc, char **argv, opts *options) {
  char sym;
  char dollar = '$';
  FILE *f;
  int gobble, line, prev;

  line = gobble = 0;
  while (argc != '\0' && argv[optind]) {
    line = gobble = 0;
    f = fopen(argv[optind], "r");
    if (f) {
      for (prev = '\n'; (sym = fgetc(f)) != EOF; prev = sym) {
        if (prev == '\n') {
          if (options->s) {
            if (sym == '\n') {
              if (gobble) continue;
              gobble = 1;
            } else
              gobble = 0;
          }
          if (options->b) {
            if ((sym == '\n')) {
              printf("%c", sym);
              continue;
            } else
              printf("%6d\t", ++line);
          }
          if ((!options->b) && options->n) {
            printf("%6d\t", ++line);
            // continue;
          }
        }
        if (options->t && sym == '\t') {
          printf("^I");
          continue;
          break;
        }
        if (options->e && sym == '\n') {
          printf("%c", dollar);
        }
        if (options->v) {
          if (sym < 32 && sym != 9 && sym != 10) {
            sym = sym + 64;
            printf("^");
          }
          if (sym == 127) {
            sym = '?';
            printf("^");
          }
        }
        printf("%c", sym);
      }
      optind++;
    }
    if (!f) {
      fprintf(stderr, "No such file");
      exit(0);
    }
    fclose(f);
  }
}

void parser(int argc, char **argv, opts *options) {
  int opt;
  int option_index = 0;

  static struct option long_options[] = {{"number-nonblank", 0, 0, 'b'},
                                         {"number", 0, 0, 'n'},
                                         {"squeeze-blank", 0, 0, 's'},
                                         {0, 0, 0, 0}};
  while ((opt = getopt_long(argc, argv, "+benstvTE", long_options,
                            &option_index))) {
    if (opt == -1) {
      break;
    }
    switch (opt) {
      case 'b':
        options->b = 1;
        break;
      case 'E':
        options->e = 1;
        break;
      case 'n':
        options->n = 1;
        break;
      case 's':
        options->s = 1;
        break;
      case 'T':
        options->t = 1;
        break;
      case 't':
        options->t = 1;
        options->v = 1;
        break;
      case 'e':
        options->e = 1;
        options->v = 1;
        break;
      case 'v':
        options->v = 1;
        break;
      default:
        fprintf(stderr, "usage benstvTE\n");
        exit(1);
    }
  }
}