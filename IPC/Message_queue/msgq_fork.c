#include<stdio.h>
#include<unistd.h>
#include<sys/msg.h>
#include<sys/wait.h>
#define MSG_KEY 0x00009801

typedef struct msgq_fork
{
    long type;
    char data[30];
}mq_t;


int main()
{
    int mqid, s, ret;
    mqid = msgget(MSG_KEY, IPC_CREAT|0644);
    if (mqid < 0)
    {
        perror("msgget() failed!\n");
        _exit(0);
    }
    ret = fork();
    if (ret == 0)
    {
        //child process
        mq_t m1;
        printf("Child sender: Pass the msg:- ");
        scanf("%[^\n]s", m1.data);
        m1.type = 21;
        msgsnd(mqid, &m1, sizeof(m1.data), 0);

        msgrcv(mqid, &m1, sizeof(m1.data), 22, 0);
        printf("Child receiver: %s\n", m1.data);
    }
    else
    {
        //parent process
        mq_t m2;
        msgrcv(mqid, &m2, sizeof(m2.data), 21, 0);
        printf("Parent receiver: %s\n",m2.data);

        printf("Parent sender: Pass the msg:- ");
        scanf("%[^\n]s", m2.data);
        m2.type = 22;
        msgsnd(mqid, &m2, sizeof(m2.data), 0);
        waitpid(-1, &s, 0);
    }
    msgctl(mqid, IPC_RMID, NULL);
    return 0;
}