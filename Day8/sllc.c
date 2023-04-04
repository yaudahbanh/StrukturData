#include <stdio.h>
#include <stdlib.h>

typedef struct TNODE
{
    int data;
    struct TNODE *next;
} TNODE;

TNODE *head, *tail;

void init()
{
    head = NULL;
    tail = NULL;
}

int isEmpty()
{
    if (tail == NULL)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

void tambahdepan(int databaru)
{
    TNODE *baru = (TNODE *)malloc(sizeof(TNODE));
    baru->data = databaru;
    baru->next = baru;

    if (isEmpty() == 1)
    {
        head = baru;
        tail = baru;
    }

    else
    {
        baru->next = head;
        head = baru;
        tail->next = head;
    }

    // printf("Data sudah masuk\n");
}

void hapusdepan()
{
    TNODE *hapus;

    if (isEmpty() == 0)
    {
        int a;
        hapus = head;
        a = head->data;

        if (head != tail) // Selama jumlah inputan lebih dari 1
        {
            head = head->next;
            tail->next = head;
            free(hapus);
        }

        else
        {
            head = NULL;
            tail = NULL;
        }

        printf("%d data telah terhapus\n", a);
    }

    else
    {
        printf("kosong\n");
    }
}

void tampil()
{
    TNODE *b;
    b = head;

    if (isEmpty() == 0)
    {
        do
        {
            printf("%d ", b->data);
            b = b->next;
        } while (b != head);

        printf("\n");
    }

    else
    {
        printf("Data masih kosong\n");
    }
}

int main()
{
    int t;

    init();

    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        int a;
        scanf("%d", &a);

        tambahdepan(a);
    }

    hapusdepan();

    tampil();
}
