#include <stdio.h>
char s[100005] = { 0 };
void test(int x, int y, int t, char* s);
int main(void)
{
    int n, x, y, t;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &x, &y, &t);
        getchar();
        scanf("%s", s);
        test(x, y, t, s);
    }
    return 0;
}
void test(int x, int y, int t, char* s)
{
    char *p;
    int mu=0,md=0,ml=0,mr=0,n=0,flag=0;
    if(x>0)mr=x;
    else ml=-x;
    if(y>0)mu=y;
    else md=-y;
    for(;*p!='\0'&&t!=n;p++,n++)
    {
        if(*p=='U'&&mu!=0)mu--;
        else if(*p=='D'&&md!=0)md--;
        else if(*p=='L'&&ml!=0)ml--;
        else if(*p=='R'&&mr!=0)mr--;
        else if(mu==0&&md==0&&ml==0&&mr==0)
        {
            n++;
            flag=1;
            break;
        }
    }
    if(flag==1)printf("%d\n",n);
    else printf("-1\n");
}