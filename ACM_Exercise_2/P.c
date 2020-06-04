#include <stdio.h>
#include <string.h>
struct ant {
    char name[15];
    int pos;
    char dir;
}ant[105];
int road[1005] = { 0 };
int main(void)
{
    int t, n, l, time, num_on,k=1;
    char temp[15];
    scanf("%d", &t);
    while (t--)
    {
        time = 1;
        memset(road,0,sizeof(int)*1005);
        scanf("%d%d", &n, &l);
        num_on = n;
        for (int i = 0; i < n; i++)
        {
            scanf("%s", ant[i].name);
            scanf("%d", &(ant[i].pos));
            scanf(" %c", &(ant[i].dir));
            getchar();
            road[ant[i].pos] = i;
        }
        printf("Case #%d:\n", k++);
        for (; num_on > 0; time++)
        {
            for (int i = 1; i <= n; i++)
            {
                if (ant[i].pos != 0 && ant[i].pos != l)
                {
                    if (ant[i].dir == 'R')
                    {
                        if (ant[i].pos + 1 < l && road[ant[i].pos + 1] != 0)
                        {
                            strcpy(temp, ant[i].name);
                            strcpy(ant[i].name, ant[road[ant[i].pos + 1]].name);
                            strcpy(ant[road[ant[i].pos + 1]].name, temp);
                        }
                        road[ant[i].pos]=0;
                        ant[i].pos++;
                        road[ant[i].pos]=i;
                        if (ant[i].pos == l)
                        {
                            printf("%d %s\n", time, ant[i].name);
                            num_on--;
                        }
                    }
                    else
                    {
                        if (ant[i].pos - 1 > 0 && road[ant[i].pos - 1] != 0)
                        {
                            strcpy(temp, ant[i].name);
                            strcpy(ant[i].name, ant[road[ant[i].pos - 1]].name);
                            strcpy(ant[road[ant[i].pos - 1]].name, temp);
                        }
                        road[ant[i].pos]=0;
                        ant[i].pos--;
                        road[ant[i].pos] = i;
                        if (ant[i].pos == 0)
                        {
                            printf("%d %s\n", time, ant[i].name);
                            num_on--;
                        }
                    }
                }
            }
        }
    }
    return 0;
}