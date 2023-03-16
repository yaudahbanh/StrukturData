#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void prima(int n)
{
    bool iniprima[n + 1];
    memset(iniprima, true, sizeof(iniprima));

    for (int p = 2; p * p <= n; p++)
    {

        if (iniprima[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                iniprima[i] = false;
        }
    }

    if (iniprima[n])
        printf("%d adalah bilangan prima", n);
    else
        printf("%d bukan bilangan prima", n);
}

void banner()
{
    int n = 100;

    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
    {

        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    for (int p = 2; p <= n; p++)
    {
        if (prime[p])
            printf("%d ", p);
    }
}

int main()
{
    printf("Berikut adalah contoh bilangan prima dari 1 - 100\n");
    banner();
    puts("");

    int t;
    printf("Check apakah bilangan prima : ");
    scanf("%d", &t);

    prima(t);
}