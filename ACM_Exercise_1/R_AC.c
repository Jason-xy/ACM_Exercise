#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(void)
{
    int i,t,n,cnt;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int *a,*b;
        a = (int *)malloc(sizeof(int) * n);
        b = (int *)malloc(sizeof(int) * n - 1);
        for(i = 0;i < n - 1; i++)
            b[i] = i + 1;
        for(i = 0;i < n; i++)
            scanf("%d",&a[i]);
        for(i = 0;i < n - 1; i++)
        {
            int x = abs(a[i] - a[i + 1]);
            for(cnt = 0;cnt < n; cnt++)
            {
                if(b[cnt] == x)
                {
                    b[cnt] = 0;
                    break;
                }
            }
        }
        int sum = 0;
        for(i = 0;i < n - 1; i++)
        {
            if(b[i] == 0)
                sum++;
        }
        if(sum == n - 1)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }
    return 0;
} 
