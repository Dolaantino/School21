#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct options {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
  int bla;
} opts;

void parser(int argc, char **argv, opts *options, regex_t *regex);
void reader(int argc, char **argv, opts *options, regex_t *regex);

int main(int argc, char **argv) {
  regex_t regex;
  // int sum;
  opts options = {0};

  parser(argc, argv, &options, &regex);
  reader(argc, argv, &options, &regex);

  regfree(&regex);
  return 0;
}

void parser(int argc, char **argv, opts *options, regex_t *regex) {
  int opt = 0;
  char search_string[100] = {0};
  FILE *fp;
  ssize_t fff = 0;
  int regflag = 0;
  char *fp_line = NULL;
  size_t lenght = 0;

  while ((opt = getopt_long(argc, argv, "e:ivclnhsf:o", NULL, NULL))) {
    if (opt == -1) {
      break;
    }
    switch (opt) {
      case 'e':
        options->e = 1;
        options->bla = 1;
        break;
      case 'i':
        options->i = 1;
        break;
      case 'v':
        options->v = 1;
        break;
      case 'c':
        options->c = 1;
        break;
      case 'l':
        options->l = 1;
        break;
      case 'n':
        options->n = 1;
        break;
      case 'h':
        options->h = 1;
        break;
      case 's':
        options->s = 1;
        break;
      case 'f':
        options->f = 1;
        break;
      case 'o':
        options->o = 1;
        break;
      default:
        fprintf(stderr, "usage eivclnhsfo\n");
        exit(1);
    }
    if (options->bla) {
      regflag = REG_EXTENDED;
      strcat(search_string, optarg);
      strcat(search_string, "|");
      options->bla = 0;
    }
    if (options->f) {
      regflag = REG_EXTENDED;
      fp = fopen(optarg, "r");
      if (fp) {
        while (fff != EOF) {
          fff = getline(&fp_line, &lenght, fp);
          if (fp_line[strlen(fp_line) - 1] == '\n') {
            fp_line[strlen(fp_line) - 1] = 127;
          }
          strcat(search_string, fp_line);
          strcat(search_string, "|");
        }
        fclose(fp);
        if (fp_line != NULL) {
          free(fp_line);
        }
      }
      if (!fp) {
        if (!options->s) {
          printf("No such file");
          exit(0);
        }
        if (options->c) {
          exit(0);
        }
      }
      search_string[strlen(search_string) - 1] = '\0';
    }
  }
  search_string[strlen(search_string) - 1] = '\0';
  if (options->i) {
    regflag = REG_ICASE;
  }
  if ((options->e && options->f) || options->e || options->f) {
    regcomp(regex, search_string, regflag);
  } else {
    regcomp(regex, argv[optind], regflag);
    optind++;
  }
}
void reader(int argc, char **argv, opts *options, regex_t *regex) {
  int compare = 0;
  int str_count = 0;
  int FIND_SUCCEC = 0;
  // int count = 0;
  size_t len = 0;
  char *tmp_line = NULL;
  FILE *f;
  ssize_t reg = 0;
  int SUCCES = 0;
  regmatch_t match[10];
  int names = argc - optind;

  while (optind < argc && argv[optind]) {
    f = fopen(argv[optind], "r");
    if (!f) {
      if (!options->s) {
        if (names > 1) {
          fprintf(stderr, "grep: %s: No such file or directory\n",
                  argv[optind]);
        } else
          fprintf(stderr, "No such file");
        optind++;
        continue;
      }
    }
    if (f) {
      if (names > 1 && !options->h && options->c) {
        printf("%s:", argv[optind]);
      }
      while (reg != EOF) {
        reg = getline(&tmp_line, &len, f);
        if (tmp_line && reg != EOF) {
          str_count++;
          SUCCES = regexec(regex, tmp_line, 1, match, 0);
          if ((SUCCES == 0 && !options->v) ||
              (SUCCES == 0 && options->l && !options->v)) {
            if (options->l) {
              options->h = 1;
            }
            if (names > 1 && !options->h && !options->c) {
              printf("%s:", argv[optind]);
            }
            if (options->c) {
              FIND_SUCCEC++;
            }
            if (options->n && !options->l && !options->c) {
              printf("%d:", str_count);
            }
            // if (options->o && !options->l) {
            //   for (int j = 0; j < 10; j++) {
            //     for (int i = match[j].rm_so; i < match[j].rm_eo; i++) {
            //       printf("%c\n", tmp_line[i]);
            //     }
            //   }
            // }
            // count++;

            if (options->l) {
              if (options->c) {
                printf("%d\n", FIND_SUCCEC);
              }
              printf("%s\n", argv[optind]);
              break;
            }
            if (!options->l && !options->c && !options->o) {
              printf("%s", tmp_line);
              if (tmp_line[strlen(tmp_line) - 1] != '\n') {
                printf("\n");
              }
            }
          }
          if (options->v || (options->v && SUCCES != 0)) {
            compare = REG_NOMATCH;
            if (SUCCES == compare) {
              if (options->c) {
                FIND_SUCCEC++;
              }
              if (options->l) {
                if (options->c) {
                  printf("%d\n", FIND_SUCCEC);
                }
                if (names == 1) {
                  printf("%s\n", argv[optind]);
                }
                if (names > 1) {
                  printf("%s\n", argv[optind]);
                }
                break;
              }
              if (names > 1 && !options->h && !options->c) {
                printf("%s:", argv[optind]);
              }
              if (options->n && !options->c) {
                printf("%d:", str_count);
              }
              if (!options->c) {
                printf("%s", tmp_line);
                if (tmp_line[strlen(tmp_line) - 1] != '\n') {
                  printf("\n");
                }
              }
            }
          }
        }
      }
      if (options->c && !options->l) {
        printf("%d\n", FIND_SUCCEC);
      }
    }
    if ((argc - optind) > 0) {
      optind++;
      reg = 0;
      str_count = 0;
      FIND_SUCCEC = 0;
    }
    fclose(f);
  }
  if (tmp_line) {
    free(tmp_line);
  }
}
