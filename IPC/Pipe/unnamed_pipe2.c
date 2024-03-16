#include<stdio.h>
#include<unistd.h>

int main()
{
    int fd[2], id;
    char str1[30], str2[30];
    id = pipe(fd);
    if (id < 0)
    {
        perror("pipe() failed!\n");
        _exit(0);
    }
    printf("Enter the string: ");
    scanf("%[^\n]s", str1);
    write(fd[1], str1, sizeof(str1));
    read(fd[0], str2, sizeof(str2));
    printf("Receiver: %s\n", str2);
    close(fd[1]);
    close(fd[0]);
    return 0;
}