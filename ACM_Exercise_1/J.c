#include <stdio.h>

int test(int m, int n);
int main(void)
{
    int t, m, n, num;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d%d", &m, &n);
        num = test(m, n);
        printf("%d\n", num);
    }
    return 0;
}int test(int m, int n)
{
    int a[210] = { 0 }, b = 0, l = m;
    while (m)
    {
        for (int i = 0; i < n; i++)
        {
            if (b == l )b = 0;
            //printf("b=%d\n", b);
            if (a[b] == 1) i--;
            if (i + 1 < n)b++;
        }
        a[b] = 1;
        //printf("ban=%d\n", b);
        m--;
    }
    return b + 1;
}