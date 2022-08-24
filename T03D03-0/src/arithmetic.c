#include <stdio.h>

int main()
{
    int a,b,s,r,p,d;
    
    if(scanf ("%d%d",&a,&b) == 2)
    {
        s=a+b;
        r=a-b;
        p=a*b;
        if (b==0)
        {
            printf("%d %d %d n/a",s,r,p);
            return 0;
        }
        else
        {
            d=a/b;
            printf("%d %d %d %d",s,r,p,d);
            return 0;
        }
    }
    else
    {
        printf("n/a");
        return 0;
    }
    return 0;
}
