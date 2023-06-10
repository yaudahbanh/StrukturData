#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Edge
{
    int start;
    int finish;
    int bahaya;
} Edge;

typedef struct uni
{
    vector<int> parent;
    vector<int> rank;
} uni;

void init(uni &uf, int n)
{
    uf.parent.resize(n + 1);
    uf.rank.resize(n + 1, 0);
    for (int i = 1; i <= n; i++)
        uf.parent[i] = i;
}

int find(uni &uf, int x)
{
    if (uf.parent[x] != x)
        uf.parent[x] = find(uf, uf.parent[x]);
    return uf.parent[x];
}

void unite(uni &uf, int x, int y)
{
    int rootX = find(uf, x);
    int rootY = find(uf, y);

    if (uf.rank[rootX] < uf.rank[rootY])
        uf.parent[rootX] = rootY;
    else if (uf.rank[rootX] > uf.rank[rootY])
        uf.parent[rootY] = rootX;
    else
    {
        uf.parent[rootY] = rootX;
        uf.rank[rootX]++;
    }
}

int cariBahayaGaksih(vector<Edge> &edges, int n)
{
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b)
         { return a.bahaya < b.bahaya; });

    uni uf;
    init(uf, n);
    int bahaya = 0;

    for (const auto &edge : edges)
    {
        int startroot = find(uf, edge.start);
        int finishroot = find(uf, edge.finish);

        if (startroot != finishroot)
        {
            unite(uf, startroot, finishroot);
            bahaya = max(bahaya, edge.bahaya);
        }
    }

    return bahaya;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<Edge> edges;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    int bahaya = cariBahayaGaksih(edges, n);
    cout << bahaya << endl;

    return 0;
}
