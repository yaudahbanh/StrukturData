#include <bits/stdc++.h>
using namespace std;

bool flag = 0;

typedef struct bstnode_t
{
    int key;
    struct bstnode_t
        *left,
        *right, *ortu;
} BSTNode;

typedef struct bst_t
{
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode *__bst__createNode(BSTNode *root, int value)
{
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->ortu = root;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode *__bst__insert(BSTNode *root, BSTNode *node, int value)
{
    if (node == NULL)
        return __bst__createNode(root, value);
    if (value < node->key)
        node->left = __bst__insert(node, node->left, value);

    else if (value > node->key)
        node->right = __bst__insert(node, node->right, value);

    return node;
}

BSTNode *__bst__search(BSTNode *root, int value)
{
    while (root != NULL)
    {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
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

bool bst_isEmpty(BST *bst)
{
    return bst->_root == NULL;
}

BSTNode *bst_find(BST *bst, int value)
{
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return NULL;

    if (temp->key == value)
        return temp;
    else
        return NULL;
}

void bst_insert(BST *bst, int value)
{
    if (!bst_find(bst, value))
    {
        bst->_root = __bst__insert(bst->_root, bst->_root, value);
        bst->_size++;
    }
}

void cari(BSTNode *root, long long value)
{
    BSTNode *temp = root;
    long long jumlah;
    if (temp)
    {
        if (temp->ortu)
        {
            if (temp->left)
            {
                jumlah = temp->key + temp->ortu->key + temp->left->key;
                if ((jumlah == value))
                {
                    flag = 1;
                    return;
                }
            }
            if (temp->right)
            {
                jumlah = temp->key + temp->ortu->key + temp->right->key;
                if ((jumlah == value))
                {
                    flag = 1;
                    return;
                }
            }
        }
        if (temp->left && temp->right)
        {
            jumlah = temp->key + temp->left->key + temp->right->key;
            if ((jumlah == value))
            {
                flag = 1;
                return;
            }
        }
        cari(temp->left, value);
        cari(temp->right, value);
    }
}

int main()
{
    BST set;
    bst_init(&set);
    long long n, t;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        bst_insert(&set, x);
    }
    cin >> t;
    cari(set._root, t);
    if (flag)
    {
        cout << t << " Selamat! Kalian menemukan harta karunnya" << endl;
        return 0;
    }
    cout << t << " Tidak ada kombinasi yang tepat! Bikin ulang." << endl;

    return 0;
}
