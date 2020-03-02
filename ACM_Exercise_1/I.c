#include <stdio.h>

void test(int n);
int main(void)
{
    int t, n;
    scanf("%d", &t);
    getchar();
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        getchar();
        test(n);
    }
    return 0;
}
void test(int n)
{
    char a[100][100] = { 0 }, b[100][100] = { 0 };
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
            scanf("%c", &a[i][k]);
        getchar();
    }
    if (n != 1)
    {
        n = n - 1;
        for (int i = 0; i < ((n + 1) / 2 + 2); i++)
        {
            for (int j = i; j < n; j++)
            {
                if (b[j][n - i] == 0)b[j][n - i] = a[i][j];
                if (b[n - i][n - j] == 0)b[n - i][n - j] = a[j][n - i];
                if (b[n - j][i] == 0)b[n - j][i] = a[n - i][n - j];
                if (b[i][j] == 0)b[i][j] = a[n - j][i];
            }
        }
        n = n + 1;
        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k < n; k++)
                printf("%c", b[i][k]);
            printf("\n");
        }
    }
    else
    {
        printf("%c\n", a[0][0]);
    }
    printf("\n");
}