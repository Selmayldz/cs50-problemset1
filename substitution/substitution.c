#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main()
{
    char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char newalp[26];
    printf("Enter new alphabet:");
    scanf("%s", &newalp);
    if (strlen(newalp) != 26)
    {
        printf("Key must be 26 characters!\n");
        return 0;
    }
    for (int i = 0; i <= strlen(newalp); i++)
    {
        if (((newalp[i] < 'a' && newalp[i] > 'z') || (newalp[i] < 'A' && newalp[i] > 'Z')))
        {
            printf("Key must contain only letters.\n");
            return 0;
        }
        else if (newalp[i] >= 'a' && newalp[i] <= 'z')
        {
            newalp[i] = toupper(newalp[i]);
        }
        int controller[26];
        for (int j = 0; j < 26; j++)
        {
            if (newalp[i] == controller[j])
            {
                printf("Key must not contain repeated letters.\n");
                return 0;
            }
        }
        controller[i] = newalp[i];
    }
    char text[100];
    printf("Enter text:");
    scanf("%s", &text);
    char keyword[100];

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isupper(text[i]) != 0) // Girilen metindeki kontrol edilen karakter büyük harf ise
        {
            for (int j = 0; j < 26; j++)
            {
                if (text[i] == alphabet[j])
                {
                    keyword[i] = newalp[j];
                    break;
                }
            }
        }
        else if (islower(text[i]) != 0)
        {
            for (int j = 0; j < 26; j++)
            {
                if (text[i] == tolower(alphabet[j]))
                {
                    keyword[i] = tolower(newalp[j]);
                    break;
                }
            }
        }
        else
        {
            keyword[i] = text[i];
        }
    }
    printf("Key word:%s\n", keyword);
    return 0;
}
