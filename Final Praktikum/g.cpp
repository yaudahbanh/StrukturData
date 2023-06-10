#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *insertNode(Node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
        return root;
    }

    if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertNode(root->right, data);
    }

    return root;
}

void CariNodeUserBlueArchive(Node *root, vector<int> &result)
{
    if (root == NULL)
    {
        return;
    }

    if ((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL))
    {
        result.push_back(root->data);
    }

    CariNodeUserBlueArchive(root->left, result);
    CariNodeUserBlueArchive(root->right, result);
}

Node *hapusNode(Node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }

    if (data < root->data)
    {
        root->left = hapusNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = hapusNode(root->right, data);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        Node *temp = root->right;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = hapusNode(root->right, temp->data);
    }

    return root;
}

int main()
{
    int t;
    cin >> t;

    Node *root = NULL;

    for (int i = 0; i < t; i++)
    {
        int operasiangka, data;
        cin >> operasiangka;

        if (operasiangka == 15)
        {
            cin >> data;
            root = insertNode(root, data);
        }
        else if (operasiangka == 04)
        {
            cin >> data;
            root = hapusNode(root, data);
        }
        else if (operasiangka == 89)
        {
            vector<int> result;
            CariNodeUserBlueArchive(root, result);
            if (result.empty())
            {
                cout << "Use whatever means you must to control our population. Just do it.\n";
            }
            else
            {
                sort(result.begin(), result.end());
                for (int j = 0; j < result.size(); j++)
                {
                    cout << result[j] << " ";
                }
                cout << endl;
            }
        }
    }

    return 0;
}
