#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int n, times, num[2] = { 0 }, flag, ans[2] = { 0 };
    char *drivers, * p;
    drivers = (char*)malloc(100010 * sizeof(char));
    scanf("%d", &n);
    getchar();
    fgets(drivers, 100020, stdin);
    flag = (int)*drivers - 48;
    p = drivers;
    for (; *p != '\n'; p++)
    {
        if ((int)*p - 48 != flag)num[flag]++;
        flag = !flag;
    }
    if (num[0] >= num[1])ans[0] = num[0];
    else ans[0] = num[1];
    //printf("ans0=%d\n", ans[0]);
    num[0] = num[1] = 0;
    flag = !((int)*drivers - 48);
    p = drivers;
    for (; *p != '\n'; p++)
    {
        if ((int)*p - 48 != flag)num[flag]++;
        flag = !flag;
    }
    if (num[0] >= num[1])ans[1] = num[0];
    else ans[1] = num[1];
    //printf("ans1=%d\n", ans[1]);
    if (ans[1] >= ans[0])printf("%d", ans[0]);
    else printf("%d", ans[1]);
    return 0;
}