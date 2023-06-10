#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<long long>> AdJ;

long long BFS(long long start)
{
    long long n = AdJ.size();
    vector<bool> kunjungan(n, false);
    vector<long long> steps(n, -1);
    queue<long long> q;

    kunjungan[start] = true;
    steps[start] = 0;
    q.push(start);

    while (!q.empty())
    {
        long long curr = q.front();
        q.pop();

        for (long long neighbor : AdJ[curr])
        {
            if (neighbor == start)
            {
                return steps[curr] + 1;
            }
            if (!kunjungan[neighbor])
            {
                kunjungan[neighbor] = true;
                steps[neighbor] = steps[curr] + 1;
                q.push(neighbor);
            }
        }
    }

    return -1;
}

void addgraf(long long a, long long b)
{
    AdJ[a].push_back(b);
}

int main()
{
    long long n;
    cin >> n;
    AdJ.resize(n);

    while (true)
    {
        long long a, b;
        cin >> a >> b;
        if (a == -1 && b == -1)
        {
            break;
        }
        addgraf(a, b);
    }

    for (long long i = 0; i < n; i++)
    {
        long long result = BFS(i);
        if (result == -1)
        {
            cout << "gak bisa pulang mamah" << endl;
        }
        else
        {
            cout << result << endl;
        }
    }

    return 0;
}
