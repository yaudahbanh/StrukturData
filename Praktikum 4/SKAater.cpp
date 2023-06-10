#include <iostream>
#include <vector>
using namespace std;

void solveme(vector<vector<int>>& kosmikList, vector<bool>& ok, int a)
{
    ok[a] = true;
    for (auto i : kosmikList[a])
    {
        if (!ok[i])
        {
            solveme(kosmikList, ok, i);
        }
    }
}

int main()
{
    int n;
    int t;
    cin >> n >> t;

    vector<vector<int>> kosmikList(n);
    vector<bool> ok(n, false);

    for (int i = 0; i < t; i++)
    {
        int a, b;
        cin >> a >> b;
        kosmikList[a].push_back(b);
        kosmikList[b].push_back(a);
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!ok[i])
        {
            solveme(kosmikList, ok, i);
            count++;
        }
    }

    if (count == 1)
    {
        puts("Kompleksitas entitas terbentuk");
    }
    else
    {
        cout << "Seluruh kosmik tidak berkaitan, butuh " << count - 1 << " lagi ";
    }

    return 0;
}
