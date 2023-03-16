#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int tanda = 0;

typedef struct pqueueNode_t
{
    int umur;
    int prio;
    char nama[100];

    struct pqueueNode_t *next;
} PQueueNode;

typedef struct pqueue_t
{
    PQueueNode *_top;
    unsigned _size;
} PriorityQueue;

void pqueue_init(PriorityQueue *pqueue)
{
    pqueue->_top = NULL;
    pqueue->_size = 0;
}

bool pqueue_isEmpty(PriorityQueue *pqueue)
{
    return (pqueue->_top == NULL);
}

void pqueue_push(PriorityQueue *pqueue, char namae[], int umur, int priority)
{
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode = (PQueueNode *)malloc(sizeof(PQueueNode));
    strcpy(newNode->nama, namae);
    newNode->umur = umur;
    newNode->prio = priority;
    newNode->next = NULL;

    if (pqueue_isEmpty(pqueue))
    {
        pqueue->_top = newNode;
        return;
    }

    if (priority < pqueue->_top->prio)
    {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
        return;
    }

    if (priority == pqueue->_top->prio && umur >= pqueue->_top->umur)
    {

        if (umur == pqueue->_top->umur)
        {
            printf("Kamu jodoh ya %s - %d && %s - %d\n", pqueue->_top->nama, pqueue->_top->prio, namae, priority);
            tanda = 1;
        }

        if (tanda == 0)
        {
            newNode->next = pqueue->_top;
            pqueue->_top = newNode;
        }
    }

    else
    {
        while ((temp->next != NULL && temp->next->prio < priority) || (temp->next != NULL && temp->next->prio == priority && umur <= temp->next->umur))
        {
            if (temp->next->umur == umur && temp->next->prio == priority)
            {
                printf("Kamu jodoh ya %s - %d && %s - %d\n", temp->next->nama, temp->next->prio, namae, priority);
                tanda = 1;
                break;
            }

            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void pqueue_pop(PriorityQueue *pqueue)
{
    if (!pqueue_isEmpty(pqueue))
    {
        PQueueNode *temp = pqueue->_top;
        pqueue->_top = pqueue->_top->next;
        free(temp);
    }
}

int pqueue_top(PriorityQueue *pqueue)
{
    if (!pqueue_isEmpty(pqueue))
        return pqueue->_top->prio;
    else
        return 0;
}

int main(int argc, char const *argv[])
{
    PriorityQueue myPque;

    pqueue_init(&myPque);

    int n, m;
    char namae[100];
    int umur;
    int priority;

    scanf("%d %d", &n, &m);

    if (n == m)
    {
        printf("Full senyum deck\n");
        tanda = 1;
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d", namae, &umur, &priority);

        if (tanda == 0)
        {
            pqueue_push(&myPque, namae, umur, priority);
        }
    }

    for (int i = 0; i < m; i++)
    {
        pqueue_pop(&myPque);
    }

    if (tanda == 0)
    {
        printf("Pasien selanjutnya adalah: %s - %d\n", myPque._top->nama, myPque._top->prio);
    }

    // DEBUG
    // while (!pqueue_isEmpty(&myPque))
    // {
    //     puts("");
    //     printf("%s %d %d", myPque._top->nama, myPque._top->umur, myPque._top->prio);
    //     pqueue_pop(&myPque);
    // }

}