#include <stdio.h>

void test(void);
int main(void)
{
    int t;
    scanf("%d", &t);
    getchar();
    for (int i = 0; i < t; i++)
    {
        test();
    }
    return 0;
}
void test()
{
    char a[1100][25] = { 0 };
    char b;
    int i = 0, flag;
    while(1)
    {
        scanf("%s",a[i++]);
        flag = scanf("%c", &b);
        if(flag == -1 || b == '\n') break;
    }
    for(i = i - 1; i > 0; i--)
    {
    printf("%s ", a[i]);
    }
    printf("%s\n", a[0]);
}