#include <stdio.h>
// int A(int a,int b);
// int C(int a,int b);
int main(void)
{
    int n,m,num1=1,num2=1;
    scanf("%d%d",&n,&m);
    if(m==1)
    printf("0");
    else if(n==2)
    {
        if(m%2)printf("0");
        else printf("1");
    }
    else
    {
    for(int i = 0; i < m-1; i++)num1*=(n-1);
    for(int i = 0; i < m-2; i++)num2*=(n-1);
    printf("%d",num1-num2);
    }
    return 0;
}
// int A(int a,int b)
// {
//     int k = 1;
//     for(int i=0;i<a;i++,b--)
//     k*=b;
//     return k;
// }
// int C(int a,int b)
// {
//     int k,j=1;
//     k=A(a,b);
//     for(int i = 1; i <= a; i++)
//     j*=i;
//     return k/j;
// }