#include<stdio.h>

int main(void)
{
    int n,m,ans;
	while(scanf("%d",&n)!=EOF)
    {
        m=1,ans=1;
        while(m<n)
        {
            m=m*3+1;
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}