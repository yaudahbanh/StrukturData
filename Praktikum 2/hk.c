#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int flag = 0;

typedef struct bstnode_t
{
    int key;
    struct bstnode_t
        *left,
        *right;
} BSTNode;

typedef struct bst_t
{
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode *_bst_createNode(int value)
{
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode *_bst_insert(BSTNode *root, int value)
{
    if (root == NULL)
        return _bst_createNode(value);

    if (value < root->key)
        root->left = _bst_insert(root->left, value);
    else if (value > root->key)
        root->right = _bst_insert(root->right, value);

    return root;
}

void bst_insert(BST *bst, int value)
{

    bst->_root = _bst_insert(bst->_root, value);
    bst->_size++;
}

void bst_init(BST *bst)
{
    bst->_root = NULL;
    bst->_size = 0u;
}

void preorder(BSTNode *root)
{
    if (root)
    {
        if (root->key % 2 != 0)
        {
            printf("%d ", root->key);
            flag++;
        }

        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{

    BST set;
    bst_init(&set);

    int t;
    scanf("%d", &t);

    int a;
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &a);
        bst_insert(&set, a);
    }

    preorder(set._root);
    printf("%d", flag + 17);
    
    return 0;
}