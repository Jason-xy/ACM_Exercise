#include <stdio.h>

void test(int n);
int main(void)
{
    int t, n;
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        test(n);
    }
    return 0;
}

void test(int n)
{
    int a[21][21] = {0}, b = 1;
    if(n != 1)
    {
    for(int i = 0; i < (n / 2 + 1); i++)
    {
        for(int j = i; j < n - 1 - i ; j++)
        {
            if(a[n - 1 - i][j] == 0)a[n - 1 - i][j] = b++;
            else break;
        }
        for(int k = n - 1 - i; k > i ; k--)
        {
            if(a[k][n - 1 - i] == 0 )a[k][n - 1 - i] = b++;
            else break;
        }
        for(int l = n - 1 - i; l > i; l--)
        {
            if(a[i][l] == 0)a[i][l] = b++;
            else break;
        }
        for(int m = i; m < n - 1; m++)
        {
            if(a[m][i] == 0)a[m][i] = b++;
            else break;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        printf("%*d", 4, a[j][i]);
        printf("\n");
    }
    }
    else
    {
        printf("%*d\n", 4, 1);
    }
}