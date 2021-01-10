char ** summaryRanges(int* nums, int numsSize, int* returnSize){
    *returnSize=0;
    if(!numsSize)return NULL;

    int min=nums[0],max=nums[0],j=0;
    long temp=nums[0];
    char **ans=(char**)malloc(numsSize*sizeof(char*)+1);
    for(int i=0; i<numsSize; i++){
        if(nums[i]!=temp){
            max=nums[i-1];
            ans[j]=(char*)malloc(25*sizeof(char));
            if(max!=min)
                sprintf(ans[j++],"%d->%d",min,max);
            else
                sprintf(ans[j++],"%d",min);
            min=nums[i];
        }
        if(i<numsSize-1)
        temp=nums[i]+1;
    }
    max=nums[numsSize-1];
    ans[j]=(char*)malloc(25*sizeof(char));
    if(max!=min)
        sprintf(ans[j++],"%d->%d",min,max);
    else
        sprintf(ans[j++],"%d",min);
    *returnSize=j;
    return ans;
}