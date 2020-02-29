#include <stdio.h>

int main(void)
{
    int t, n, n_max = 1, n_min = 1;
    double grade[1000] = { 0.0 }, max , min , sum, avr;

    scanf("%d",&t);
    for(int k = 0; k < t; k++)
    {
        max = -1.0, min = 100.0, sum = 0.0;
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
        {
            scanf("%lf",&grade[i]);
            if(grade[i] >= max)
            max = grade[i];
            else if(grade[i] <= min)
            min = grade[i];

            sum += grade[i];
        }
        avr =  (sum - min - max)/(n - 2);
        if(k == t - 1)
        printf("%.2lf",avr);
        else
        printf("%.2lf\n", avr);
    }
    return 0;
}