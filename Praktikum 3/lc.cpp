#include <iostream>
#include <map>
using namespace std;

int infokancraft(map<string, int> &pokoknya, map<string, int> &barang, int jumlahbuat)
{
    for (auto i : barang)
    {
        if (pokoknya[i.first] < i.second)
        {
            return 0; // barang tidak bisa dicraft
        }

        else
        {
            jumlahbuat = min(jumlahbuat, pokoknya[i.first] / i.second);
        }
    }

    return jumlahbuat;
}

int main()
{
    map<string, int> pokoknya;
    string kata;

    while (1)
    {
        getline(cin, kata);

        if (kata == "#")
        {
            break;
        }
        pokoknya[kata]++; // untuk menambahkan jumlah bahan
    }

    int t;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        map<string, int> barang;
        int disuruh;
        int jumlahbahan;

        cin >> disuruh;
        cin >> jumlahbahan;

        for (int j = 0; j < jumlahbahan; j++)
        {
            string namapokoknya;
            int jumlahpokoknya;
            cin.ignore(); // error banh
            getline(cin, namapokoknya);
            cin >> jumlahpokoknya;
            barang[namapokoknya] += jumlahpokoknya;
        }

        int jumlahbuat = infokancraft(pokoknya, barang, 2147483647);

        if (jumlahbuat >= disuruh)
        {
            cout << "Material Fulfilled, Crafting " << disuruh << "!" << endl;
            for (auto a : barang)
            {
                pokoknya[a.first] -= a.second * disuruh; // dihapus dari list bahan
            }
        }

        else
        {
            cout << "Insufficient Material, Can only craft " << jumlahbuat << "." << endl; // bahan nya kurang njirs
        }
    }
}