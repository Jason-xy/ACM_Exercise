#include <stdio.h>
#include <string.h>
int day[2005] = { 0 }, sports[105] = { 0 };
int main(void)
{
    int n, m, q, l, r, ans;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)scanf("%d", &day[i]);
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        ans = 0;
        memset(sports, 0, sizeof(int) * 105);
        scanf("%d%d", &l, &r);
        for (int k = l; k <= r; k++)
        {
            if (sports[day[k]] == 0)
            {
                sports[day[k]] = 1;
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}