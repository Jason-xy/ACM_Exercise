#include <stdio.h>
#include <stdlib.h>

void test(char* str);
int main(void)
{
    int t;
    char* str;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        str = (char*)malloc(2000 * sizeof(char));
        scanf("%s", str);
        getchar();
        test(str);
        free(str);
    }
    return 0;
}
void test(char* str)
{
    char* p = str;
    int a = 0;
    for (; *(p + 1) != ')'&& *(p + 1) != '\0'; p++)
        if (*p == '(') a++;
    for (; *p != '\0'; p++)
    {
        if (*p == '(') a++;
        if (*p == ')') a--;
        if (a < 0)
        {
            printf("No\n");
            break;
        }
    }
    if (a > 0)printf("No\n");
    else if (a == 0)printf("Yes\n");
}