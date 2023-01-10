#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<cs50.h>

int main()
{
    long int n;
    printf("Number:");
    scanf("%li",&n);

    int sum=0;
    long int n2;
    n2=n;
    long int cardno;
    cardno=n;

    do
    {
        int a=n%100;
        int b=a/10;

        if(a>5)
        {
            int s=2*b;
            int t=(s%10)+(s/10);
            sum+=t;
        }
        else
        {
            int t2=2*b;
            sum+=t2;
        }
        n=n/100;

    }
    while(n>9);

    do
    {
        int b=n2%10;
        n2=n2/100;
        sum+=b;

    }
    while (n2>0);



    if(sum%10==0)
    {
        if((cardno>=34*pow(10,13) && cardno<35*pow(10,13)) || (cardno>=37*pow(10,13) && cardno<38*pow(10,13)))
        {
            printf("AMEX\n");
        }
        else if(cardno>=51*pow(10,14) && cardno<56*pow(10,14))
        {
            printf("MASTERCARD\n");
        }
        else if((cardno>=4*pow(10,12) && cardno<5*pow(10,12)) || (cardno>=4*pow(10,15) && cardno<5*pow(10,15)))
        {
            printf("VISA\n");
        }
        else
        {
          printf("INVALID\n");
        }
    }
    else
        printf("INVALID\n");

}