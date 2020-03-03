#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test(char* str);
int main(void)
{
    int t;
    char* str;
    scanf("%d", &t);
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
    int flag, i, len;
    char* p;
    len = strlen(str);
    if (len < 4)printf("%s\n", str);
    else
    {
        for (i = 0, p = str; i < 5; p++, i++)
        {
            if (*p == ',')
            {
                flag = 1;
                break;
            }
            else
                flag = 0;
        }
        if (flag)
        {
            for (p = str; *p != '\0'; p++)
                if(*p != ',')
                printf("%c", *p);
            printf("\n");
        }
        else
        {
            p = str;
            if (len % 3)
            {
                for (int k = 0; k < (len % 3); k++, p++)
                    printf("%c", *p);
            }
            else
                for (int k = 0; k < 3; k++, p++)printf("%c", *p);
            for (; *p != '\0';)
            {
                printf(",");
                for (int k = 0; k < 3 && *p != '\0'; k++, p++)
                    printf("%c", *p);
            }
            printf("\n");
        }
    }
}