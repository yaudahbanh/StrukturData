#include <iostream>
#include <cstring>
using namespace std;

const int MAX_SIZE = 105;
bool denah[MAX_SIZE][MAX_SIZE];

void solveme(int i, int j, int n)
{
    if (i < 1 || i > n || j < 1 || j > n || !denah[i][j])
        return;

    denah[i][j] = false;
    solveme(i + 1, j, n);
    solveme(i - 1, j, n);
    solveme(i, j + 1, n);
    solveme(i, j - 1, n);
    solveme(i + 1, j + 1, n);
    solveme(i + 1, j - 1, n);
    solveme(i - 1, j + 1, n);
    solveme(i - 1, j - 1, n);
}

int main()
{
    memset(denah, false, sizeof(denah));
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        for (int j = 1; j <= t; j++)
        {
            char a;
            cin >> a;
            denah[i][j] = (a == '+');
        }
    }
    int flag = 0;
    for (int i = 1; i <= t; i++)
    {
        for (int j = 1; j <= t; j++)
        {
            if (denah[i][j])
            {
                solveme(i, j, t);
                flag++;
            }
        }
    }
    cout << flag;

    return 0;
}
