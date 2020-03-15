#include <stdio.h>
#include <math.h>
void test(void);
int main(void)
{
    int t;
    scanf("%d", &t);
    getchar();
    for(int i = 0; i < t; i++)
    {
        test();
    }
    return 0;
}
void test(void)
{
    int h,m,n;
    scanf("%d:%d",&h,&m);
    if(h>=12)h-=12;
    if(m%2==0)
    {
        n=(int)abs(30*h+m/2-6*m);
        if(n>180)n=360-n;
        printf("%d\n",n);
    }
    else
    {
        n=(int)abs(60*h-11*m);
        if(n>360)n=720-n;
        printf("%d/%d\n",n,2);
    }
}