#include <iostream>
#include <vector>

using namespace std;

typedef struct bstnode_t
{
    int key, stamina;
    struct bstnode_t
        *left,
        *right;
} BSTNode;

typedef struct bst_t
{
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode *__bst__createNode(int value, int stamina)
{
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->stamina = stamina;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode *__bst__insert(BSTNode *root, int value, int stamina)
{
    if (root == NULL)
        return __bst__createNode(value, stamina);

    if (value < root->key)
        root->left = __bst__insert(root->left, value, stamina);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value, stamina);

    return root;
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

BSTNode *__bst__findMinNode(BSTNode *node)
{
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;

    return currNode;
}

BSTNode *__bst__remove(BSTNode *root, int value)
{
    if (root == NULL)
        return NULL;

    if (value > root->key)
        root->right = __bst__remove(root->right, value);
    else if (value < root->key)
        root->left = __bst__remove(root->left, value);
    else
    {

        if (root->left == NULL)
        {
            BSTNode *rightChild = root->right;
            free(root);
            return rightChild;
        }
        else if (root->right == NULL)
        {
            BSTNode *leftChild = root->left;
            free(root);
            return leftChild;
        }

        BSTNode *temp = __bst__findMinNode(root->right);
        root->key = temp->key;
        root->right = __bst__remove(root->right, temp->key);
    }
    return root;
}

void bst_init(BST *bst)
{
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_find(BST *bst, int start)
{
    BSTNode *temp = __bst__search(bst->_root, start);
    if (temp == NULL)
        return false;

    if (temp->key == start)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, int value, int stamina)
{
    if (!bst_find(bst, value))
    {
        bst->_root = __bst__insert(bst->_root, value, stamina);
        bst->_size++;
    }
}

void bst_remove(BST *bst, int value)
{
    if (bst_find(bst, value))
    {
        bst->_root = __bst__remove(bst->_root, value);
        bst->_size--;
    }
}

int findjarak(BSTNode *root, int posisi, int stamina)
{
    if (root)
    {
        stamina += root->stamina + 1;

        if (posisi > root->key)
        {
            return findjarak(root->right, posisi, stamina);
        }

        else if (posisi < root->key)
        {
            return findjarak(root->left, posisi, stamina);
        }
    }

    return stamina;
}

BSTNode *mencariAnc(BSTNode *root, int a, int b)
{
    if (root == NULL)
    {
        return NULL;
    }

    BSTNode *kiri = mencariAnc(root->left, a, b);
    BSTNode *kanan = mencariAnc(root->right, a, b);
    if (root->key == a || root->key == b)
    {
        return root;
    }
    if (kiri != NULL && kanan != NULL)
    {
        return root;
    }
    if (kanan != NULL)
    {
        return kanan;
    }
    else
    {
        return kiri;
    }
}

int main()
{
    BST pale;
    bst_init(&pale);

    int ts_start, ts_finish, ts_ancestor;

    int start, finish;

    cin >> start >> finish;

    int t;

    cin >> t;

    while (t--)
    {
        int a, b;

        cin >> a >> b;
        bst_insert(&pale, a, b);
    }

    ts_start = findjarak(pale._root, start, 0);
    ts_finish = findjarak(pale._root, finish, 0);
    ts_ancestor = findjarak(pale._root, mencariAnc(pale._root, start, finish)->key, 0);

    // cout << ts_start << " " << ts_finish << " "  << ts_ancestor;

    cout << (ts_start - 1) + (ts_finish - 1) - 2 * (ts_ancestor - 1) + mencariAnc(pale._root, start, finish)->stamina << endl;

    return 0;
}