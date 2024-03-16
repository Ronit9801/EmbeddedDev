#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/msg.h>
#define MSG_KEY 0x00009801

typedef struct Independent_Process1
{
    long type;
    char data[30];
}mq_t;

int main()
{
    int mqid;
    mqid = msgget(MSG_KEY, IPC_CREAT|0644);
    if (mqid < 0)
    {
        perror("msgget() failed!\n");
        _exit(0);
    }
    mq_t m1;
    //Sender
    printf("Process 1 Sender: Pass msg:- ");
    scanf("%[^\n]s", m1.data);
    m1.type = 21;
    msgsnd(mqid, &m1, sizeof(m1.data), 0);

    //Receiver
    msgrcv(mqid, &m1, sizeof(m1.data), 22, 0);
    printf("Process 1 Receiver: %s\n", m1.data);
    msgctl(mqid, IPC_RMID, NULL);
    return 0;
}