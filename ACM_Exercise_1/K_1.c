#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
void test(void)
{
    char* str, * p, *p1;
    str = (char*)malloc(2000 * sizeof(char));
    p1 = (char*)malloc(30 * sizeof(char));
    p = p1;
    fgets(str, 2000, stdin);
    for (p = str; *p != '\n'; p++);
    strcpy(p, " ");
    for (; p + 1 != str; p--)
    {
        for (; *(p - 1) != ' ' && p != str; p--);
        if(p != str)
            printf("%s", p);
        else
        {
            for (p = str; *p != ' '; p++);
            strcpy(p, "\0");
            for (; p != str; p--);
            printf("%s", p);
        }
        strcpy(p, "\0");
    }
    printf("\n");
    free(str);
    ferr(p1);
}