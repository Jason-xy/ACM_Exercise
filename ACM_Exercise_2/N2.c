#include <stdio.h>
#define N 100

double f(double a,double b,double n){
	if(n==0) return a;
	if(n==1) return b;
	else return f(a,b,n-1)+f(a,b,n-2);
}

int main(){
	int times;
	scanf("%d", &times);
	while(times--)
    {
		double a,b,m,n;
		scanf("%lf%lf%lf",&a,&b,&m);
		int t;
		if((long)a%3==0&&(long)b%3==0)
        {
			while(m--){
				scanf("%lf",&n);
				printf("Yes\n");				
			}
		}
        else
        {
			for(int i=0;i<N;i++)
            {
			    if((long)f(a,b,i)%3==0)
                {
				    t=i;
				    break;	
				}	
			}
			while(m--){
			scanf("%d",n);
			if((long)(n-t)%4==0) printf("Yes\n");
			else printf("No\n"); 				
			}
		}
	}
	return 0;
}