#include <stdio.h>

int main(void) 
{
    int n, m;
    scanf("%d%d", &n, &m);
    int ans = 1;
    for (int i = 1; i <= m; ++i)ans *= n - 1;
    if (m % 2)ans = (ans - n + 1) / n;
    else ans = (ans + n - 1) / n;
    printf("%d", ans);
}