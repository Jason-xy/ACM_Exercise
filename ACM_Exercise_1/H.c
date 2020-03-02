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
        str = (char*)malloc(1100 * sizeof(char));
        fgets(str, 1100, stdin);
        test(str);
        free(str);
    }
    return 0;
}
void test(char* str)
{
    char* num, * p;
    long sum = 0.0;
    for (p = str; *p != 0; p++)
    {
        if (*p >= 48 && *p <= 57)
        {
            num = (char*)malloc(20 * sizeof(char));
            for (int i = 0; *p >= 48 && *p <= 57; i++)
                *(num + i) = *(p++);
            if(num != "0")
            sum += atol(num);
            free(num);
        }
    }
    printf("%ld\n", sum);
}