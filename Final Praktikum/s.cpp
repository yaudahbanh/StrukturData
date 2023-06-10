#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#define PB push_back
using namespace std;

int main()
{
    vector<string> array;
    int t, n;
    cin >> t >> n;
    for (int a = 0; a < t; a++)
    {
        string b;
        cin >> b;
        array.PB(b); // push
    }
    int flag = 0;
    for (int i = 0; i < array.size(); i++)
    {
        for (int j = 0; j < array.size(); j++)
        {
            if (i == j)
                continue;
            string temp = "";
            temp = temp + array[i];
            temp = temp + array[j];

            if (stol(temp) % n == 0)
            {
                flag++;
            }
        }
    }
    cout << flag;

    return 0;
}