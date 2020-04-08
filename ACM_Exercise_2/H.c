#include <stdio.h>
char s[100005] = { 0 };
void test(int x, int y, int t, char* s);
int main(void)
{
    int n, x, y, t;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &x, &y, &t);
        getchar();
        scanf("%s", s);
        test(x, y, t, s);
    }
    return 0;
}
void test(int x, int y, int t, char* s)
{
    char* p = s;
    int m = 0, n = 0, q = 0, flag = 0;
    for (; *p != '\n' && t > q; p++)
    {
        switch (*p)
        {
        case 'U':
            if (y > 0)n++;
            if (m == x && n == y)
                flag = 1;
            break;
        case 'D':
            if (y < 0)n--;
            if (m == x && n == y)
                flag = 1;
            break;
        case 'L':
            if (x < 0)m--;
            if (m == x && n == y)
                flag = 1;
            break;
        case 'R':
            if (x > 0)m++;
            if (m == x && n == y)
                flag = 1;
            break;
        }
        q++;
        if (flag == 1)
        {
            printf("%d\n", q);
            break;
        }
    }
    if (*p == '\n' || t < q)printf("-1\n");
}