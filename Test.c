#include <stdio.h>

int check(int a, int b, int c)
{
    return(a*a+b*b==c*c);
}

int main()
{
    while (1)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if(a+b+c == 0){ break; }
        if(check(a,b,c)||check(a,c,b)||check(b,c,a))
        {
            printf("right\n");
        }
        else
        {
            printf("wrong\n");
        }
    }
    return 0;
}