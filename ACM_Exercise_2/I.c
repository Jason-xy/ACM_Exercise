#include <stdio.h>

void test(int n,int k);
int main(void)
{
    int t,n,k;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d%d",&n,&k);
        test(n,k);
    }
    return 0;
}
void test(int n,int k)
{
    int ans;
    if(n == 1||k==0 ||(n==2&&k==0) || (n!=2&&k==1)) ans = 0;
        else 
        {
            if(k > n-1) ans = n*(n-1)/2;
            else ans = n*k/2;
        }
        printf("%d\n",ans);
}