#include <iostream>
#include <set>
using namespace std;

set<int> leaf;

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

BSTNode *__bst__createNode(int value)
{
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode *__bst__insert(BSTNode *root, int value)
{
    if (root == NULL)
        return __bst__createNode(value);

    if (value < root->key)
        root->left = __bst__insert(root->left, value);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value);

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

bool bst_find(BST *bst, int value)
{
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;

    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, int value)
{
    if (!bst_find(bst, value))
    {
        bst->_root = __bst__insert(bst->_root, value);
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

void findleaf(BSTNode *daun)
{
    if (daun)
    {
        if (daun->left == NULL && daun->right == NULL)
        {
            leaf.insert(daun->key);
        }

        findleaf(daun->left);
        findleaf(daun->right);
    }
}


int main()
{
    BST okok;
    bst_init(&okok);

    set<int> bima;

    int t;
    scanf("%d", &t);
    while (t--)
    {
        int a;
        scanf("%d", &a);
        bst_insert(&okok, a);
        bima.insert(a);
    }

    findleaf(okok._root);

    int q;

    scanf("%d", &q);

    int infokan = 0;

    while (q--)
    {
        infokan = 0;
        int x;
        scanf("%d", &x);

        for (auto i : bima)
        {
            if (bst_find(&okok, (x - i)) && i != (x - i))
            {
                printf("Aceng mengambil: %d dan %d\n", i, x - i);
                bst_remove(&okok, x - i);
                bst_remove(&okok, i);
                leaf.erase(x - i);
                leaf.erase(i);
                bima.erase(x - i);
                bima.erase(i);
                infokan = 1;
                break;
            }

            if ((x - i) == i)
            {
                break;
            }
            
        }

        if (infokan == 0)
        {
            int ricardo = 0;
            printf("[");
            for (auto i : leaf)
            {
                printf("%d", i);
                if (ricardo != leaf.size() - 1)
                {
                    printf(", ");
                }

                ricardo++;
            }

            printf("]\n");
        }
    }

    return 0;
}