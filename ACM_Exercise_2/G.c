#include <stdio.h>
#include <string.h>
int main(void)
{
    int count=0,j=0,l=0;
    char num1[1010]={0},num2[1010];
    scanf("%s",num1);
    count=strlen(num1);
    for(int i = 1; i <= 9; i++)
    {
        for(int k=0;k<count;k++)
        {
            if(num1[k]=i)num2[j++]=num1[k];
        }
    }
    if(strcmp(num1,num2))
    {
        for(l = 0; l < count; l++)
        if(num2[l+1] = num2[count-1])break;
        char temp;
        temp=num2[l];
        num2[l]=num2[l+1];
        num2[l+1]=temp;
    }
    printf("%s",num2);
}