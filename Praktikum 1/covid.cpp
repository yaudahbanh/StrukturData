#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>
using namespace std;

#define PB push_back
#define PBA pop_back

int main()
{

    vector<string> info, mint;

    char n[100], m[100];

    while (1)
    {
        scanf("%s", n);
        if (n[0] == '#')
        {
            break;
        }
        info.PB(n);
    }

    while (scanf("%s", m) != EOF)
    {
        mint.PB(m);
    }

    while (1)
    {

        if (mint.size() == 0)
        {
            printf("Bisa menang ini mah, gas mainin aja masbro\n");
            return 0;
        }

        if (info.front() == mint.front())
        {
            info.erase(info.begin());
            mint.erase(mint.begin());
            continue;
        }

        if (info.back() == mint.back())
        {
            info.PBA();
            mint.PBA();
            continue;
        }

        printf("Gabisa sumpah, game ini red flag banget sih\n");
        return 0;
    }

    printf("Bisa menang ini mah, gas mainin aja masbro\n");
}