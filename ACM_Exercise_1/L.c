#include <stdio.h>

void test(int y, int m, int d);
int leap[12]={31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int common[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main(void)
{
    int t, y, m, d;
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
        scanf("%d%d%d", &y, &m, &d);
        test(y,m,d);
    }
}

void test(int y, int m, int d)
{
    int sum = 0;
    if((y % 4) || ((y % 400) && !(y % 100)))
    {
        for(int i = 0; i < m - 1; i++)
        sum += common[i];
        sum += d;
    }
    else
    {
        for(int i = 0; i < m - 1; i++)
        sum += leap[i];
        sum += d;
    }
    printf("%d\n",sum);
}