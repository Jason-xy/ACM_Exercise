#include <stdio.h>
#include <string.h>
#define N 1000000
int a[N];
int main(void)
{  
    int i,j,n,m,t; 
    while(scanf("%d%d",&n,&m)==2)
    {  
        memset(a,0,N*sizeof(int));
        for(i=0;i<n;i++)
        {
            scanf("%d",&t);
            a[t+N/2]++;
        }
        for(t=0,i=N-1;t<m && i>=0;)
        {  
            if(a[i]>0)
            {  
                printf("%d ",i-N/2);
                t++;
                if(--a[i]==0)i--;
            }
            else i--;
        }
        printf("\n");
    }
    return 0;
}
