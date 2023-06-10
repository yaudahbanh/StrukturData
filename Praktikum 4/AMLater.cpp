#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bfsolving(const vector<vector<int>>& arr, int size)
{
    vector<bool> berkunjung(size, false);
    queue<int> q;
    q.push(0);
    berkunjung[0] = true;

    while (!q.empty())
    {
        int area = q.front();
        q.pop();

        for (int i = 0; i < arr[area].size(); i++)
        {
            int areaselanjutnya = arr[area][i];
            if (!berkunjung[areaselanjutnya])
            {
                berkunjung[areaselanjutnya] = true;
                q.push(areaselanjutnya);
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        if (!berkunjung[i])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int t;
    cin >> t;

    vector<vector<int>> arr(t);
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        while (n--)
        {
            int a;
            cin >> a;
            arr[i].push_back(a);
        }
    }

    if (bfsolving(arr, t))
    {
        cout << "Para peserta LBH berhasil keluar!\n";
    }
    else
    {
        cout << "Para peserta LBH terjebak selamanya.\n";
    }

    return 0;
}
