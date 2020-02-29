#include <stdio.h>

int main(void)
{
    long ary[3], max, min;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            scanf("%ld", &ary[k]);
        }

        for (int k = 0; k < 3; k++)
        {
            for (int j = 2; j > k; j--)
            {
                if (ary[j] >= ary[j - 1])
                {
                    max = ary[j];
                    min = ary[j - 1];
                }
                else
                {
                    max = ary[j - 1];
                    min = ary[j];
                }
                ary[j] = max, ary[j - 1] = min;
            }
        }

        if (ary[0] != ary[1] && ary[0] != ary[2] && ary[1] != ary[2])
            printf("%ld\n", ary[1]);
        else
            printf("%ld\n", ary[2]);
    }
    return 0;
}