//不会了 emmmm 预习下图解钩....

#include <stdio.h>

struct 
{
    int *cross_a;
    int *cross_b;
    int time;
}road[10005];
int cross[105];

int main()
{
    int n,m,a,b;
    for(scanf("%d%d",&n,&m);n!=0&&m!=0;)
    {
        getchar();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&(road[i].time));
            road[i].cross_a=cross+a;
            road[i].cross_b=cross+b;
            //sovle();
        }
    }
    return 0;
}