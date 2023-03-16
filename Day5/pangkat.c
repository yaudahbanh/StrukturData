#include <stdio.h>

void pangkat(int a, int b)
{

    int hasil = 1;

    for (int i = 0; i < b; i++)
    {
        hasil *= a;
    }

    printf("Hasil akhir : %d\n", hasil);
}

int main()
{

    int a, b;

    printf("Masukan bilangan : ");
    scanf("%d", &a);
    printf("Masukan pangkat : ");
    scanf("%d", &b);

    pangkat(a, b);
}