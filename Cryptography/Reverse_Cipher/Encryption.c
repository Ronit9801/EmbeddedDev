#include<stdio.h>
#include<string.h>

int main()
{
    short int len, i, j;
    char ch[120];
    printf("Enter the text: ");
    scanf("%[^\n]s", ch);
    len = strlen(ch);
    printf("The encrypted text: ");
    for (i = len-1; i >= 0; i--)
    {
        printf("%c",ch[i]);
    }
    printf("\n");
    return 0;
}