#include <stdio.h>

void faktor(int n)
{

    int temp = 1;

    while (n != 1)

    {
        temp *= n;
        n -= 1;
    }

    printf("Hasil faktorial adalah %d\n", temp);
}

int main()
{

    int n;

    printf("Masukan bilangan : ");
    scanf("%d", &n);

    faktor(n);
}