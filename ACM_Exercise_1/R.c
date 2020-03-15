#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void test(void);
int main(void)
{
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
        test();
    }
    return 0;
}
void test(void)
{
    int len, k, j;
    int *ary,*min;
    scanf("%d", &len);
    ary = malloc(sizeof(int) * (len + 10));
    min = malloc(sizeof(int) * (len + 10));
    scanf("%d", ary);
    for(int i = 1; i < len; i++)
    {
        scanf("%d",ary + i);
        k = abs(*(ary + i) - *(ary + i - 1));
        printf("k=%d\n",k);
        *(min + k) = 1;
    }
    for(int i = 1; i < len ; i++)
    {
    j *= *(min + i);
    printf("j=%d\n");
    }
    if(j == 1)printf("Jolly\n");
    else printf("Not jolly\n");
    free(ary);
    free(min);
}