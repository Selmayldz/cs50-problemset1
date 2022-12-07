#include <stdio.h>
#include <stdlib.h>

void piramit(int a)
{
    int i,j;

    for(i=1;i<=a;i++)
    {
        for(j=1;j<=(a-i);j++)
        {
            printf(" ");
        }
        for(j=1;j<=i;j++)
        {
            printf("#");
        }
        for(j=1;j<=2;j++)
        {
            printf(" ");
        }
         for(j=1;j<=i;j++)
        {
            printf("#");
        }
        printf("\n");
    }
}

int main()
{
    int a;
    printf("mario\n");
   loop: printf("height:");
    scanf("%d",&a);

    if(a>0 && a<=8)
        piramit(a);
    else
        goto loop;

    return 0;
}
