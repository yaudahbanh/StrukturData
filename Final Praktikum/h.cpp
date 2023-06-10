#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
} Node;

typedef struct BST
{
    struct Node *root;

    BST() : root(NULL) {}
} BST;

void insert(BST *bst, int val)
{
    Node **curr = &(bst->root);
    while (*curr)
    {
        if (val < (*curr)->data)
            curr = &((*curr)->left);
        else if (val > (*curr)->data)
            curr = &((*curr)->right);
        else
            return;
    }
    *curr = new Node(val);
}

int cariLevel(BST *bst, int val)
{
    Node *curr = bst->root;
    int level = 1;
    while (curr)
    {
        if (val < curr->data)
            curr = curr->left;
        else if (val > curr->data)
            curr = curr->right;
        else
            return level;
        level++;
    }
    return -1;
}

void inorder(Node *node, vector<int> &nums)
{
    if (!node)
        return;
    inorder(node->left, nums);
    nums.push_back(node->data);
    inorder(node->right, nums);
}

int cariKthKecil(BST *bst, int k)
{
    vector<int> nums;
    inorder(bst->root, nums);
    if (k >= 1 && k <= nums.size())
        return nums[k - 1];
    return -1;
}

bool cariLokasi(Node *node, int val, string &path)
{
    if (!node)
        return false;
    if (val == node->data)
    {
        path += 'S';
        return true;
    }
    if (val < node->data)
    {
        path += 'L';
        if (cariLokasi(node->left, val, path))
            return true;
        path.pop_back();
    }
    else
    {
        path += 'R';
        if (cariLokasi(node->right, val, path))
            return true;
        path.pop_back();
    }
    return false;
}

string Lokasi(BST *bst, int val)
{
    string path;
    cariLokasi(bst->root, val, path);
    return path;
}

int main()
{
    BST bst;

    string line;
    while (getline(cin, line))
    {
        istringstream iss(line);
        string cmd;
        iss >> cmd;

        if (cmd == "IN")
        {
            int num;
            iss >> num;
            insert(&bst, num);
        }
        else if (cmd == "FD")
        {
            int num;
            iss >> num;
            int level = cariLevel(&bst, num);
            if (level != -1)
                cout << "on level " << level << endl;
            else
                cout << "no " << num << endl;
        }
        else if (cmd == "RK")
        {
            int num;
            iss >> num;
            int kthSmallest = cariKthKecil(&bst, num);
            cout << kthSmallest << endl;
        }
        else if (cmd == "PH")
        {
            int num;
            iss >> num;
            string path = Lokasi(&bst, num);
            if (path.empty())
                cout << "no " << num << endl;
            else
                cout << path << endl;
        }
        else if (cmd == "STOP")
        {
            cout << "done" << endl;
            break;
        }
    }

    return 0;
}
