#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#define ll long long
#define PI acos(-1)
#define M(n, m) sizeof(n, m, sizeof(n));
const int INF = 2 << 30;
const int maxn = 1e5 + 100;
using namespace std;

char a[maxn][101];
int n;
char str[maxn];

bool Judge(char *a)
{
    int len = strlen(a);
    if (a[len - 8] == ' ' && a[len - 7] == 'n' && a[len - 6] == 'o' && a[len - 5] == ' ')
        return 0;
    return 1;
}

int main()
{
    while(cin >> n && n)
    {
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i ++)
        {
            getchar();
            fgets(a[i],101,stdin);
        }
        for (int i = 1; i <= (n + 1) / 2; i ++)
            cout << i << " ";
        cout << "Score" << endl;
        int sum1, sum2;
        sum1 = sum2 = 0;
        for (int i = 0; i < n; i += 2)
        {
            if (Judge(a[i]))
            {
                printf("O ");
                sum1 += 1;
            }
            else
                printf("X ");
        }
        printf("%d\n", sum1);
        for (int i = 1; i < n;i += 2)
        {
            if (Judge(a[i]))
            {
                printf("O ");
                sum2 += 1;
            }
            else
                printf("X ");
        }
        if (n & 1)
            printf("- ");
        printf("%d\n", sum2);
    }
    return 0;
}