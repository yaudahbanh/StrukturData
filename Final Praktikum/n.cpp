#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<long long> jeri;

    long long t;
    cin >> t;

    for (long long i = 0; i < t; i++)
    {
        long long n;
        cin >> n;

        if (n == 1) // Swap
        {
            if (jeri.empty())
            {
                jeri.push(1);
                jeri.push(0);
            }

            else if (jeri.size() == 1 && jeri.top() == 1)
            {
                jeri.pop();
            }

            else if (jeri.size() > 1)
            {
                if (jeri.top() == 1)
                {
                    jeri.pop();
                }

                else if (jeri.top() == 0)
                {
                    jeri.pop();
                    jeri.push(1);
                    jeri.push(0);
                    jeri.push(1);
                    jeri.push(0);
                }
            }
        }

        else if (n == 0) // Rotate
        {
            if (jeri.empty())
            {
                jeri.push(0);
            }

            else if (jeri.size() == 1 && jeri.top() == 1)
            {
                jeri.push(0);
            }

            else if (jeri.size() == 1 && jeri.top() == 0)
            {
                jeri.pop();
            }

            else if (jeri.size() > 1)
            {
                if (jeri.top() == 1)
                {
                    jeri.push(0);
                }

                else if (jeri.top() == 0)
                {
                    jeri.pop();
                }
            }
        }
    }

    cout << jeri.size() << endl;

    return 0;
}