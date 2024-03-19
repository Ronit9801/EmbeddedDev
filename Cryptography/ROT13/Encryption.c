#include<stdio.h>
#include<string.h>

int main()
{
    int len, i;
    char ch[30];
    printf("Enter the text: ");
    scanf("%[^\n]s", ch);
    len = strlen(ch);
    for(i = 0; i < len; i++)
    {
        if (ch[i] > 64 && ch[i] < 91)
        {
            if (ch[i] > 64 && ch[i] < 78)
                ch[i]+=13;
            else
                ch[i]-=13;
        }
        if (ch[i] > 96 && ch[i] < 123)
        {
            if (ch[i] > 96 && ch[i] < 110)
                ch[i]+=13;
            else
                ch[i]-=13;
        }
    }
    printf("Encrypted text: ");
    for (int j = 0; j < len; j++)
    {
        printf("%c",ch[j]);
    }
    printf("\n");
    return 0;
}