#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/msg.h>
#define MSG_KEY 0x00009801

typedef struct Independent_Process2
{
    long type;
    char data[30];
}mq_t;

int main()
{
    int mqid;
    mqid = msgget(MSG_KEY, 0);
    if (mqid < 0)
    {
        perror("msgget() failed!\n");
        _exit(0);
    }
    mq_t m2;
    //Receiver
    msgrcv(mqid, &m2, sizeof(m2.data), 21, 0);
    printf("Process 2 Receiver: %s\n", m2.data);

    //Sender
    printf("Process 2 Sender: Pass msg:- ");
    scanf("%[^\n]s", m2.data);
    m2.type = 22;
    msgsnd(mqid, &m2, sizeof(m2.data), 0);
    return 0;
}