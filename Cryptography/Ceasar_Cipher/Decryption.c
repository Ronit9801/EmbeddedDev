#include<stdio.h>
#include<string.h>

int main()
{
    char ch[30];
    short int shift, i=0, len;
    printf("Enter the encrypted text: ");
    scanf("%[^\n]s", ch);
    len = strlen(ch);
    printf("Enter the count to shift by: ");
    scanf("%hd", &shift);
    do
    {
        if (ch[i] > 64 && ch[i] < 91)
        {
            ch[i]=(ch[i]-shift-90)%26+90;
        }
        if (ch[i] > 96 && ch[i] < 123)
        {
            ch[i]=(ch[i]-shift-122)%26+122;
        }
        i++;
    } while (ch[i] != '\0');
    printf("Decrypted text: ");
    for (int j = 0; j < len; j++)
    {
        printf("%c", ch[j]);
    }
    printf("\n");
    return 0;
}