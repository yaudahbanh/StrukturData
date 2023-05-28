#include <iostream>
#include <map>
using namespace std;

int main()
{

    int n;
    int k1 = 0, k2 = 0;
    map<string, int> iya;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string kata;
        cin >> kata;
        iya[kata]++;

        if (iya[kata] == 1)
        {
            k1++;
        }
        else if (iya[kata] == 2)
        {
            k2++;
        }

        if (iya[kata] <= 2)
        {
            cout << kata << " masuk Kamus " << iya[kata] << "!" << endl;
        }

        else
        {
            cout << kata << " tidak bisa masuk Kamus!" << endl;
        }
    }
    
    cout << "Kamus 1 berisi " << k1 << " kata" << endl;
    cout << "Kamus 2 berisi " << k2 << " kata" << endl;
}
