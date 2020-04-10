#include <stdio.h>
#include <math.h>
double f(double a, double b, double n);
int main(void)
{
    double a,b,n,m;
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lf%lf%lf", &a,&b,&m);
        while(m--)
        {
            scanf("%lf",&n);
            if((long long)f(a,b,n)%3==0)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    printf("%lf",f(a,b,m));
}
double f(double a, double b, double n)
{
    double A,B;
    A=(3*a)/(2*pow(5,0.5))-b/(2*pow(5,0.5))-a/2+b/2;
    B=(3*a)/(2*pow(5,0.5))-b/(2*pow(5,0.5))+a/2-b/2;
    return A*pow((1+pow(5,0.5))/2,n)-B*pow((1-pow(5,0.5))/2,n);
}