#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<string, int> mapping = {
    {"A1", 1}, {"B1", 2}, {"C1", 3},
    {"A2", 4}, {"B2", 5}, {"C2", 6},
    {"A3", 7}, {"B3", 8}, {"C3", 9}
};

void solveme(unordered_map<int, vector<int>> &hasil, vector<bool> &visited, vector<vector<int>> &arr, int node, int index)
{
    visited[node] = true;
    for (int neighbor : arr[node])
    {
        if (!visited[neighbor])
        {
            hasil[index].push_back(neighbor);
            solveme(hasil, visited, arr, neighbor, index);
        }
    }
}

int main()
{
    unordered_map<int, vector<int>> hasil;
    vector<vector<int>> arr(10);
    vector<bool> visited(10, false);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        string a, b, buang;
        cin >> a >> buang >> b;
        arr[mapping[a]].push_back(mapping[b]);
        arr[mapping[b]].push_back(mapping[a]);
    }

    int index = 1;
    for (int i = 1; i <= 9; i++)
    {
        if (!visited[i])
        {
            hasil[index].push_back(i);
            solveme(hasil, visited, arr, i, index);
            index++;
        }
    }

    int c = 0;
    index--;
    for (int i = 1; i <= index; i++)
    {
        c += (9 - hasil[i].size()) * hasil[i].size();
    }
    cout << c / 2;

    return 0;
}
