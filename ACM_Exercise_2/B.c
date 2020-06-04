#include <stdio.h>
#include <stdlib.h>
void test(void);
int search(char* p, char* key);
int main(void)
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        test();
    }
    return 0;
}
void test(void)
{
    char* p, * key;
    int n, num = 0;
    scanf("%d", &n);
    getchar();
    key = (char*)malloc(sizeof(char) * 25);
    scanf("%s", key);
    getchar();
    for (int i = 0; i < n; i++)
    {
        p = (char*)malloc(sizeof(char) * 110);
        fgets(p, 110, stdin);
        num += search(p, key);
        free(p);
    }
    if (num == 0)printf("Do not find\n\n");
    else printf("%d\n\n", num);
    free(key);
}
int search(char* p, char* key)
{
    char* str1, * str2;
    for (str1 = p; *str1 != '\n'; str1++)9
    {
        str2 = key;
        if ((*(str1 - 1) == ' ' && *str1 == *str2)||(str1==p && *str1==*str2))
            while (*str1 == *str2)
            {
                str1++;
                str2++;
                if (*str2 == '\0' && (*str1 == ' '||*str1 == '\n'))
                    return 1;
            }
    }
    return 0;
}