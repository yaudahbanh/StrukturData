#include <iostream>
#include <stdio.h>
using namespace std;

long long mod = 1000000009;

long long pow(long long a, long long b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
            res = (res * a) % mod;
        b = b >> 1;
        a = (a * a) % mod;
    }
    return res % mod;
}

int main()
{
    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        long long n;
        cin >> n;

        printf("Zodiak found: %d signs\n", pow(2, n * (n - 1) / 2) % mod);
    }

    return 0;
}
