/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int ans[1000][3]={0},n=0;
    for(int i=0;i<numsSize;i++){
        for(int j=i+1;j<numsSize;j++){
            for(int k=j+1;k<numsSize;k++){
                if(nums[i]+nums[j]==-nums[k]){
                    ans[n][0]=nums[i];
                    ans[n][1]=nums[j];
                    ans[n][2]=nums[k];
                    n++;
                }
            }
        }
    }
    returnSize=malloc(sizeof(int));
    returnSize[0]=n;
    **returnColumnSizes=malloc(sizeof(int));
    returnColumnSizes[0][0]=n;
    return ans;
}