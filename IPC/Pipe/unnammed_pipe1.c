#include<stdio.h>
#include<unistd.h>

int main()
{
    int fd[2], ret;
    char str1[30], str2[30];
    ret = pipe(fd);
    if (ret < 0)
    {
        perror("pipe() failed!\n");
        _exit(0);
    }
    ret = fork();
    if (ret == 0)
    {
        //Writer process
        close(fd[0]);
        printf("Enter the string: ");
        scanf("%[^\n]s", str1);
        write(fd[1], str1, sizeof(str1));
        close(fd[1]);
    }
    else
    {
        //Reader process
        close(fd[1]);
        read(fd[0], str2, sizeof(str2));
        printf("Receiver: %s\n", str2);
        close(fd[0]);
    }
    return 0;
}