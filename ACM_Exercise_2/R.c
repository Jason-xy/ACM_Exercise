#include<stdio.h>  
#include <string.h>

int a[100001],b[100001];
int main(void)
{ 
    int n,m,i,j; 
    memset(b,0,10001*sizeof(int));
    scanf("%d%d",&n,&m); 
    for (i=1;i<=n;i++)
    { 
        scanf("%d",&a[i]); 
        b[a[i]]++;
    } 
    for (i=99999;i>=1;i--) 
        b[i]+=b[i+1];
    for (i=1;i<=m;i++)
    { 
        scanf("%d",&j); 
        printf("%d\n",b[j]);
    }    
} 
