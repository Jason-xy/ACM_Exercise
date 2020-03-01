#include <stdio.h>
#include <stdlib.h>

int compare(char* str1, char* str2);

int main(void)
{
    int t, status;
    char* str1, * str2;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        str1 = (char*)malloc(110 * sizeof(char));
        str2 = (char*)malloc(110 * sizeof(char));
        scanf("%s", str1);
        scanf("%s", str2);
        status = compare(str1, str2);
        if (status == 1)
            printf("Yes\n");
        else
            printf("No\n");
        free(str1);
        free(str2);
    }
    return 0;
}

int compare(char* str1, char* str2)
{
    int a[10] = { 0 };
    char* p1 = str1, * p2 = str2;
    while (*p1)
    {
        if (*p1 == '1')a[0]++;
        else if (*p1 == '2')a[1]++;
        else if (*p1 == '3')a[2]++;
        else if (*p1 == '4')a[3]++;
        else if (*p1 == '5')a[4]++;
        else if (*p1 == '6')a[5]++;
        else if (*p1 == '7')a[6]++;
        else if (*p1 == '8')a[7]++;
        else if (*p1 == '9')a[8]++;
        p1++;
    }
    while (*p2)
    {
        if (*p2 == '1')a[0]--;
        else if (*p2 == '2')a[1]--;
        else if (*p2 == '3')a[2]--;
        else if (*p2 == '4')a[3]--;
        else if (*p2 == '5')a[4]--;
        else if (*p2 == '6')a[5]--;
        else if (*p2 == '7')a[6]--;
        else if (*p2 == '8')a[7]--;
        else if (*p2 == '9')a[8]--;
        p2++;
    }

    if (a[0] == 0 && a[1] == 0 && a[2] == 0 && \
        a[3] == 0 && a[4] == 0 && a[5] == 0 && \
        a[6] == 0 && a[7] == 0 && a[8] == 0)
        return 1;
    else
        return 0;
}