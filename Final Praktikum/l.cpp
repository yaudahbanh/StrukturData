#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct BSTNode {
    long long key;
    struct BSTNode* left;
    struct BSTNode* right;
    struct BSTNode* parent;
} BSTNode;

typedef struct BST {
    BSTNode* root;
    unsigned long long size;
} BST;

BSTNode* createNode(BSTNode* root, long long value) {
    BSTNode* newNode = new BSTNode;
    newNode->key = value;
    newNode->parent = root;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

BSTNode* insert(BSTNode* root, BSTNode* node, long long value) {
    if (node == nullptr)
        return createNode(root, value);

    if (value < node->key)
        node->left = insert(node, node->left, value);
    else if (value > node->key)
        node->right = insert(node, node->right, value);

    return node;
}

BSTNode* search(BSTNode* root, int value) {
    while (root != nullptr) {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}

void initializeBST(BST* bst) {
    bst->root = nullptr;
    bst->size = 0u;
}

bool isEmpty(BST* bst) {
    return bst->root == nullptr;
}

BSTNode* find(BST* bst, int value) {
    BSTNode* temp = search(bst->root, value);
    if (temp == nullptr)
        return nullptr;

    if (temp->key == value)
        return temp;
    else
        return nullptr;
}

void insertValue(BST* bst, int value) {
    if (find(bst, value) == nullptr) {
        bst->root = insert(bst->root, bst->root, value);
        bst->size++;
    }
}

long long maks = 0;

void solve(BSTNode* root, vector<long long>& arr, long long level) {
    if (root) {
        long long idx = level;
        arr[idx] = max(root->key, arr[idx]);
        maks = max(maks, level);
        solve(root->left, arr, level + 1);
        solve(root->right, arr, level + 1);
    }
}

int main() {
    BST bst;
    initializeBST(&bst);

    long long numb, count = 0;
    while (cin >> numb) {
        insertValue(&bst, numb);
        count++;
    }

    vector<long long> arr(count, 0);
    solve(bst.root, arr, 0);

    for (long long i = 0; i < count; i++) {
        if (arr[i] != 0) {
            cout << arr[i] << endl;
            continue;
        }
    }

    return 0;
}
