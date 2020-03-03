#include <stdio.h>
#include <stdlib.h>

void test(char* str);
int main(void)
{
    int t;
    char* str;
    scanf("%d", &t);
    getchar();
    for (int i = 0; i < t; i++)
    {
        str = (char*)malloc(300 * sizeof(char));
        scanf("%s", str);
        test(str);
        free(str);
    }
    return 0;
}
void test(char* str)
{
    char* p = str;
    int sum = 0;
    for (; *p != '\0'; p++)
        sum += *p - 48;
    if (sum % 3)printf("No ");
    else printf("Yes ");

    p = str;
    sum = 0;
    for (int i = 0; *p != '\0'; p++, i++)
        if (i % 2)sum += *p - 48;
        else sum -= *p - 48;
    if (sum % 11)printf("No\n");
    else printf("Yes\n");
}