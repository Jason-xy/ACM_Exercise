#include <stdio.h>
int tree[10005]={0};
int main(void)
{
    int l,m,a,b,ans=0;
    scanf("%d%d",&l,&m);
    for(int i = 0; i <= l; i++)tree[i]=1;
    while(m--)
    {
        scanf("%d%d",&a,&b);
        for(int i = a;i <= b; i++)tree[i]=0;
    }
    for(int i=0; i <= l; i++)ans+=tree[i];
    printf("%d",ans);
    return 0;
}