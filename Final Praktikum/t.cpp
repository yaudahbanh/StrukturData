#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adjList;
vector<bool> kunjungan;
vector<int> ortu;

void masukanEdge(int u, int v)
{
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void BFS(int start, int finish)
{
    queue<int> q;
    q.push(start);
    kunjungan[start] = true;

    while (!q.empty())
    {
        int currNode = q.front();
        q.pop();

        if (currNode == finish)
            return;

        for (int neighbor : adjList[currNode])
        {
            if (!kunjungan[neighbor])
            {
                kunjungan[neighbor] = true;
                q.push(neighbor);
                ortu[neighbor] = currNode;
            }
        }
    }
}

void printJalan(int finish)
{
    vector<int> path;
    int currNode = finish;

    while (currNode != -1)
    {
        path.push_back(currNode);
        currNode = ortu[currNode];
    }

    int panjangJalan = path.size();
    cout << panjangJalan << endl;

    for (int i = panjangJalan - 1; i >= 0; i--)
        cout << path[i] << " ";
}

int main()
{
    int N, E;
    cin >> N >> E;

    adjList.resize(N + 1);
    kunjungan.resize(N + 1, false);
    ortu.resize(N + 1, -1);

    int A, B;
    for (int i = 0; i < E; i++)
    {
        cin >> A >> B;
        masukanEdge(A, B);
    }

    int start = 1;
    int finish = N;

    BFS(start, finish);

    if (kunjungan[finish])
        printJalan(finish);
    else
        cout << "RIP LAPET 2023" << endl;

    return 0;
}
