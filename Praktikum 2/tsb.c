#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct bstnode_t
{
    char nama[10000];
    struct bstnode_t
        *left,
        *right, *ortu;
} BSTNode;

typedef struct bst_t
{
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode *__bst__createNode(BSTNode *ortu, char nama[])
{
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
    strcpy(newNode->nama, nama);
    newNode->left = newNode->right = NULL;
    newNode->ortu = ortu;
    return newNode;
}

BSTNode *__bst__insert(BSTNode *ortu, BSTNode *root, char nama[])
{
    if (root == NULL)
        return __bst__createNode(ortu, nama);

    if (strcmp(nama, root->nama) < 0)
        root->left = __bst__insert(root, root->left, nama);
    else if (strcmp(nama, root->nama) > 0)
        root->right = __bst__insert(root, root->right, nama);

    return root;
}

BSTNode *__bst__search(BSTNode *root, char nama[])
{
    while (root != NULL)
    {
        if (strcmp(nama, root->nama) < 0)
            root = root->left;
        else if (strcmp(nama, root->nama) > 0)
            root = root->right;
        else
            return root;
    }
    return root;
}

void bst_init(BST *bst)
{
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_find(BST *bst, char nama[])
{
    BSTNode *temp = __bst__search(bst->_root, nama);
    if (temp == NULL)
        return false;

    if (strcmp(temp->nama, nama) == 0)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, char nama[])
{
    if (!bst_find(bst, nama))
    {
        bst->_root = __bst__insert(bst->_root, bst->_root, nama);
        bst->_size++;
    }
}

int main()
{
    BST set;
    bst_init(&set);

    int a, b;

    scanf("%d %d", &a, &b);

    while (a--)
    {
        char namanya[100];
        scanf("%s", namanya);
        bst_insert(&set, namanya);
    }

    while (b--)
    {
        char keluarga[100];
        scanf("%s", keluarga);

        if (*keluarga == 'I')
        {
            char ibu[100];
            scanf("%s", ibu);
            BSTNode *temp = __bst__search(set._root, ibu);

            if (temp->ortu == NULL)
            {
                printf("Aku Adalah Pemimpin Keluarga Ini! HAHAHA\n");
            }

            else
            {
                printf("%s\n", temp->ortu);
            }
        }

        else
        {
            char selain[100];
            scanf("%s", selain);
            bst_insert(&set, selain);

            BSTNode *temp = __bst__search(set._root, selain);

            if (temp->left && temp->right != NULL)
            {
                printf("%s %s\n", temp->right->nama, temp->left->nama);
            }

            else if (temp->left != NULL)
            {
                printf("- %s\n", temp->left->nama);
            }

            else if (temp->right != NULL)
            {
                printf("%s -\n", temp->right->nama);
            }

            else {
                printf("Aku Sedih!! Tidak Memiliki Anak:)\n");
            }
        }
    }

    return 0;
}