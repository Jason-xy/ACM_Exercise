#include <stdio.h>

int main(void)
{
    int t;
    long a, b, c, d, up = 0, down = 0, up_b, down_b, divisor, temp;
    char sign;
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
        scanf("%ld%ld%ld%ld %c", &a, &b, &c, &d, &sign);
        getchar();
        if(b != 0 && d != 0)
        {
            switch(sign)
            {
                case '+' :
                {
                    up = a * d + b * c;
                    down = b * d;
                }
                break;
                case '-': 
               {
                    up = a * d - b * c;
                    down = b * d;
                }
                break;
                case '*':
                {
                    up = a * c;
                    down = b * d;
                }
                break;
                case '/':
                {
                    up = a * d;
                    down = b * c;
                }
                break;
            }
        }
        // printf("%ld\n",up);
        // printf("%ld\n",down);
        up_b = up;
        down_b = down;
        if(down != 0)
        {
            while(temp = up_b % down_b)
            {
                up_b = down_b;
                down_b = temp;
            }
            divisor = down_b;
            up /= divisor;
            down /= divisor;

            if(down < 0 && up > 0)
            {
                up = 0 - up;
                down = 0 - down;
            }
            else if(down < 0 && up < 0)
            {
                up = 0 - up;
                down = 0 - down;
            }

            if(down == 1)
            printf("%ld/%ld%c%ld/%ld=%d\n", a, b, sign, c, d, up);
            else
            printf("%ld/%ld%c%ld/%ld=%d/%d\n", a, b, sign, c, d, up, down);
        }
        else
        printf("Error\n");
    }
    return 0;
}