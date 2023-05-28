#include <bits/stdc++.h>
using namespace std;


// https://www.geeksforgeeks.org/program-nth-catalan-number/
unsigned long int catalanDP(unsigned int n)
{
    unsigned long int catalan[n + 1];
 
    catalan[0] = catalan[1] = 1;
 
    for (int i = 2; i <= n; i++) {
        catalan[i] = 0;
        for (int j = 0; j < i; j++)
            catalan[i] += catalan[j] * catalan[i - j - 1];
    }
    return catalan[n];
}

int main()
{

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        unsigned long int gunung;
        cin >> gunung;
        unsigned long int bima = catalanDP(gunung);

        cout << bima << endl;
    }
}