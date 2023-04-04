#include <stdio.h>
#include <stdlib.h>

typedef struct TNode
{
    int data;
    struct TNode *next, *prev;
} TNode;

TNode *head, *tail;

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

void Tambahdepan(int data)
{
    TNode *baru = (TNode *)malloc(sizeof(TNode));
    baru->data = data;
    baru->next = NULL;
    baru->prev = NULL;
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        head->next = NULL;
        head->prev = NULL;
        tail->prev = NULL;
        tail->next = NULL;
    }
    else
    {
        baru->next = head;
        head->prev = baru;
        head = baru;
    }
}

void Tambahbelakang(int data)
{
    TNode *baru = (TNode *)malloc(sizeof(TNode));
    baru->data = data;
    baru->next = NULL;
    baru->prev = NULL;
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        head->next = NULL;
        head->prev = NULL;
        tail->prev = NULL;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
        tail->next = NULL;
    }
}

void Hapusdepan()
{
    TNode *hapus;
    int d;
    if (isEmpty() == 0)
    {
        if (head->next != NULL)
        {
            hapus = head;
            d = hapus->data;
            head = head->next;
            head->prev = NULL;
            free(hapus);
        }
        else
        {
            d = head->data;
            head = NULL;
            tail = NULL;
        }
        printf("%d terhapus\n", d);
    }
    // else
    //     printf("Data masih kosong\n");
}

void Hapusbelakang()
{
    TNode *hapus;
    int d;
    if (isEmpty() == 0)
    {
        if (head->next != NULL)
        {
            hapus = tail;
            d = tail->data;
            tail = tail->prev;
            tail->next = NULL;
            free(hapus);
        }
        else
        {
            d = head->data;
            head = NULL;
            tail = NULL;
        }
        printf("%d terhapus\n", d);
    }
    // else
    //     printf("Data masih kosong\n");
}

void tampil()
{
    TNode *bantu;
    bantu = head;

    if (isEmpty() == 0)
    {
        while (bantu != NULL)
        {
            printf("%d ", bantu->data);
            bantu = bantu->next;
        }
        printf("\n");
    }
    // else
    // {
    //     printf("Datanya masih kosong coy\n");
    // }
}

void tampilreverse()
{
    TNode *bantu;
    bantu = tail;

    if (isEmpty() == 0)
    {
        while (bantu != NULL)
        {
            printf("%d ", bantu->data);
            bantu = bantu->prev;
        }
        printf("\n");
    }
    // else
    // {
    //     printf("Datanya masih kosong coy\n");
    // }
}

int main()
{

    // a untuk insert depan
    // b untuk insert belakang
    int a, b;
    scanf("%d %d", &a, &b);

    for (int i = 0; i < a; i++)
    {
        int data;
        scanf("%d", &data);
        Tambahdepan(data);
    }

    for (int i = 0; i < b; i++)
    {
        int datanya;
        scanf("%d", &datanya);
        Tambahbelakang(datanya);
    }

    puts("");
    Hapusdepan();
    Hapusbelakang();
    puts("");
    printf("Tampil Data : \n");
    tampil();
    printf("Tampil Data Terbalik : \n");
    tampilreverse();

    return 0;
}