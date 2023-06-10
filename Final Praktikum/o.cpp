#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;

    int mapnya[110][110];
    memset(mapnya, 0, sizeof(mapnya));

    for (int pale = 0; pale < t; pale++)
    {
        int a, b;
        cin >> a >> b;

        mapnya[a][b] = 1;

        for (int j = 1; j <= 3; j++)
        {
            for (int i = 0; i <= j; i++)
            {
                if (mapnya[a - j + i][b - i] == 0)
                    mapnya[a - j + i][b - i] = j + 1;
                else
                    mapnya[a - j + i][b - i] = min(mapnya[a - j + i][b - i], j + 1);

                if (mapnya[a - j + i][b + i] == 0)
                    mapnya[a - j + i][b + i] = j + 1;
                else
                    mapnya[a - j + i][b + i] = min(mapnya[a - j + i][b + i], j + 1);
            }

            for (int i = j; i >= 0; i--)
            {
                if (mapnya[a + j - i][b - i] == 0)
                    mapnya[a + j - i][b - i] = j + 1;
                else
                    mapnya[a + j - i][b - i] = min(mapnya[a + j - i][b - i], j + 1);

                if (mapnya[a + j - i][b + i] == 0)
                    mapnya[a + j - i][b + i] = j + 1;
                else
                    mapnya[a + j - i][b + i] = min(mapnya[a + j - i][b + i], j + 1);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d ", mapnya[j][i]);
        }
        printf("\n");
    }

    return 0;
}
