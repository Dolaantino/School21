#include <stdio.h>

int main ()
{
    printf ("Имена разработчиков-1\nЗапустить игру-2\n");
    int x;
    scanf("%d",&x);
    switch(x)
    {
    case 1:
        printf("Ваня\nРома\nДолаан\n");
        break;
    case 2:
        printf("Игра запущена\n");
        break;
    }
return 0;
}
