#include <stdio.h>

int move_racket1(char a, int racket1_y);
int move_racket2(char b, int racket2_y);
int move_ball_x(int ball_x, int d);
int move_ball_y(int ball_y, int p);

int main() {
  char a, b;
  int ball_x = 3;
  int ball_y = 12;
  int racket1_y = 10;
  int racket2_y = 10;
  int x = 0;
  int p = 1;
  int d = 1;
  int player1 = 0;
  int player2 = 0;
  int t;
  printf("Добро пожаловать в игру\nПервый игрок управляет левой ракеткой с "
         "помощью клавиш 'A' и 'Z', второй игрок управляет правой ракеткой с "
         "помощью клавиш 'K' и 'M'\nИгра оканчивается когда один из игроков "
         "набирает 21 очко\nЧтобы начать игру нажмите 1\n");
  scanf("%d", &t);
  switch (t) {
  case 1:
    while (x == 0) {
      for (int i = 0; i <= 25; i++) {
        for (int j = 0; j <= 80; j++) {

          if (i == 1 || i == 25) { // Ограничения поля
            printf("_");
          }

          else if (i > 1 && i < 25) {
            if (j == 40) { // Средняя линия
              printf("|");
            }

            else if (ball_x == j && ball_y == i) { // Отрисовка мяча
              printf("*");
            }

            else if (j == 2 && i > racket1_y && i <= (racket1_y + 3) ||
                     j == 77 && i > racket2_y &&
                         i <= (racket2_y + 3)) { //Ракетки
              printf("H");

            } else {
              printf(" ");
            }
          }
        }

        printf("\n");
      }

      if (ball_y == 24) { // Разворот при отскоке от низа
        p = -1;
      }
      if (ball_y == 2) { // Разворот при отскоке от верха
        p = 1;
      }

      if (ball_x == 76 && (ball_y == racket2_y ball_y == racket2_y + 1 
                           ball_y == racket2_y + 2)) {
        d = -1;
      }

      if (ball_x == 4 && (ball_y == racket1_y ball_y == racket1_y + 1 
                          ball_y == racket1_y + 2)) {
        d = 1;
      }
      if (ball_x > 77) {
        player1++;
        ball_x = 3;
        ball_y = 12;
      }

      if (ball_x < 2) {
        player2++;
        ball_x = 76;
        ball_y = 12;
      }
      ball_x = move_ball_x(ball_x, d);
      ball_y = move_ball_y(ball_y, p);

      printf("%d", player1);
      printf("                                                                 "
             "              ");
      printf("%d", player2);
      if (player1 == 21) {
        printf("\nПобедил игрок 1");
        break;
      }
      if (player2 == 21) {
        printf("\nПобедил игрок 2");
        break;
      }
      racket1_y = move_racket1(a, racket1_y);
      racket2_y = move_racket2(b, racket2_y);
    }

    break;

  default:
    printf("Цифра не выбрана");
  }
  return 0;
}

int move_ball_x(int ball_x, int d) {
  ball_x = ball_x + d;
  return ball_x;
}

int move_ball_y(int ball_y, int p) {
  ball_y = ball_y + p;
  return ball_y;
}

int move_racket1(char a, int racket1_y) {
  a = getchar();
  if (a == 'a' && racket1_y != 1) {
    racket1_y -= 1;
  }
  if (a == 'z' && racket1_y != 21) {
    racket1_y += 1;
  }
  if (a != 'a' && a != 'z') {
    racket1_y = racket1_y;
  }
  return racket1_y;
}

int move_racket2(char b, int racket2_y) {
  b = getchar();
  if (b == 'k' && racket2_y != 1) {
    racket2_y -= 1;
  }
  if (b == 'm' && racket2_y != 21) {
    racket2_y += 1;
  }
  if (b != 'k' && b != 'm') {
    racket2_y = racket2_y;
  }
  return racket2_y;
}
