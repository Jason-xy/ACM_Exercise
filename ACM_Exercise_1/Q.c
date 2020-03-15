#include <stdio.h>
#include <string.h>

void test(void);
int main(void)
{
    int t;
    scanf("%d", &t);
    getchar();
    for (int i = 0; i < t; i++)
    {
        test();
        printf("\n");
    }
    return 0;
}

void test(void)
{
    char code[30], codeword[1200] = { 0 };
    char word[1000][30] = { 0 };
    int len_code, len_word, flag, i, k = 0, n = 0, l;
    scanf("%s", code);
    getchar();
    len_code = strlen(code);
    scanf("%s", codeword);
    getchar();
    len_word = strlen(codeword);
    k = len_word / len_code;
    for (int j = 65; j <= 122; j++)
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
            if (flag == 1)
                for (int m = 0; m < k; m++)
                {
                    word[m][l] = codeword[n++];
                }
            l++;
            if (flag == 0)break;
        }
    }
    for (i = 0; i < k; i++)
    {
        for (l = 0; l < len_code; l++)
            printf("%c", word[i][l]);
    }
}