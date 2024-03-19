#include<stdio.h>
#include<string.h>

int main()
{
    char ch[30];
    short int shift, i=0, len, j;
    printf("Enter the text to encrypt: ");
    scanf("%[^\n]s",ch);
    len = strlen(ch);
    printf("Enter the count to shift: ");
    scanf("%d", &shift);
    do
    {
        if (ch[i] > 64 && ch[i] < 91)
        {
            ch[i]=(ch[i]+shift-65)%26+65;
        }
        if (ch[i] > 96 && ch[i] < 123)
        {
            ch[i]=(ch[i]+shift-97)%26+97;
        }
        i++;
    } while (ch[i] != '\0');
    printf("Encrypted text: ");
    for (j = 0; j < len; j++)
    {
        printf("%c", ch[j]);   
    }
    printf("\n");
    return 0;
}
