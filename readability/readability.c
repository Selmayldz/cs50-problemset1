#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    string text=get_string("Text:");

    int letters=0;
    for(int i=0;i<strlen(text);i++)
    {
        if((text[i]>='a' && text[i]<='z') || (text[i]>='A' && text[i]<='Z'))
        letters++;
    }
    printf("%i letters\n",letters);

    int words=1;
    for(int i=0;i<strlen(text);i++)
    {
        if(text[i]==' ')
        words++;
    }
    printf("%i words\n",words);

    int sentences=0;
    for(int i=0;i<strlen(text);i++)
    {
        if(text[i]=='!' || text[i]=='.' || text[i]=='?')
        sentences++;
    }
    printf("%i sentences\n",sentences);

    float l=((float)letters/(float)words)*100;
    float s=((float)sentences/(float)words)*100;

    float index1=0.0588*l-0.296*s-15.8;
    int index=round(index1);

    if(index<1)
      printf("Before grade 1\n");
    else if(index>16)
      printf("Grade 16+\n");
    else
      printf("Grade %i\n",index);
}