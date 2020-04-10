#include <stdio.h>
#include <math.h>
int main()
{
    int n,m,k;
    long long ans;
	scanf("%d%d%d",&n,&m,&k);
	if(k==-1&&(n+m)%2==1) 
        printf("0");
	else 
		printf("%lld",(long long)pow(2,(float)(m-1)*(float)(n-1)));
	return 0;	
} 