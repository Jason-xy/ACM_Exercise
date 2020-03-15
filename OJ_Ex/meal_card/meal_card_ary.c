#include <stdio.h>

int main(void)
{
    int n, m, money, a[1005], temp1 = 50, temp2, b, sum = 0;
    while (1)
    {
        scanf("%d", &n);
        if(!n)break;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            //printf("%d",a[i]);
        }
        getchar();
        for(int i = 0; i < n; i++)
        {
            for(int k = i,temp2 = 60; k < n ; k++)
            {
                if(a[k] < temp2) b = k, temp2 = a[k];
               //printf("test%d\n",a[b]);
            }
            temp1 = a[i];
            a[i] = a[b];
            a[b] = temp1;
            //printf("%d\n",a[i]);
        }
         scanf("%d", &money);
         getchar();
        for(int i = 0; i < n; i++)
        {
            if(money - sum - a[i] < 5 && money - sum >= 5)
            {
                sum += a[n-1];
                printf("%d\n",money - sum);
            }
            sum += a[i];
        }
    }
    return 0;
}