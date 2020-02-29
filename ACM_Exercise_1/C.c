#include <stdio.h>

int main(void)
{
    int t, n, m, temp, mul;

    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
        scanf("%d%d", &m, &n);
        mul = m * n;
        while(temp = m%n)
        {
            m = n;
            n = temp;
        } 
        printf("%d %d\n", n, mul / n);
    }
    return 0;
}