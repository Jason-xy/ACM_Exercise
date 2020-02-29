#include <stdio.h>
#include <math.h>

int main(void)
{
    int t, n, n_max = 0, n_min = 0;
    double grade[1000] = { 0.0 }, max, min, sum, avr;

    scanf("%d", &t);
    for (int k = 0; k < t; k++)
    {
        max = -1.0, min = 100.0, sum = 0.0, n_max = 0, n_min = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%lf", &grade[i]);
            if (grade[i] >= max)
                max = grade[i];
            else if (grade[i] <= min)
                min = grade[i];

            sum += grade[i];
        }

        for (int i = 0; i < n; i++)
        {
            if (fabs(grade[i] - max) < 0.00001)n_max++;
            if (fabs(grade[i] - min) < 0.00001)n_min++;
        }

        avr = (sum - n_min * min - n_max * max) / ((double)n - (double)n_max - (double)n_min );
        if (k == t - 1)
            printf("%.2lf", avr);
        else
            printf("%.2lf\n", avr);
    }
    return 0;
}