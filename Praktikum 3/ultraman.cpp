#include <iostream>
#include <map>
#include <vector>

using namespace std;

// copas guthib
struct AVLNode
{
    int data;
    AVLNode *left, *right;
    int height;
    int power;
};

// copas guthib
struct AVL
{
    AVLNode *_root;
    unsigned _size;

    AVLNode *_avl_createNode(int value, int power)
    {
        AVLNode *newNode = (AVLNode *)malloc(sizeof(AVLNode));
        newNode->data = value;
        newNode->height = 1;
        newNode->power = power;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    AVLNode *_search(AVLNode *root, int value)
    {
        while (root != NULL)
        {
            if (value < root->data)
                root = root->left;
            else if (value > root->data)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    int _getHeight(AVLNode *node)
    {
        if (node == NULL)
            return 0;
        return node->height;
    }

    int _max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    AVLNode *_rightRotate(AVLNode *pivotNode)
    {
        AVLNode *newParrent = pivotNode->left;
        pivotNode->left = newParrent->right;
        newParrent->right = pivotNode;

        pivotNode->height = _max(_getHeight(pivotNode->left),
                                 _getHeight(pivotNode->right)) +
                            1;
        newParrent->height = _max(_getHeight(newParrent->left),
                                  _getHeight(newParrent->right)) +
                             1;

        return newParrent;
    }

    AVLNode *_leftRotate(AVLNode *pivotNode)
    {
        AVLNode *newParrent = pivotNode->right;
        pivotNode->right = newParrent->left;
        newParrent->left = pivotNode;

        pivotNode->height = _max(_getHeight(pivotNode->left),
                                 _getHeight(pivotNode->right)) +
                            1;
        newParrent->height = _max(_getHeight(newParrent->left),
                                  _getHeight(newParrent->right)) +
                             1;

        return newParrent;
    }

    AVLNode *_leftCaseRotate(AVLNode *node)
    {
        return _rightRotate(node);
    }

    AVLNode *_rightCaseRotate(AVLNode *node)
    {
        return _leftRotate(node);
    }

    AVLNode *_leftRightCaseRotate(AVLNode *node)
    {
        node->left = _leftRotate(node->left);
        return _rightRotate(node);
    }

    AVLNode *_rightLeftCaseRotate(AVLNode *node)
    {
        node->right = _rightRotate(node->right);
        return _leftRotate(node);
    }

    int _getBalanceFactor(AVLNode *node)
    {
        if (node == NULL)
            return 0;
        return _getHeight(node->left) - _getHeight(node->right);
    }

    AVLNode *_insert_AVL(AVLNode *node, int value, int power)
    {

        if (node == NULL)
            return _avl_createNode(value, power);
        if (value < node->data)
            node->left = _insert_AVL(node->left, value, power);
        else if (value > node->data)
            node->right = _insert_AVL(node->right, value, power);

        node->height = 1 + _max(_getHeight(node->left), _getHeight(node->right));

        int balanceFactor = _getBalanceFactor(node);

        if (balanceFactor > 1 && value < node->left->data)
            return _leftCaseRotate(node);
        if (balanceFactor > 1 && value > node->left->data)
            return _leftRightCaseRotate(node);
        if (balanceFactor < -1 && value > node->right->data)
            return _rightCaseRotate(node);
        if (balanceFactor < -1 && value < node->right->data)
            return _rightLeftCaseRotate(node);

        return node;
    }

    AVLNode *_findMinNode(AVLNode *node)
    {
        AVLNode *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;
        return currNode;
    }

    AVLNode *_remove_AVL(AVLNode *node, int value)
    {
        if (node == NULL)
            return node;
        if (value > node->data)
            node->right = _remove_AVL(node->right, value);
        else if (value < node->data)
            node->left = _remove_AVL(node->left, value);
        else
        {
            AVLNode *temp;
            if ((node->left == NULL) || (node->right == NULL))
            {
                temp = NULL;
                if (node->left == NULL)
                    temp = node->right;
                else if (node->right == NULL)
                    temp = node->left;

                if (temp == NULL)
                {
                    temp = node;
                    node = NULL;
                }
                else
                    *node = *temp;

                free(temp);
            }
            else
            {
                temp = _findMinNode(node->right);
                node->data = temp->data;
                node->right = _remove_AVL(node->right, temp->data);
            }
        }

        if (node == NULL)
            return node;

        node->height = _max(_getHeight(node->left), _getHeight(node->right)) + 1;

        int balanceFactor = _getBalanceFactor(node);

        if (balanceFactor > 1 && _getBalanceFactor(node->left) >= 0)
            return _leftCaseRotate(node);

        if (balanceFactor > 1 && _getBalanceFactor(node->left) < 0)
            return _leftRightCaseRotate(node);

        if (balanceFactor < -1 && _getBalanceFactor(node->right) <= 0)
            return _rightCaseRotate(node);

        if (balanceFactor < -1 && _getBalanceFactor(node->right) > 0)
            return _rightLeftCaseRotate(node);

        return node;
    }

    void _inorder(AVLNode *node)
    {
        if (node)
        {
            _inorder(node->left);
            printf("%d ", node->data);
            _inorder(node->right);
        }
    }

    void init()
    {
        _root = NULL;
        _size = 0U;
    }

    bool isEmpty()
    {
        return _root == NULL;
    }

    bool find(int value)
    {
        AVLNode *temp = _search(_root, value);
        if (temp == NULL)
            return false;

        if (temp->data == value)
            return true;
        else
            return false;
    }

    void insert(int value, int power)
    {
        if (!find(value))
        {
            _root = _insert_AVL(_root, value, power);
            _size++;
        }
    }

    void remove(int value)
    {
        if (find(value))
        {
            _root = _remove_AVL(_root, value);
            _size--;
        }
    }

    void inorder()
    {
        this->_inorder(_root);
    }
};

// cek kiri dan kanan + 1
void bagiandiagonal(map<int, vector<AVLNode *>> &bima, AVLNode *sman5, int yangke)
{
    if (sman5)
    {
        bagiandiagonal(bima, sman5->left, yangke);
        bima[yangke].push_back(sman5);
        bagiandiagonal(bima, sman5->right, yangke + 1);
    }
}

int main(int argc, char const *argv[])
{
    AVL set;
    set.init();
    map<int, vector<AVLNode *>> bima;

    int inputan;
    int banyakpower;
    string planet;

    cin >> inputan >> banyakpower >> planet;

    for (int i = 0; i < inputan; i++)
    {
        int node;
        int power;

        cin >> node >> power;
        set.insert(node, power);
    }

    AVLNode *temp = set._root;
    int banyakdiagonal = 0;

    while (temp != NULL) // mencari banyak diagonal
    {
        banyakdiagonal++;
        temp = temp->right;
    }

    bagiandiagonal(bima, set._root, 1);

    cout << "Ultraman lapet(Power: " << banyakpower << ")" << endl;
    cout << "Planet: " << planet << endl;
    cout << "-----------------------" << endl;

    int mati = 0;

    for (int i = 1; i <= banyakdiagonal; i++)
    {
        int attack = 0;
        char abc = 'A'; // set ke A

        if (i != 1)
        {
            cout << "=>" << endl;
        }
        
        if (i != banyakdiagonal)
        {
            cout << "Stage " << i << ":" << endl;
            for (int j = 1; j <= bima[i].size(); j++)
            {
                attack += bima[i][j - 1]->power;
                cout << "Monster " << abc++ << bima[i][j-1]->data << "_" << i << "_" << j << ": " << bima[i][j - 1]->power << endl;
            }
        }

        else
        {
            cout << "Final Stage:" << endl;
            for (int k = 1; k <= bima[i].size(); k++)
            {
                attack += bima[i][k - 1]->power;
                cout << "Boss " << planet << "_" << bima[i][k - 1]->data << ": " << bima[i][k - 1]->power << endl;
            }
        }

        if (i % 2 == 0) // genap
        {
            attack *= 0.8;
        }

        else // ganjil
        {
            attack *= 0.9;
        }

        banyakpower -= attack;

        if (banyakpower < 0 && mati == 0) // matinya di stage ke berapa
        {
            mati = i;
        }
    }

    cout << "\nResult:" << endl;
    if (banyakpower > 0)
    {
        cout << "Ultraman Lapet lolos dari Planet " << planet << endl;
    }
    else if (mati == banyakdiagonal)
    {
        cout << "Ultraman Lapet terperangkap di Planet " << planet << " pada Final Stage" << endl;
    }
    else if (mati < banyakdiagonal)
    {
        cout << "Ultraman Lapet terperangkap di Planet " << planet << " pada Stage " << mati << endl;
    }
}