#include <stdio.h>
#include <stdlib.h>

typedef struct TNode
{
    int data;
    struct TNode *next;
} TNode;

TNode *head, *tail;

void init()
{
    head = NULL;
    tail = NULL;
}

int isEmpty()
{
    return head == NULL;
}

void insertdepan(int databaru)
{
    TNode *baru = (TNode *)malloc(sizeof(TNode));
    baru->data = databaru;
    baru->next = NULL;

    while (databaru > baru->next)
    {
        /* code */
    }
    

    if (isEmpty())
    {
        head = tail = baru;
    }
    else
    {
        baru->next = head;
        head = baru;
    }

    // printf("Data sudah masuk\n");
}

void insertbelakang(int databaru)
{
    TNode *baru = (TNode *)malloc(sizeof(TNode));
    baru->data = databaru;
    baru->next = NULL;

    if (isEmpty())
    {
        head = baru;
        tail = baru;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }

    // printf("Data sudah masuk\n");
}

void tampil()
{
    TNode *bantu = head;
    while (bantu != NULL)
    {
        printf("%d ", bantu->data);
        bantu = bantu->next;
    }
}

int main()
{
    init();

    int t;

    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        int a, b;

        scanf("%d %d", &a, &b);

        if (a == 1)
        {
            insertdepan(b);
        }

        else if (a == 2)
        {
            insertbelakang(b);
        }
    }

    tampil();

    return 0;
}
