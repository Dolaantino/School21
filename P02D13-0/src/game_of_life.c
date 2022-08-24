#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>

#define H 25
#define W 80

int initfield(char (*field)[W]);
void printfield(char (*field)[W], int v);
void boundery();
void run(char (*field)[W], char (*tem)[W]);
int gameplay(char (*field)[W], char (*tem)[W]);
int action(char (*field)[W], int x, int y, char (*tem)[W]);
void copy(char (*field)[W], char (*tem)[W]);
int change(char (*field)[W], int x, int y, char (*tem)[W], int count);
void gameover();
void gameoflife();

int main(void) {
  char field[H][W];
  if (!initfield(field)) {
    printf("Incorrect input!");
  } else {
    FILE *tty;
    tty = freopen("/dev/tty", "r", stdin);
    if (tty == NULL) {
      printf("Unable to switch output!");
    } else {
      char tem[H][W];
      initscr();
      raw();
      nodelay(stdscr, TRUE);
      noecho();
      clear();
      gameoflife();
      refresh();
      usleep(5000000);
      run(field, tem);
      endwin();
      gameover();
    }
  }
  return 0;
}

void copy(char (*field)[W], char (*tem)[W]) {
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      field[i][j] = tem[i][j];
    }
  }
}

void run(char (*field)[W], char (*tem)[W]) {
  int flag = 1;
  int v = 30000;
  char key = '\0';
  while (flag) {
    if (key == '-') {
      v = (v < 250000) ? v + 10000 : v;
    } else if (key == '=') {
      v = (v > 10000) ? v - 10000 : v;
    } else if (key == 'q') {
      break;
    }
    clear();
    printfield(field, v);
    refresh();
    key = getch();
    flag = gameplay(field, tem);
    usleep(v);
  }
  usleep(3000000);
}

int initfield(char (*field)[W]) {
  int flag = 1;

  for (int i = 0; i < H; i++) {
    char check;
    for (int j = 0; j < W; j++) {
      field[i][j] = getchar();
      if (field[i][j] != ' ' && field[i][j] != '*') {
        flag = 0;
        break;
      }
    }
    check = getchar();
    if (check != '\n') {
      flag = 0;
      break;
    }
  }

  return flag;
}

void printfield(char (*field)[W], int v) {
  boundery();
  for (int i = 0; i < H; i++) {
    printw("|");
    for (int j = 0; j < W; j++) {
      printw("%c", field[i][j]);
    }
    printw("|\n");
  }
  boundery();
  printw("Delay: %d", v);
}

void boundery() {
  for (int i = 0; i < W + 2; i++) {
    printw("-");
  }
  printw("\n");
}

int gameplay(char (*field)[W], char (*tem)[W]) {
  int flag = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (action(field, j, i, tem)) {
        flag = 1;
      }
    }
  }
  copy(field, tem);
  return flag;
}

int action(char (*field)[W], int x, int y, char (*tem)[W]) {
  int rx = (x + 1 == W) ? 0 : x + 1;
  int lx = (x - 1 == -1) ? W - 1 : x - 1;
  int by = (y + 1 == H) ? 0 : y + 1;
  int ty = (y - 1 == -1) ? H - 1 : y - 1;
  int count = 0;
  int flag2 = 0;
  if (field[ty][lx] == '*') {
    count++;
    flag2 = 1;
  }
  if (field[ty][x] == '*') {
    count++;
    flag2 = 1;
  }
  if (field[ty][rx] == '*') {
    count++;
    flag2 = 1;
  }
  if (field[y][lx] == '*') {
    count++;
    flag2 = 1;
  }
  if (field[y][rx] == '*') {
    count++;
    flag2 = 1;
  }
  if (field[by][lx] == '*') {
    count++;
    flag2 = 1;
  }
  if (field[by][x] == '*') {
    count++;
    flag2 = 1;
  }
  if (field[by][rx] == '*') {
    count++;
    flag2 = 1;
  }
  return (change(field, x, y, tem, count) && flag2 == 1) ? 1 : 0;
}

int change(char (*field)[W], int x, int y, char (*tem)[W], int count) {
  int flag1 = 0;
  if (field[y][x] == '*' && (count > 3 || count < 2)) {
    tem[y][x] = ' ';
    flag1 = 1;
  } else if (field[y][x] == ' ' && count == 3) {
    tem[y][x] = '*';
    flag1 = 1;
  } else {
    tem[y][x] = field[y][x];
  }
  return flag1;
}

void gameover() {
  printf("******    *     *      *   ******\n");
  printf("*    *   * *    **    **   *\n");
  printf("*       *   *   * *  * *   *\n");
  printf("*       *****   *  **  *   ******\n");
  printf("*   **  *   *   *      *   *\n");
  printf("*    *  *   *   *      *   *\n");
  printf("******  *   *   *      *   ******\n");
  printf("\n******   *   *   ******   ******\n");
  printf("*    *   *   *   *        *    *\n");
  printf("*    *   *   *   *        *    *\n");
  printf("*    *   *   *   ******   ******\n");
  printf("*    *   *   *   *        *  *\n");
  printf("*    *    * *    *        *   *\n");
  printf("******     *     ******   *    *\n");
}

void gameoflife() {
  printw("  ________                                _____  .__  .__  _____     "
         "  \n");
  printw(" /  _____/_____    _____   ____     _____/ ____\\ |  | |__|/ "
         "____\\____  \n");
  printw("/   \\  ___\\__  \\  /     \\_/ __ \\   /  _ \\   __\\  |  | |  \\   "
         "__\\/ __ \\ \n");
  printw("\\    \\_\\  \\/ __ \\|  Y Y  \\  ___/  (  <_> )  |    |  |_|  ||  | "
         "\\  ___/ \n");
  printw(" \\______  (____  /__|_|  /\\___  >  \\____/|__|    |____/__||__|  "
         "\\___  >\n");
  printw("        \\/     \\/      \\/     \\/                                 "
         "   \\/ \n");
}
