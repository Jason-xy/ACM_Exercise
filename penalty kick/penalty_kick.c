#include <stdio.h>
#include <stdlib.h>

char find_no(char* str);//寻找‘ no’

int main(void)
{
    char* note[18] = { NULL };//储存最多18行信息
    int n, k, score;//点球数/循环变量/最终得分
    char team_1[9] = { 0 }, team_2[9] = { 0 };//分别存储两球队队员进球情况

    while (1)
    {
        scanf("%d", &n);
        if (n <= 0)break;//输入0退出
        getchar();//吃掉0后回车

        for (k = 0; k < n; k++)//读入进球情况数据
        {
            note[k] = (char*)malloc(110 * sizeof(char));
            fgets(note[k], 110, stdin);
        }

        for (k = 0; k < ((n + 1) / 2); k++)//打印表格
            printf("%d ", k + 1);
        printf("Score\n");

        score = 0;//球队一进球情况统计
        for (k = 0; k < n ; k = k + 2)//偶数下标为第一组
        {
            team_1[k / 2 + 1] = find_no(note[k]);//team数组的下标没啥意义不用管
            if (team_1[k / 2 + 1] == 'O')score++;
            printf("%c ", team_1[k / 2 + 1]);
        }
        printf("%d\n", score);

        score = 0;//球队二
        for (k = 1; k < n+1 ; k = k + 2)//奇数下标为第二组
        {

            if (k >= n)//判断第二组是否踢了最后一球
                printf("- ");
            else
            {
                team_2[k / 2 + 1] = find_no(note[k]);//team数组的下标没啥意义不用管
                if (team_2[k / 2 + 1] == 'O')score++;
                printf("%c ", team_2[k / 2 + 1]);
            }
        }
        printf("%d\n", score);
        for (k = 0; k < n; k++) 
        {
            free(note[k]);
        }
    }
    return 0;
}

char find_no(char* str)
{

    int i ;
    for(i=0;str[i]!='\0';i++);
    if(i > 9 && str[i-7] == 'o' && str[i-8] == 'n' && str[i-9] == ' ') return 'X';
    return 'O';
}