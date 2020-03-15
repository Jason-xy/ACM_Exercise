#include <stdio.h>

int count(char color,char* balls_order,int balls_number);
int compare(char a,char b);

int main(void)
{
    int number = 1,r_number = 0,y_number = 0;
    char balls[15] = {0};

    while (1)
    {
        scanf("%d",&number);
        getchar();
        if(!number)break;
        for(int k = 0;k < number;k++)
        scanf("%c",balls+k);
        r_number = count('R',balls,number);
        y_number = count('Y',balls,number);
        if(r_number < 7 && y_number < 7)
        {
            if(balls[number - 1] == 'B')
                printf("Yellow\n");
            else
                printf("Red\n");
        }
        else
        {
            if(r_number < y_number)
            printf("Yellow\n");
            else if(r_number > y_number)
            printf("Red\n");
            else
            {
                if(balls[number - 1] == 'L')
                printf("Yellow\n");
                else
                printf("Red\n");
            }
        }
        getchar();
    }
    return 0;
}

int count(char color,char* balls_order,int balls_number)
{
    int total = 0;
    for(int k = 0;k < balls_number;k++)
    {
        total += compare(color,balls_order[k]);
    }
    return total;
}

int compare(char a,char b)
{
    if(a == b)
        return 1;
    else
        return 0;
}