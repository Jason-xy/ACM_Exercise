#include <stdio.h>

int turn(int a);
void test(int n, int k);
int main(void)
{
    int t, k, n;
    scanf("%d",&t);
    for(int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        scanf("%d", &k);
        test(n, k);
    }
    return 0;
}

int turn(int a)
{
    if(a == 0)return 1;
    else return 0;
}

void test(int n, int k)
{
    int a[1100] = {0};
    for(int j = 0; j < k; j++)
        for(int l = 0; l < n; l++)
        if(!((l+1)%(j+1))) a[l] = turn(a [l]);

        for(int l = 0; l < n; l++)
        if(a[l])printf("%d ",l+1);
        printf("\n");
}