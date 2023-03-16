#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define iyach map<ll, ll>

int main()
{

    iyach pointnya;

    int t;
    ll highscore = -9223372036854775807;
    ll top = 0;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        ll id;
        ll jumlahpemain;
        ll pemainlolos;

        cin >> id;
        cin >> jumlahpemain;
        cin >> pemainlolos;

        pointnya[id] += jumlahpemain * 500 - 200 * pemainlolos;

        if (pointnya[id] >= highscore)
        {
            highscore = pointnya[id];
            top = id;
        }

        cout << top << " " << highscore << endl;
    }
}