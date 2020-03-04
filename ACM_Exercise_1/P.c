#include <stdio.h>
#include <string.h>

int main(void)
{
    char code[30];
    char word[1000][30] = { 0 };
    int len_code, flag, i, k = 0, l, flag2 = 0;
    scanf("%s", code);
    getchar();
    len_code = strlen(code);
    while (1)
    {
        for (i = 0; i < len_code; i++)
        {
            word[k][i] = getchar();
            if (word[k][i] == ' ')word[k][i] = getchar();
            if (word[k][i] > 90) word[k][i] = word[k][i] - 32;
            if (word[k][i] == '\n')
            {
                for (; i < len_code; i++)
                    word[k][i] = 'E';
                flag2 = 1;
                break;
            }
        }
        k++;
        if (flag2 == 1)break;
    }
    for (int j = 65; j <= 90; j++)
    {
        l = 0;
        while (1)
        {
            flag = 0;
            for (; l < len_code; l++)
            {
                if (code[l] == (char)j)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
            for (int m = 0; m < k; m++)
                printf("%c", word[m][l]);
            l++;
            if (flag == 0)break;
        }
    }
}