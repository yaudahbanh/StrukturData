#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        unordered_map<int, int> count;
        stack<int> harga;
        int maxnya = 0;

        for (int a = 0; a < n; a++)
        {
            int c;
            cin >> c;
            harga.push(c);
            count[c]++;
            maxnya = max(maxnya, count[c]);
        }

        int last = 0;
        int sizeofc = count.size();

        if (sizeofc == 1)
        {
            last = n;
        }
        else if (sizeofc == 2)
        {
            auto it = count.begin();
            int c1 = it->second;

            it++;

            int c2 = it->second;
            last = abs(c1 - c2);
        }
        else
        {
            int omagad = n / 2;
            if (maxnya <= omagad)
            {
                last = n % 2;
            }
            else
            {
                last = maxnya - (n - maxnya);
            }
        }

        cout << last << endl;
    }
    
    return 0;
}
