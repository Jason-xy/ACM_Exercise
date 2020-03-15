#include <stdio.h>

int A(int a,int b);
int C(int a,int b);
int main(void)
{
    int n,m;
    scanf("%d%d",&n,&m);


    return 0;
}
int A(int a,int b)
{
    int k = 1;
    for(int i=0;i<a;i++,b--)
    k*=b;
    return k;
}
int C(int a,int b)
{
    int k,j=1;
    k=A(a,b);
    for(int i = 1; i <= a; i++)
    j*=i;
    return k/j;
}